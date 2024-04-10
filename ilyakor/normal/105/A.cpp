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

int main()
{
    int n, m;
    double dk;
    int k;
    cin >> n >> m >> dk;
    k = (int) (dk * 100.0 + 0.1);
    map<string, int> M;
    for (int i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> s >> x;
        x = (x * k) / 100;
        if (x < 100) continue;
        M[s] = x;
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (!M.count(s)) M[s] = 0;
    }
    cout << sz(M) << "\n";
    for (map<string, int>::iterator it = M.begin(); it != M.end(); ++it) {
        cout << (it->first) << " " << (it->second) << "\n";
    }
    return 0;
}