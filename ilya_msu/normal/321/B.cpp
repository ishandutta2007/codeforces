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
//const int INF = 50000;
//const int N = 1000 * 1000 * 1000 + 10;


vector<int> killDef(const vector<int>& d, const vector<int>& a) {
    vector<int> res;
    int i1 = 0, i2 = 0;
    while((i2 < a.size()) && (i1 < d.size())) {
        if (a[i2] <= d[i1]) {
            res.push_back(a[i2]);
            ++i2;
        }
        else {
            ++i1;
            ++i2;
        }
    }
    if (i1 < d.size()) {
        res.resize(0);
        return res;
    }
    for (int i = i2; i < a.size(); ++i)
        res.push_back(a[i]);
    return res;
}

int killAll(const vector<int>& a, const vector<int>& d) {
    int i1 = 0, i2 = 0;
    while((i2 < a.size()) && (i1 < d.size())) {
        if (a[i2] < d[i1]) {
            ++i2;
        }
        else {
            ++i1;
            ++i2;
        }
    }
    if (i1 < d.size()) {
        return 0;
    }
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += a[i];
    }
    for (int i = 0; i < d.size(); ++i)
        res -= d[i];
    return res;
}

int kill(const vector<int>& a, const vector<int>& d, int k) {
    int i1 = 0, i2 = 0;
    while((i2 < a.size()) && (i1 < k)) {
        if (a[i2] < d[i1]) {
            ++i2;
        }
        else {
            ++i1;
            ++i2;
        }
    }
    if (i1 < k) {
        return 0;
    }
    int res = 0;
    for (int i = a.size() - k; i < a.size(); ++i) {
        res += a[i];
    }
    for (int i = 0; i < k; ++i)
        res -= d[i];
    return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    vector<int> a, d;
    int n, m;
    cin >> n >> m;
    string s;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> s >> x;
        if (s == "ATK")
            a.push_back(x);
        else
            d.push_back(x);
    }
    vector<int> data(m);
    for (int i = 0; i < m; ++i)
        cin >> data[i];
    sort(data.begin(), data.end());
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    vector<int> data2 = killDef(d, data);
    int res = killAll(data2, a);
    for (int i = 0; i < a.size(); ++i) {
        res = max(res, kill(data, a, i + 1));
    }
    cout << res << endl;   
    return 0;
}