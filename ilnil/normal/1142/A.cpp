#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define db double
using namespace std;
const int N=2e5+5;
ll n,k,a,b;
ll ans,mi,ma,o;
void R(ll &n){
	char c;for(n=0;(c=getchar())<48;);
	for(;c>47;c=getchar())n=n*10+c-48;
}
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
void calc(ll b,ll a){
	b-=a;
	fo(i,0,n){
		if(b>0){
			o=n*k/gcd(n*k,b);
			if(o<0){
				int kk=0;
			}
			mi=min(mi,o);
			ma=max(ma,o);
		}
		b+=k;
	}
}
int main(){
	R(n);R(k);
	R(a);R(b);
	mi=1e18;ma=0;
	calc(b,a);
	calc(k-b,a);
	calc(b,k-a);
	calc(k-b,k-a);
	printf("%I64d %I64d",mi,ma);
}