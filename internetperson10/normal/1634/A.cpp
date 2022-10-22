#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        auto isPalindrome = [&]() {
            for(int i = 0; i < n; i++) {
                if(s[i] != s[n-1-i]) return false;
            }
            return true;
        };
        if(k == 0 || isPalindrome()) cout << "1\n";
        else cout << "2\n";
    }
}