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

char buf[1000 * 1000 * 2];

int Next[20 * 1000][26];
int nc[20 * 1000][26];


int main()
{
    scanf("%s", buf);
    string s1 = buf;
    scanf("%s", buf);
    string s2 = buf;
    memset(Next, -1, sizeof(Next));
    memset(nc, 0, sizeof(nc));
    for (int i = sz(s1) - 1; i >= 0; --i) {
        memcpy(Next[i], Next[i + 1], sizeof(Next[i + 1]));
        Next[i][s1[i] - 'a'] = i;
    }
    memcpy(Next[sz(s1)], Next[0], sizeof(Next[0]));
    for (int i = sz(s1) - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (Next[i][j] != -1) continue;
            Next[i][j] = Next[i + 1][j];
            nc[i][j] = 1;
        }
        if (Next[i][s1[i] - 'a'] == -1){
            Next[i][s1[i] - 'a'] = i;
            nc[i][s1[i]] = 1;
        }
    }
    int res = 1;
    int cur = 0;
    for (int i = 0; i < sz(s2); ++i) {
        int x = s2[i] - 'a';
        if (cur >= sz(s1)) {
            cur -= sz(s1), ++res;
        }
        if (Next[cur][x] == -1) {
            printf("-1\n");
            return 0;
        }
        res += nc[cur][x];
        cur = Next[cur][x] + 1;
    }
    cout << res << "\n";
    return 0;
}