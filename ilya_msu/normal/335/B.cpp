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
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;
const long double eps = 1e-10;

vector<vector<int> > d;
vector<vector<pii> > p;
vector<vector<int> > nxt, pr;
int sol(int l, int r) {
    if (r < l)
        return 0;
    if (l == r)
        return 1;
    if (d[l][r] != -1)
        return d[l][r];
    d[l][r] = 0;
    for (int i = 0; i < 26; ++i) {
        int l1 = nxt[i][l], r1 = pr[i][r];
        if ((l1 == -1) || (r1 == -1))
            continue;
        if (l1 > r1)
            continue;
        int x = sol(l1 + 1, r1 - 1);
        if (l1 < r1)
            ++x;
        ++x;
        if (x > d[l][r]) {
            d[l][r] = x;
            p[l][r] = pii(l1, r1);
        }
    }
    return d[l][r];
}


int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    string s;
    int n;
    cin >> s;
    n = s.size();
    vector<int> count(26, 0);
    for (int i = 0; i < s.size(); ++i)
        ++count[s[i] - 'a'];
    for (int i = 0; i < 26; ++i)
        if (count[i] >= 100) {
            string res;
            for (int j = 0; j < 100; ++j)
                res += ('a' + i);
            cout << res << endl;
            return 0;
        }
    d.assign(n, vector<int> (n, -1));
    p.assign(n, vector<pii> (n));
    vector<vector<int> > pos(26);
    nxt.assign(26, vector<int> (n, -1));
    pr.assign(26, vector<int> (n, -1));
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
        nxt[s[i] - 'a'][i] = i;
        pr[s[i] - 'a'][i] = i;

    }
    for (int i = 0; i < 26; ++i) {
        int k = -1;
        for (int j = 0; j < n; ++j) {
            if (pr[i][j] != -1)
                k = pr[i][j];
            pr[i][j] = k;
        }
        k = -1;
        for (int j = n - 1; j >= 0; --j) {
            if (nxt[i][j] != -1)
                k = j;
            nxt[i][j] = k;
        }
    }
    int l = sol(0, n - 1);
    string res;
    pii cur(0, n - 1);
    vector<int> ans;
    while(l >= 2) {
        cur = p[cur.first][cur.second];
        res += s[cur.first];
        ++cur.first, --cur.second;
        l -= 2;
    }
    if (l == 1)
        res += s[cur.first];
    int m = res.size() - l - 1;
    for (int i = m; i >= 0; --i)
        res += res[i];
    if (res.size() < 100)
        cout << res << endl;
    else
        cout << res.substr(0, 50) << res.substr(res.size() - 50, 50) << endl;
    return 0;
}