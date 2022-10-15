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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
//const int N = 100 * 1000 + 10;
//const ll mod = 3046201;
int n;
struct rule {
    string p;
    int l, r;
};

vector<rule> rules;

vector<int> zz(string s) {
    int m = s.size();
	vector<int> z(m);
	for (int i = 1, l = 0, r = 0; i < m; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < m && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;
	}
	return z;
}

set<ll> res;
ll prime = 31;
void solve(string s) {
    vector<bool> ans(s.size(), true);
    for (int j = 0; j < n; ++j) {
        string ss = s + rules[j].p;
        vector<int> z = zz(ss);
        vector<int> a(s.size() + 1, 0);
        for (int i = s.size(); i < z.size(); ++i)
            ++a[min((int)s.size(), z[i])];
        for (int i = a.size() - 2; i >= 0; --i)
            a[i] = a[i] + a[i + 1];
        for (int i = 1; i < a.size(); ++i) {
            if ((a[i] < rules[j].l) || (a[i] > rules[j].r))
                ans[i - 1] = false;
        }
    }
    ll hash = 0;
    ll mu = 1;
    for (int i = 0; i < ans.size(); ++i) {
        hash += s[i] * mu;
        mu = mu * prime;
        if (ans[i])
            res.insert(hash);
    }
}

int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s, sold;
    cin >> s;
    sold = s;
    cin >> n;
    rules.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> rules[i].p >> rules[i].l >> rules[i].r;
    }
    int m = s.size();
    for (int i = 0; i < m; ++i) {
        solve(s);
        s = s.substr(1, s.size() - 1);        
    }
    cout << res.size() << endl;
    return 0;
}