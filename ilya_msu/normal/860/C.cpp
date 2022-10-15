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
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

map<string, int> mp;

int toInt(string& s) {
    int res = 0;
    if (s[0] == '0')
        return -1;
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] >= '0') && (s[i] <= '9'))
            res = res * 10 + (s[i] - '0');
        else
            return -1;
    }
    return res;
}

string getUnusedName(const vector<int>& a) {
    if (a.empty())
        return "1";
    if (a[0] != 1)
        return "1";
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] > a[i - 1] + 1) {
            return to_string(a[i - 1] + 1);
        }
    }
    return to_string(a.back() + 1);
}


void solve() {
    int n;
    cin >> n;
    vector<string> exJunk, ordJunk;
    vector<int> used(n + 1, 0);
    int totalEx = 0;
    vector<int> sints, sintsEx;
    vector<int> usedInts;
    for (int i = 0; i < n; ++i) {
        string s;
        int ex;
        cin >> s >> ex;
        totalEx += ex;
        int sint = toInt(s);
        if (sint > 0)
            usedInts.push_back(sint);
        if ((sint == -1) || (sint > n) || (sint < 1)) {
            if (ex) {
                exJunk.push_back(s);
            }
            else
                ordJunk.push_back(s);
        }
        else {
            used[sint] = 1;    
            sints.push_back(sint);
            sintsEx.push_back(ex);

        }
    }
    vector<int> badExs, badOrds;
    for (int i = 0; i < sints.size(); ++i) {
        int sint = sints[i];
        if ((sint <= totalEx) && (sintsEx[i] == 0))
            badExs.push_back(sint);
        if ((sint > totalEx) && (sintsEx[i] == 1))
            badOrds.push_back(sint);
    }
    queue<int> unusedEx, unusedOrds;
    for (int i = 1; i <= totalEx; ++i) {
        if (used[i] == 0)
            unusedEx.push(i);
    }
    for (int i = totalEx + 1; i <= n; ++i) {
        if (used[i] == 0)
            unusedOrds.push(i);
    }
    sort(usedInts.begin(), usedInts.end());
    string unusedName = getUnusedName(usedInts);
    int usedAdd = 0;
    vector<string> res;
    while ((!badExs.empty()) || (!badOrds.empty())) {
        if (!badExs.empty()) {
            int x = badExs.back();
            if (!unusedOrds.empty()) {
                int y = unusedOrds.front();
                unusedOrds.pop();
                if (used[y])
                    continue;
                res.push_back("move " + to_string(x) + " " + to_string(y));
                used[x] = 0;
                badExs.pop_back();
                used[y] = 1;
                unusedEx.push(x);
                continue;
            }
        }
        if (!badOrds.empty()) {
            int x = badOrds.back();
            if (!unusedEx.empty()) {
                int y = unusedEx.front();
                unusedEx.pop();
                if (used[y])
                    continue;
                res.push_back("move " + to_string(x) + " " + to_string(y));
                badOrds.pop_back();
                used[x] = 0;
                used[y] = 1;
                unusedOrds.push(x);
                continue;
            }
        }
        if (!badExs.empty()) {
            int x = badExs.back();
            badExs.pop_back();
            res.push_back("move " + to_string(x) + " " + unusedName);
            usedAdd = 1;
            used[x] = 0;
            unusedEx.push(x);
            continue;
        }
        if (!badOrds.empty()) {
            int x = badOrds.back();
            res.push_back("move " + to_string(x) + " " + unusedName);
            badOrds.pop_back();
            usedAdd = 1;
            used[x] = 0;
            unusedOrds.push(x);
            continue;
        }
    }
    for (int i = 1; i <= totalEx; ++i) {
        if (used[i])
            continue;
        if (!exJunk.empty()) {
            res.push_back("move " + exJunk.back() + " " + to_string(i));
            exJunk.pop_back();
        }
        else {
            res.push_back("move " + unusedName + " " + to_string(i));
        }
        used[i] = 1;
    }
    for (int i = totalEx + 1; i <= n; ++i) {
        if (used[i])
            continue;
        if (!ordJunk.empty()) {
            res.push_back("move " + ordJunk.back() + " " + to_string(i));
            ordJunk.pop_back();
        }
        else {
            res.push_back("move " + unusedName + " " + to_string(i));
        }
        used[i] = 1;
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << "\n";

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