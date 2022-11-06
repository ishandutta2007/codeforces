#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
char str[100][101];
int len[100];
int a[100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
        cin >> str[i];
        a[i] = i;
        len[i] = strlen(str[i]);
	}
	sort(a, a + n, [&](int i, int j) {
        return len[i] < len[j];
    });
    for (int i = 0; i < n - 1; ++i) {
        int x = a[i], y = a[i + 1], p = 1, q;
        for (int j = 0; j <= len[y] - len[x]; ++j) {
            q = 1;
            for (int k = 0; k < len[x]; ++k) {
                if (str[x][k] != str[y][k + j]) {
                    q = 0;
                    break;
                }
            }
            if (q) {
                p = 0;
                break;
            }
        }
        if (p) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", str[a[i]]);
    }
	return 0;
}