#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        string s;
        cin >> s;

        int mini = 1293123;
        for (int i=0; i<n; i++) {
            if (s[i] == '>') {
                mini = i;
                break;
            }
            if (s[n-1-i] == '<') {
                mini = i;
                break;
            }
        }

        printf("%d\n", mini);
    }
}