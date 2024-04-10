#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int mo=998244353,mo2=1e9+7;
const int N=3e5+5,M=5005,G=505;
int q,n;
int p[N],t[N],st[N],en[N];
int ans;
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&q);
	for(;q--;){
		scanf("%d",&n);
		fo(i,1,n)t[i]=0,st[i]=n+1,en[i]=0;
		fo(i,1,n)scanf("%d",&p[i]),t[p[i]]=1;
		fo(i,1,n)t[i]+=t[i-1];
		fo(i,1,n)p[i]=t[p[i]],st[p[i]]=min(st[p[i]],i),en[p[i]]=i;
		n=t[n];
		int ss=0;ans=0;
		fo(i,1,n){
			if(en[i-1]<st[i]){
				++ss;
				ans=max(ans,ss);
			}else{
				ss=1;
			}
		}
		printf("%d\n",n-ans);
	}
}