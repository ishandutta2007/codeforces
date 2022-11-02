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

char ts[10000];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    scanf("%s", ts);
    set<int> S;
    int last = -1;
    for (int i = 0; ts[i]; ++i)
    {
        if (ts[i] == '0') continue;
        if (last != -1)
            S.insert(i - last);
        last = i;
    }
    printf("%s\n", sz(S) <= 1 ? "YES" : "NO");
    return 0;
}