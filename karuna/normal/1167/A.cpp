#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, n;
string s;
int main() {
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        cin >> s;

        if (n<11) {
            printf("NO\n");
            continue;
        }

        bool flag = false;
        for (int i=0; i<=n-11; i++) {
            if (s[i] == '8') flag = true;
        }

        if (flag) printf("YES");
        else printf("NO");

        printf("\n");
    }
}