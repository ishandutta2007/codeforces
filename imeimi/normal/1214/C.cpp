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

int n;
char in[200002];
char ch[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> in + 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == '(') {
            ++sum;
        }
        else {
            --sum;
        }
    }
    if (sum != 0) {
        printf("No\n");
        return 0;
    }
    {
        int E = 0, F = n + 1;
        for (int i = 1; i <= n; ++i) {
            if (in[i] == '(') {
                E = max(F, i);
            }
            else {
                F = min(F, i);
            }
        }
        {
            int sum = 1;
            for (int i = 1; i <= n; ++i) {
                if (i == E) continue;
                if (in[i] == '(') {
                    ++sum;
                }
                else {
                    --sum;
                }
                if (sum < 0) break;
            }
            if (sum == 0) {
                printf("Yes\n");
                return 0;
            }
        }
        {
            int sum = 1;
            for (int i = n; i > 0; --i) {
                if (i == F) continue;
                if (in[i] == '(') {
                    --sum;
                }
                else {
                    ++sum;
                }
                if (sum < 0) break;
            }
            if (sum == 0) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}