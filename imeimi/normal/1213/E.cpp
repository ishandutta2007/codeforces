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

int E[3][3];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    char S[5];
    cin >> S;
    E[S[0] - 'a'][S[1] - 'a'] = 1;
    cin >> S;
    E[S[0] - 'a'][S[1] - 'a'] = 1;
    printf("YES\n");
    for (int i = 0; i < 3; ++i) {
        if (E[i][i] == 1) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) continue;
                if (E[i][j] == 1) continue;
                if (E[j][i] == 1) continue;
                int k = i ^ j ^ 3;
                if (E[k][k] == 1) continue;
                if (E[j][k] == 0) swap(i, j);
                for (int it = 0; it < n; ++it) {
                    printf("%c%c", 'a' + j, 'a' + i);
                }
                for (int it = 0; it < n; ++it) {
                    printf("%c", 'a' + k);
                }
                return 0;
            }
        }
    }
    int ord[] = { 0, 1, 2 };
    do {
        if (E[ord[0]][ord[1]]) continue;
        if (E[ord[1]][ord[2]]) continue;
        for (int i = 0; i < n; ++i) printf("%c", (char)(ord[0] + 'a'));
        for (int i = 0; i < n; ++i) printf("%c", (char)(ord[1] + 'a'));
        for (int i = 0; i < n; ++i) printf("%c", (char)(ord[2] + 'a'));
        return 0;
    } while (next_permutation(ord, ord + 3));
    return 1;
}