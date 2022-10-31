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
#define DIM 10007
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
ll resi, resn, rese, rest;
int main() {
	schnell;
	cin >> s;
	for (ll i = 0; i < s.length(); i++) {
		if (s[i] == 'n')resn++;
		if (s[i] == 'e')rese++;
		if (s[i] == 't')rest++;
		if (s[i] == 'i')resi++;
	}
	ll res = 0;
	if (resn >= 3 && rese >= 3 && rest >= 1 && resi >= 1) {
		resn -= 3; rese -= 3; rest--; resi--;
		res++;
		resn /= 2; rese /= 3;
		cout << 1 + min(min(resn, rese), min(resi, rest)) << endl;
	}
	else {
		cout << 0 << endl;
	}
}