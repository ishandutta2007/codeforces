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
int A[1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        bool P = true;
        for (int j = i + 1; j <= n; ++j) {
            if (A[j] - A[j - 1] != A[j - i] - A[j - i - 1]) {
                P = false;
                break;
            }
        }
        if (P) ans.push_back(i);
    }
    printf("%d\n", (int)ans.size());
    for (int i : ans) printf("%d ", i);
    return 0;
}