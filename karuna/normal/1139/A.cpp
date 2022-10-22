#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll cnt = 0;
    for (int i=0; i<n; i++) {
        if (s[i]%2 == 0) {
            cnt += i+1;
        }
    }

    printf("%lld", cnt);
}