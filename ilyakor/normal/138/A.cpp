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



string ans[4] = {"aabb", "abab", "abba", "aaaa"};



string vow = "aeiou";



string cut(string s, int k) {

    set<char> sv(all(vow));

    string res;

    for (int i = sz(s) - 1; i >= 0; --i) {

        res += s[i];

        if (sv.count(s[i])) {

            --k;

            if (k == 0) break;

        }

    }

    if (k) for (int i = 0; i < 10; ++i) res += (char)(rand() % 100 + 10);

    reverse(all(res));

    return res;

}



int main() {

    int n, k;

    cin >> n >> k;

    set<int> ok;

    ok.insert(0);

    ok.insert(1);

    ok.insert(2);

    for (int i = 0; i < n; ++i) {

        vector<string> v(4);

        for (int j = 0; j < 4; ++j) {

            cin >> v[j];

            v[j] = cut(v[j], k);

        }



        vi del;

        if (v[0] != v[1] || v[2] != v[3]) del.pb(0);

        if (v[0] != v[2] || v[1] != v[3]) del.pb(1);

        if (v[0] != v[3] || v[2] != v[1]) del.pb(2);

        for (int j = 0; j < sz(del); ++j) {

            int x = del[j];

            if (ok.count(x)) ok.erase(x);

        }

    }

    if (!sz(ok)) printf("NO\n");

    else if (sz(ok) > 1) printf("aaaa\n");

    else cout << ans[*ok.begin()] << "\n";

    return 0;

}