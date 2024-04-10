#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=1e3+5;
int n=10,T;
int f[N];
ll x;
ll F(ll x){
	if(x<=10)return f[x];
	if(x&1)return x-F(x-1);
	ll y=x/2;
	return y&1?x-F(y):x-F(x-1);
}
int main(){
//	freopen("a.out","w",stdout);
	fo(i,1,n)
		if(i&1)f[i]=i-f[i-1];
		else f[i]=max(i-f[i-1],i-f[i/2]);
	ios::sync_with_stdio(0);
	for(cin>>T;T--;){
		cin>>x;
		printf("%lld\n",F(x));
	}
}