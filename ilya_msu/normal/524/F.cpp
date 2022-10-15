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
#include<functional>

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
const int N = 1000000;


vector<int> sufAr(const string& s) {
    int n = s.size();
    vector<int> perm(n), cl(n);
    vector<int> count(256, 0);
    for (int i = 0; i < n; ++i)
        count[s[i]]++;
    for (int i = 1; i < 256; ++i)
        count[i] += count[i - 1];
    for (int i = 0; i < n; ++i)
        perm[--count[s[i]]] = i;
    cl[perm[0]] = 0;
    int num = 1;
    for (int i = 1; i < n; ++i) {
        if (s[perm[i]] != s[perm[i - 1]])
            ++num;
        cl[perm[i]] = num - 1;
    }
    vector<int> perm2(n), cl2(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; ++i) {
            perm2[i] = perm[i] - (1 << h);
            if (perm2[i] < 0)
                perm2[i] += n;
        }
        vector<int> end(num, 0);
        for (int i = 0; i < n; ++i) {
            ++end[cl[perm2[i]]];
        }
        for (int i = 1; i < num; ++i)
            end[i] += end[i - 1];
        for (int i = n - 1; i >= 0; --i)
            perm[--end[cl[perm2[i]]]] = perm2[i];
        cl2[perm[0]] = 0;
        num = 1;
        for (int i = 1; i < n; ++i) {
            if ((cl[perm[i]] != cl[perm[i - 1]]) || (cl[(perm[i] + (1 << h)) % n] != cl[(perm[i - 1] + (1 << h)) % n]))
                ++num;
            cl2[perm[i]] = num - 1;
        }
        cl = cl2;
    }
    return perm;
}

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(n);
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(')
			a[i] = 1, ++l;
		else
			a[i] = -1, ++r;
	}
	vector<int> level(n + 1);
	level[0] = 0;
	for (int i = 0; i < n; ++i)
		level[i + 1] = level[i] + a[i];
	vector<int> up(n + 1), down(n + 1);
	up[0] = 0;
	for (int i = 0; i < n; ++i)
		up[i + 1] = min(up[i], level[i]);
	down[n] = level[n];
	for (int i = n - 1; i >= 0; --i)
		down[i] = min(down[i + 1], level[i]);
	vector<int> len(n);
	if (r == 0) {
		for (int i = 0; i < l; ++i)
			s += ')';
		cout << s << endl;
		return;
	}
    if (l == 0) {
        for (int i = 0; i < r; ++i)
            cout << '(';
        cout << s << endl;
        return;

    }
	int id = 0;
	while (a[id] == 1)
		++id;
	len[id] = 0;
	for (int i = id - 1; (i != id) && (i + n != id); --i) {
		if (i == -1)
			i = n - 1;
		if (a[i] == 1) {
			if (i == n - 1)
				len[i] = len[0] + 1;
			else
				len[i] = len[i + 1] + 1;
		}

		else
			len[i] = 0;
	}
    vector<int> ok(n, false);
	int low = max(r - l, 0);
	
	for (int i = 0; i < n; ++i) {
		int curl = level[i];
		if (curl - down[i + 1] > low)
			continue;
		if (level[i] - level[n] - up[i] > low)
			continue;
        ok[i] = true;
	}
    vector<int> perm = sufAr(s);
    int st = 0;
    while (!ok[perm[st]])
        ++st;
    st = perm[st];
	for (int i = 0; i < r - l; ++i) {
		cout << "(";
	}
	for (int j = 0, i = st; j < n; ++j, ++i) {
		if (i == n)
			i = 0;
		cout << s[i];
	}
	for (int i = 0; i < l - r; ++i)
		cout << ")";
	cout << endl;
}

//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();

#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}