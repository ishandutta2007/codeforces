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
#define forn(x) for(ll i = 1;i<=x;i++)
typedef long long ll;
typedef long double ld;
#define DIM 1007
#define DIM2 10007
#define MODULO 1000000007
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
ll n,D[DIM*2][DIM],P[DIM*2],N[DIM*2][DIM],R[DIM*2];
int main() {
	schnell;
	cin >> n;
	D[1][1] = 1;
	R[1] = 1;
	for (ll i = 2; i <= n * 2;i++) {
		if (i == n * 2) {
			R[i] += D[i - 1][1];
			break;
		}
		for (ll j = 0; j <= n && n*2-i>=j ; j++) {
			if (j > 0) {
				D[i][j] += D[i - 1][j - 1];
				N[i - 1][j - 1]++;
				if (N[i - 1][j - 1] == 2)P[i]+=D[i-1][j-1];
				D[i][j] += MODULO;
			}
			D[i][j] += D[i - 1][j + 1];
			D[i][j] %= MODULO;
			N[i - 1][j + 1]++;
			if (N[i - 1][j + 1] == 2)P[i] += D[i - 1][j + 1];
			R[i] += D[i][j];
			R[i] %= MODULO;
			P[i] %= MODULO;
		}
	}
	ll res1 = 0,res2 = 0;
	for (ll i = n * 2; i >= 1; i -= 2) {
		if (R[i] < P[i])R[i] += MODULO;
		res1 += R[i] - P[i];
		res1 %= MODULO;
	}
	
	//for (ll i = 1; i <= n * 2; i++)cout << R[i] << ' ' << P[i] << endl;
	cout << max(res1, res2) % MODULO << endl;
}