#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1000;

vector<ll> f,w;

struct triple {
	ll first,second,third;
	triple(ll a=0,ll b=0, ll c=0):first(a),second(b),third(c){}
};

typedef vector<triple> vt;
vt a,b,x;
int n;
ll k;

void mul1()
{
	for(int i=0;i<n;i++){
		ll q = a[i].first;
		a[i].first = b[q].first;
		a[i].second += b[q].second;
		a[i].third = min(a[i].third,b[q].third);
	}
}

void bin(ll p, void (*func)()){
	if(p==1){
		return;
	}
	bin(p/2,func);
	b = a;
	func();
	if(p%2){
		b = x;
		func();
	}

}

int main()
{
	cin >> n >> k;
	f.resize(n);
	w.resize(n);
	x.resize(n);
	for(int i=0;i<n;i++){
		cin >> f[i];
		x[i].first = f[i];
	}
	for(int i=0;i<n;i++){
		cin >> w[i];
		x[i].second = w[i];
		x[i].third = w[i];
	}
	a = x;
	bin(k,mul1);
	for(int i=0;i<n;i++){
		cout << a[i].second << " " << a[i].third << "\n";
	}
}