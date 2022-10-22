#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, k;
string s;
int main() {
    scanf("%d", &n);
    cin >> s;

    bool f = false;
    for (int i=1; i<n; i++) {
        if (s[i-1] > s[i]) {
            printf("YES\n");
            printf("%d %d", i, i+1);
            return 0;
        }
    }

    printf("NO");
}