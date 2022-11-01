#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 100500;

int main()
{
    string s;
    getline(cin, s);
    s += " ";
    
    string cur;
    int st = 0;
    forn(i, s.size()) {
        if (s[i] == '"') {
            if (st == 0)
                st = 1;
            else {
                st = 0;
                cout << "<" << cur << ">\n";
                cur.clear();
            }
        }
        else if (s[i] != ' ' || st) {
            cur += s[i];
        }
        else {
            if (!cur.empty()) cout << "<" << cur << ">\n";
            cur.clear();
        }
    }

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}