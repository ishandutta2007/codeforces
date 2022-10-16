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

int T,n,i,x,k,s[N],y,a[N],t1,t2,b[N],c[N],d[N];
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(i=n-k+1;i<=n;++i)cin>>s[i];
		if(k==1){
			cout<<"YES\n";
		}
		else{
			for(i=n-k+2;i<=n;++i)a[i]=s[i]-s[i-1];
			int fl=0;
			for(i=n-k+2;i<n;++i)if(a[i]>a[i+1])fl=1;
			if(fl||s[n-k+1]>1ll*a[n-k+2]*(n-k+1))cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}