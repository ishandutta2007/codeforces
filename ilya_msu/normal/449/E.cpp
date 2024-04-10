#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>



 
using namespace std; 
 
typedef long long ll; 
typedef long double ld;
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000000 + 1;

vector<int> phi;
vector<int> grPrDiv;
vector<ll> sumGcd;
vector<ll> f;
vector<ll> s0, s1, s2;

void countPhiAndGrPrDiv() {
	phi.resize(N);
	for (int i = 1; i < N; ++i)
		phi[i] = i;
	grPrDiv.assign(N, 1);
	for (int i = 2; i < N; ++i) {
		if (phi[i] == i) {
			for (int j = i; j < N; j += i) {
				phi[j] = phi[j] / i * (i - 1);
				grPrDiv[j] = i;
			}
		}
	}
}

void getDiv(int n, vector<int>& div) {
	if (n == 1) {
		div.assign(1, 1);
		return;
	}
	int d = grPrDiv[n];
	int c = 0;
	while(n % d == 0) {
		n /= d;
		++c;
	}
	getDiv(n, div);
	int sz = div.size();
	div.resize(sz * (c + 1));
	for (int i = 1; i <= c; ++i) {
		for (int j = 0; j < sz; ++j) {
			div[i * sz + j] = div[(i - 1) * sz + j] * d;
		}
	}
}

void countSumGcd() {
	sumGcd.assign(N, 0);
	for (int i = 1; i < N; ++i) {
		vector<int> div;
		getDiv(i, div);
		for (int j = 0; j < div.size(); ++j)
			sumGcd[i] += div[j] * phi[i / div[j]];
	}
}

void countF() {
	f.assign(N, 0);
	for (ll i = 1; i < N; ++i) {
		f[i] = (i * (i + 1) * (2 * i + 1) / 3 + i * i * i - i * i * (i + 1) - 2 * i * i + 2 * sumGcd[i]) % mod;
	}
}

void countPrefSums() {
	s0.assign(N, 0);
	s1.assign(N, 0);
	s2.assign(N, 0);
	for (int i = 1; i < N; ++i) {
		s0[i] = (s0[i - 1] + f[i]) % mod;
		s1[i] = (s1[i - 1] + f[i] * i) % mod;
		s2[i] = (s2[i - 1] + ((f[i] * i) % mod) * i) % mod;
	}
}

void precalc() {
	countPhiAndGrPrDiv();
	countSumGcd();
	countF();
	countPrefSums();
	
}

ll solve(ll n, ll m) {
	if (n > m)
		swap(n, m);
	return ((((n + 1) * (m + 1)) % mod) * s0[n] + s2[n] + (mod - (m + n + 2)) * s1[n]) % mod;

}


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	
	
	
	precalc();
	int t;
	cin >> t;
	for (int tt = 0; tt < t; ++tt) {
		int n, m;
		cin >> n >> m;
		cout << solve(n, m) << "\n";
	}
	return 0;
}