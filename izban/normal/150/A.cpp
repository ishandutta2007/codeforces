#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long 


ll n;
string s;

vector <ll> v,p;
map <ll,bool> mp,win,f;
map <ll,ll> prev1;
queue <ll> q;

bool pr(ll x) {
	for (int i=2; i<=(int)sqrt(x*1.0); i++) 
		if (!(x%i)) return false;
	return true;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=2; i<=(int)sqrt(n*1.0); i++) if (n%i==0) {
		if (pr(i)) v.push_back(i);
		if (pr(n/i)) v.push_back(n/i);
	}
	sort(v.begin(),v.end());

	bool f1=false; ll ans=0;
	f1=pr(n);
	for (int i=0; i<v.size(); i++) {
		if (f1) break;
		for (int j=i; j<v.size(); j++) {
			ll k=v[i]*v[j];
			if (n%k==0 && k!=n) {
				f1=true;
				ans=k;
				break;
			}
		}
	}

	if (!f1) cout << 2;
	else {
		cout << 1 << endl;
		cout << ans;
	}
	return 0;
}