#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n;
int cnt[3];
int ch[500000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < 500000; ++i) {
        if (ch[i]) continue;
        for (int j = i + i; j < 500000; j += i) {
            ch[j] = 1;
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    if (cnt[1] == 0) {
        for (int i = 0; i < n; ++i) {
            printf("2 ");
        }
        return 0;
    }
    if (cnt[2] == 0) {
        for (int i = 0; i < n; ++i) {
            printf("1 ");
        }
        return 0;
    }
    printf("2 ");
    printf("1 ");
    --cnt[1];
    --cnt[2];
    while (cnt[2]--) printf("2 ");
    while (cnt[1]--) printf("1 ");
    return 0;
}