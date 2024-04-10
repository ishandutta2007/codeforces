#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define N 1000004
#define ll long long
#define mid (l+r>>1)
#define ls k<<1
#define rs k<<1|1
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define IOS ios::sync_with_stdio(0);

int T,n,i,x,y,a[N],t1,t2,b[N],c[N],d[N];
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n;ll ss=0;t1=t2=0;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i){
			cin>>b[i];
			if(a[i]==0)c[++t1]=b[i];
			if(a[i]==1)d[++t2]=b[i];
			ss+=b[i]<<1;
		}
		sort(c+1,c+t1+1);
		sort(d+1,d+t2+1);c[t1+1]=d[t2+1]=0;
		for(i=1;i<=t1-t2;++i)ss-=c[i];
		for(i=1;i<=t2-t1;++i)ss-=d[i];
		if(t1==t2) ss-=min(c[1],d[1]);
		cout<<ss<<'\n';
	}
}