#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 
#define mp make_pair 
#define ll long long

using namespace std;
const long long mod = 1000000007;

ll k,p,a[333333];
int n;


ll Pow(ll a,ll b,ll c) {
	ll x = 1;
	while(b > 0) {
		if(b&1) x = x*a%c;
		a = a*a%c;
		b /= 2;
	}
	return x;
}


int main(){
	cin>>p>>k;
	if(k == 0) {
		cout<<Pow(p,p - 1,mod);
		return 0;
	}
	if(k == 1) {
		cout<<Pow(p,p,mod);
		return 0;
	}

	ll P = p - 1;
	for(ll i = 1;i*i <= P;++i) if(P%i == 0) {
		a[n++] = i;
		if(i*i < P) a[n++] = P/i;
	}
	sort(a,a + n);
	for(int i = 0;i < n;++i) {
		if(Pow(k,a[i],p) == 1) {
			cout<<Pow(p,P/a[i],mod);
			return 0;
		}
	}
	return 0;
}