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

vector<string> a;

bool isWin(int l, int r, int len) {
	while((l < r) && (a[l].size() == len))
		++l;
	if (l == r)
		return false;
	for (int i = 0; i < 26; ++i) {
		int pr = l;
		while(((l < r) && (a[l][len] == 'a' + i)))
			++l;
		if (l == pr)
			continue;
		if (!isWin(pr, l, len + 1))
			return true;
	}
	return false;
}

bool isLose(int l, int r, int len) {
	while((l < r) && (a[l].size() == len))
		++l;
	if (l == r)
		return true;
	for (int i = 0; i < 26; ++i) {
		int pr = l;
		while(((l < r) && (a[l][len] == 'a' + i)))
			++l;
		if (l == pr)
			continue;
		if (!isLose(pr, l, len + 1))
			return true;
	}
	return false;
}

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//clock_t startTime = clock();
	int n, k;
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	bool win = isWin(0, n, 0);
	bool lose = isLose(0, n, 0);
	if (!win)
		cout << "Second\n";
	else {
		if (lose) {
			cout << "First\n";
		}
		else {
			if (k & 1) {
				cout << "First\n";
			}
			else
				cout << "Second\n";
		}
	}
	//cerr << "Time elapsed = " << (clock() - startTime) * 1.0 / CLOCKS_PER_SEC << endl;
    return 0;
}