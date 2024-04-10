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
const int INF = 500000;
//const int N = 1000 * 1000 * 1000 + 10;
string toStr(int k) {
    string res;
    while(k) {
        res.push_back(k % 10 + '0');
        k /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool zero(int x) {
    while(x) {
        if (x % 10 == 0)
            return true;
        x /= 10;
    }
    return false;
}
vector<int> gen(string s) {
    if (s.size() == 1)
        return vector<int>(1, s[0] - '0');
    vector<int> res;
    int cur = 0;
    for (int i = 1; i < s.size(); ++i) {
        cur = 10 * cur + (s[i - 1] - '0');
        vector<int> a = gen(s.substr(i, s.size() - i));
        for (int j = 0; j < a.size(); ++j) {
            res.push_back(cur + a[j]);
            res.push_back(cur - a[j]);
            res.push_back(cur * a[j]);
        }
    }
    return res;
}

vector<int> gen(int x) {
    string s = toStr(x);
    vector<int> res = gen(s);
    /*if (s.size() < 4)
        res.push_back(0);*/
    sort(res.begin(), res.end());
    vector<int> ans;
    if (res.size() >= 1)
        ans.push_back(res[0]);
    for (int i = 1; i < res.size(); ++i)
        if (res[i] != res[i - 1])
            ans.push_back(res[i]);
    return ans;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    set<string> ans;
    int k, m;
    cin >> k >> m;
    int c = 0;
    if (k < 100) {
        string kk = toStr(k);
        string res;
        for (int i = 0; i < 1000 * 1000; ++i) {
            int x = i;
            if (zero(x)) {
                res = kk + toStr(x);
                while(res.size() < 8)
                    res += '0';
                if (ans.find(res) == ans.end()) {
                cout << res << "\n";
                ++c;
                if (c == m)
                    return 0;
                ans.insert(res);
                }
            }
        }
    }
    for (int i = 1; i < 10000; ++i) {
        vector<int> q = gen(i);
        string b = toStr(i);
        while(b.size() < 4)
            b = '0' + b;
        for (int j = 0; j < q.size(); ++j) {
            int x = q[j];
            int y = k - x;
            if ((y >= 0) && (y < 10000)) {
                string end = toStr(y);
                while(end.size() < 4)
                    end = '0' + end;
                if (ans.find(b + end) == ans.end()) {
                cout << b << end << "\n";
                ++c;
                if (c == m)
                return 0;
                ans.insert(b + end);
                }
                if (ans.find(end + b) == ans.end()) {
                cout << end << b << "\n";
                ++c;
                if (c == m)
                return 0;
                ans.insert(end + b);
                }
            }
            else {
                y = x - k;
                if ((y >= 0) && (y < 10000)) {
                string end = toStr(y);
                while(end.size() < 4)
                    end = '0' + end;
                if (ans.find(b + end) == ans.end()) {
                cout << b << end << "\n";
                ++c;
                if (c == m)
                return 0;
                ans.insert(b + end);
                }
                if (ans.find(end + b) == ans.end()) {
                cout << end << b << "\n";
                ++c;
                if (c == m)
                return 0;
                ans.insert(end + b);
                }
            }
            }
            if (c == m)
                return 0;
        }
    }
    return 0;
}