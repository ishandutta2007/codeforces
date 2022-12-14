#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long 
struct node{
	ll pos,num;
}t[N];
ll n,k,l,r,c[N],x,ans[N],MI,a[N],mid;
const double X=0.75,Y=sqrt(12);
inline bool check(){
	ll now=0;
	for(int i=1;i<=n;++i){
		if((a[i]-mid-1)>=0){
			now+=min(((ll)(sqrt(X+(a[i]-1-mid))*Y)-3ll)/6,c[i]);
		}
	}
	return now>=k;
}
inline int cmp(node aa,node bb){
	return aa.num<bb.num;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>c[i],a[i]=c[i];
	l=-4e18;r=1e12;
	while(l<r){
		mid=MI=r-(r-l)/2;
		if(check())l=MI;
		else r=MI-1;
	}
	for(int i=1;i<=n;++i){
		if((a[i]-1-l)>=0){
			ans[i]=min(((ll)(sqrt(X+(a[i]-1-l))*Y)-3ll)/6,c[i]);
			k-=ans[i];
//			printf("%lld  ",ans[i]);
		}
	}k=-k;
	for(int i=1;i<=n;++i)
	x=ans[i],t[i].num=x*x*-3-x*3+c[i]-1,t[i].pos=i;
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=k;++i)ans[t[i].pos]--;
	for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);
	return 0;
}
/*
3
2999999969
1000000000
1000000000
1000000000
*/