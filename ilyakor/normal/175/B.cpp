#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

vector<int> v;

bool worse(int s, int p) {
    int cnt = 0;
    for (int i = 0; i < sz(v); ++i)
        if (v[i] > s) ++cnt;
    return cnt * 100 >= p * sz(v);
}

bool worse0(int s, int p) {
    int cnt = 0;
    for (int i = 0; i < sz(v); ++i)
        if (v[i] > s) ++cnt;
    return cnt * 100 > p * sz(v);
}

int main() {
/*  cout << "100\n";
    for (int i = 0; i < 100; ++i)
        printf("%c%c %d\n", ('a' + i / 10), ('a' + i % 10), i + 1);
    return 0;*/
    int n;
    cin >> n;
    map<string, int> M;
    for (int i = 0; i < n; ++i) {
        string s;
        int val;
        cin >> s >> val;
        M[s] = max(M[s], val);
    }

    vector<string> p;
    for (map<string, int>::iterator it = M.begin(); it != M.end(); ++it) {
        p.pb(it->first);
        v.pb(it->second);
    }

    sort(all(v));
    reverse(all(v));

    cout << sz(p) << "\n";

    for (int i = 0; i < sz(p); ++i) {
        int s = M[p[i]];
        string res = "";
        if (worse0(s, 50))
            res = "noob";
        else if (worse0(s, 20))
            res = "random";
        else if (worse0(s, 10))
            res = "average";
        else if (worse0(s, 1))
            res = "hardcore";
        else res = "pro";

        cout << p[i] << " " << res << "\n";
    }
    return 0;
}