#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

const int P = int(1e9) + 7;
const int N = int(2e5) + 5;

int ans[N];

stack<int> up, low;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, q = i;
        cin >> x;
        if (up.size() && up.top() >= x) {
            int t = up.top();
            up.pop();
            int p = up.top();
            up.pop();
            int k = -1;
            if (low.size()) k = low.top();
            if (!low.size() || t < k) {
                low.push(p);
                low.push(t);
            } else if (!low.size() || x < k) {
                low.push(q);
                low.push(x);
                q = p;
                x = t;
            } else {
                printf("NO");
                return 0;
            }
        }
        if (up.size() && up.top() >= x) {
            int t = up.top();
            up.pop();
            int p = up.top();
            up.pop();
            int k = -1;
            if (low.size()) k = low.top();
            if (!low.size() || x < k) {
                low.push(q);
                low.push(x);
                q = p;
                x = t;
            } else {
                printf("NO");
                return 0;
            }
        }
        up.push(q);
        up.push(x);
    }
    while (low.size()) {
        low.pop();
        int p = low.top();
        low.pop();
        ans[p] = 1;
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    return 0;
}