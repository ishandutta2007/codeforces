#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const char gen[4] = {'A', 'C', 'T', 'G'};

int n;
string s;
int main() {
    scanf("%d", &n);
    cin >> s;

    int mini = 1234567;
    for (int i=0; i<=n-4; i++) {
        int ans = 0;
        int temp;
        int a, b;
        for (int j=0; j<4; j++) {
            a = max(s[i+j], gen[j]);
            b = min(s[i+j], gen[j]);
            temp = min(a-b, (26+b-a));

            ans += temp;
        }
        mini = min(mini, ans);
    }

    printf("%d", mini);
}