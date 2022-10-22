#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, cnt1, cnt2;
string s;
int main() {
    cin >> n;
    cin >> s;

    for (int i=0; i<n; i++) {
        if (s[i] == '0') cnt1++;
        else cnt2++;
    }

    if (cnt1==cnt2) {
        printf("2\n");
        for (int i=0; i<n-1; i++) printf("%c", s[i]);
        printf(" %c", s[n-1]);
    }
    else {
        printf("1\n");
        cout << s;
    }
}