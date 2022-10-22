#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int ans[202020];
string s;
int main() {
    cin >> n >> s;

    int d1=0, d2=0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') {
            if (d1==d2) {
                ++d1;
                ans[i] = 0;
            }
            else {
                ++d2;
                ans[i] = 1;
            }
        }
        else {
            if (d1==d2) {
                --d2;
                ans[i] = 1;
            }
            else {
                --d1;
                ans[i] = 0;
            }
        }
    }

    for (int i=0; i<n; i++) {
        printf("%d", ans[i]);
    }
}