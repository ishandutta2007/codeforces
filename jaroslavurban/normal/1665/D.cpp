#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// finds x,y for a*x + b*y = gcd(a,b)
// should work for negative numbers as well
ll gcd(ll a,ll b,ll&x,ll&y){
	if(!b){
		x=1;y=0;
		return a;
	}
	ll x1,y1;
	ll d=gcd(b,a%b,x1,y1);
	// I know: b*x1 + (a%b)*y1 = d
	// want to know: a*? + b*? = d
	// b*x1 + (a-(a/b)*b)*y1 = d
	// b*x1 + a*y1 - (a/b)*b*y1 = d
	// b*(x1-(a/b)*y1) + a*y1 = d
	x=y1;
	y=x1-(a/b)*y1;
	return d;
}


// if you want all solutions, then just add a*(b/g) - b*(a/g) = 0 (lcm)
// so add (b/g) to x and -(a/g) to y
bool solve_diophantine(ll a,ll b,ll c,ll&x,ll&y,ll&g){
	if(!a&&!b){
		x=y=g=0;
		return !c;
	}
	g=gcd(a,b,x,y);
	x*=c/g;
	y*=c/g;
	return !(c%g);
}

void normalize(ll&a,ll&m){a%=m;a=(a+m)%m;}

const int y = 1338557220;

void ProGamerMove() {
	vector<ll> a, m;
	for (int g, x = 1; x <= 30; ++x) {
		cout << "? " << x << " " << x + y << endl;
		cin >> g;
		m.push_back(g);
		a.push_back(((-x % g) + g) % g);
	}
	ll res=a[0];
	ll lcm=m[0];
	// I have res = a[0] % m[0]
	for(int i=1;i<a.size();++i){
		// I have res = a[i] % m[i]
		// want to solve:
		// res + x*lcm = a[i] + y*m[i]
		// lcm*x - m[i]*y = a[i]-res
		ll a1=lcm,b1=-m[i],c1=a[i]-res,x,y,g;
		if(!solve_diophantine(a1,b1,c1,x,y,g)){assert(0);}
		res=a[i]+y*m[i];
		lcm=lcm*(m[i]/__gcd(lcm,m[i]));
		normalize(res,lcm);
	}
	cout << "! " << res << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}