//https://codeforces.com/contest/1268/problem/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}

const int N=200005;
struct node{
	int c;ll s;
}tre[N<<2];
int a[N];
#define mid ((l+r)>>1)
#define ls o<<1  ,l,mid
#define rs o<<1|1,mid+1,r
void add(int o,int l,int r,int v){
	++tre[o].c;
	  tre[o].s+=v;
	if(l==r)return;else
	if(v<=mid)add(ls,v);
	else      add(rs,v);
}
int  que(int o,int l,int r,int v){
	if(l==r)return tre[o].c;else
	if(v<=mid)return   que  (ls,v);else
	return tre[o<<1].c+que  (rs,v);
}
ll query(int o,int l,int r,int v){
	if(l==r)return tre[o].s;else
	if(v<=mid)return   query(ls,v);else
	return tre[o<<1].s+query(rs,v);
}
int kth(int o,int l,int r,int v){
	if(l==r)return l;else
	if(v<=tre[o<<1].c)return kth(ls,v);
	else return kth(rs,v-tre[o<<1].c);
}
int main(){
	int n,i,b,m;ll s=0ll,z,t=0ll,T=0ll;
	scanf("%d",&n);
	for(i=1;i<=n;++i){scanf("%d",&b);a[b]=i;}
	for(i=1;i<=n;++i){
		s+=a[i];
		t+= que(1,1,n,a[i]);
		    add(1,1,n,a[i]);
		b=  kth(1,1,n,m=(i+1)>>1);
		z=query(1,1,n,b);
//		printf("i=%d b=%d s=%lld z=%lld\n",i,b,s,z);
		z=s-(z<<1)-(( ((ll)m)*(m-1) + ((ll)(i-m))*(i-m+1) )>>1);
		if(i&1)z+=b;
		printf("%lld ",z+T-t);
		T+=i;
	}
	return 0;
}