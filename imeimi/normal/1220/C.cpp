#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

char in[500001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> in;
    char mn = 'z';
    for (int i = 0; in[i]; ++i) {
        printf(mn < in[i] ? "Ann\n" : "Mike\n");
        mn = min(mn, in[i]);
    }
}