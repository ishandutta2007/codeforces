#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n;
int A[150000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    sort(A, A + n);
    int pr = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (pr < A[i] + j) {
                pr = A[i] + j;
                ++ans;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}