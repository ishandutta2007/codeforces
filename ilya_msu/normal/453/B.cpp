#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std;  
 
typedef long long ll; 
typedef unsigned long long ull; 

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 10;
const ll LLINF = (ll)4 * 1000 * 1000 * 1000 * 1000 * 1000 * 10;
const int N = 53;
const int mod = 1000 * 1000 * 1000 + 9;

vector<vector<int> > table(N + 1, vector<int>(N + 1));
vector<vector<int> > s(1);
vector<int> sum;
vector<int> prime(1001);

bool isPrime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0)
			return false;
	}
	return true;
}

//void init() {
//	vector<int> pr;
//	int x = N + 1;
//	while(pr.size() < 100) {
//		if (isPrime(x)) 
//			pr.push_back(x);
//		++x;
//	}
//	sum.assign(101, 0);
//	for (int i = 1; i < 101; ++i)
//		sum[i] = sum[i - 1] + pr[i - 1];
//	prime.assign(1001, 0);
//	for (int i = 2; i < prime.size(); ++i)
//		prime[i] = isPrime(i);
//}

void gen(int n) {
	if (n == N + 1)
		return;
	int sz = s.size();
	for (int i = 0; i < sz; ++i) {
		vector<int> a = s[i];
		bool ok = true;
		for (int j = 0; j < a.size(); ++j) {
			if (table[a[j]][n] != 1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			a.push_back(n);
			s.push_back(a);
		}
	}
	gen(n + 1);	
}


int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int solve(const vector<int>& a, const vector<int>& b) {
	int n = a.size();
	if (b.size() > n)
		return INF;
	int res = 0;
	for (int i = 0; i < n - b.size(); ++i)
		res += a[i] - 1;
	for (int i = 0; i < b.size(); ++i) {
		res += abs(a[i + n - b.size()] - b[i]);
	}
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//init();
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pii> aa(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		aa[i] = pii(a[i], i);
	}
	sort(a.begin(), a.end());
	sort(aa.begin(), aa.end());
	//reverse(a.begin(), a.end());
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			table[i][j] = gcd(i, j);
	gen(2);
	//cout << s.size() << endl;
	int res = INF;
	int ans = -1;
	for (int i = 0; i < s.size(); ++i) {
		//cerr << i << endl;
		int cur = solve(a, s[i]);
		if (cur < res) {
			res = cur;
			ans = i;
		}
	}
	//cout << res << endl;
	vector<int> res1;
	for (int i = 0; i < n - s[ans].size(); ++i)
		res1.push_back(1);
	for (int i = 0; i < s[ans].size(); ++i)
		res1.push_back(s[ans][i]);
	vector<int> res2(n);
	for (int i = 0; i < n; ++i)
		res2[aa[i].second] = res1[i];
	for (int i = 0; i < n; ++i)
		cout << res2[i] << " ";
	cout << endl;

    return 0;
}