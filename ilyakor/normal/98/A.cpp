#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

set<string> S;

int p1[6] = {1, 2, 3, 0, 4, 5};
int p2[6] = {0, 5, 2, 4, 1, 3};
int p3[6] = {5, 1, 4, 3, 0, 2};

string apply1(string s) {
    string t;
    for (int i = 0; i < sz(s); ++i)
        t += s[p1[i]];
    return t;
}

string apply2(string s) {
    string t;
    for (int i = 0; i < sz(s); ++i)
        t += s[p2[i]];
    return t;
}

string apply3(string s) {
    string t;
    for (int i = 0; i < sz(s); ++i)
        t += s[p3[i]];
    return t;
}

string norm(string s) {
    queue<string> q;
    set<string> M;
    string res = s;
    q.push(s);
    M.insert(s);
    while (!q.empty()) {
        string t = q.front();
        q.pop();
        res = min(res, t);
        {
            string t0 = apply1(t);
            if (!M.count(t0)) {
                q.push(t0);
                M.insert(t0);
            }
        }
        {
            string t0 = apply2(t);
            if (!M.count(t0)) {
                q.push(t0);
                M.insert(t0);
            }
        }
        {
            string t0 = apply3(t);
            if (!M.count(t0)) {
                q.push(t0);
                M.insert(t0);
            }
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    sort(all(s));
    do {
        string t = norm(s);
        S.insert(t);
    } while (next_permutation(all(s)));
    cout << sz(S) << "\n";
    return 0;
}