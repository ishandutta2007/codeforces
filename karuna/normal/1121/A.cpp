#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int p[1010];
int s[1010];
int c[1010];
int max_student[1010];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i=1; i<=n; i++) {
        scanf("%d", &s[i]);
        if (p[i] >= p[max_student[s[i]]]) {
            max_student[s[i]] = i;
        }
    }

    int a;
    int cnt = 0;
    for (int i=1; i<=k; i++) {
        scanf("%d", &a);
        if (max_student[s[a]] != a) {
            cnt++;
        }
    }

    cout << cnt;
}