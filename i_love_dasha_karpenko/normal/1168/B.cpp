#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;
#define pb push_back;
#define po(x) 1<<x
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
typedef long double ld;
#define DIM 300007
#define DIM2 10007
#define MODULO 998244353
const ll mask = po(9)-1;
struct pp {
	ll fi, sc;
	bool operator < (const pp b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
string s;

int main() {
	schnell;
	cin >> s;
	ll n = s.length(),last = n,res = 0;
	for (ll i = n - 1; i >= 0; i--) {
		ll cur = last;
		for (ll k = 1; i+k*2<cur; k++) {
			if (s[i] == s[i + k] && s[i] == s[i + k * 2]) {
				cur = i + k * 2;
				break;
			}
		}
		res += n - cur;
		last = cur;
	}
	cout << res << endl;
}