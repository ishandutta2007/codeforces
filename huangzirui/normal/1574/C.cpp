#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,T;ll a[maxn],Sum;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)a[i]=read(),Sum+=a[i];
	sort(a+1,a+1+n);
	cin>>m;
	for(i=1;i<=m;i++){
		ll F=read(),A=read(),ans=2e18;
		int id=lower_bound(a+1,a+1+n,F)-a;
		if(id<=n){
			ll W=Sum-a[id];
			if(W>=A)ans=0;
			else ans=min(ans,A-W);
		}
		if(id!=1){
			ll W=Sum-a[id-1];
			if(W>=A)ans=min(ans,F-a[id-1]);
			else ans=min(ans,A-W)+F-a[id-1];
		}printf("%lld\n",ans);
	}
	return 0;
}