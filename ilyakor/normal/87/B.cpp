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

map<string, int> M;

int eval(string s) {
    int c1 = 0, c2 = 0;
    string t;
    int ind1 = 0;
    while (ind1 < sz(s) && s[ind1] == '&') ++ind1, ++c1;
    int ind2 = sz(s) - 1;
    while (ind2 >= 0 && s[ind2] == '*') --ind2, ++c2;
    t = s.substr(ind1, ind2 - ind1 + 1);
    if (!M.count(t)) return -1;
    int x = M[t];
    if (x == -1) return -1;
    x += c2;
    x -= c1;
    if (x < 0) return -1;
    return x;
}

int main()
{
    int n;
    cin >> n;
    M["void"] = 0;
    for (int i = 0; i < n; ++i) {
        string ws;
        cin >> ws;
        if (ws == "typeof") {
            string s;
            cin >> s;
            int x = eval(s);
            if (x == -1)
                printf("errtype\n");
            else {
                printf("void");
                for (int j = 0; j < x; ++j) printf("*");
                printf("\n");
            }
        } else {
            string s, t;
            cin >> s >> t;
            M[t] = eval(s);
        }
    }
    return 0;
}