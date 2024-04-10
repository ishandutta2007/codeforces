#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline bool smin(int&x,const int&y){return x>y?x=y,1:0;}
inline bool smax(int&x,const int&y){return x<y?x=y,1:0;}
int calc(ll x){
	int c=0;while(x)c+=x%10,x/=10;return c;
}
inline ll fpow(ll x,int k){
	ll ans=1;for(;k;k>>=1,x=x*x)if(k&1)ans*=x;return ans;
}
int main(){
	ll n,m;cin>>n;
	if(n<10)return cout<<n,0;
	int t=log10(n);
	m=n%fpow(10,t);
	cout<<calc(m+1)+calc(n-m-1);
	return 0;
}