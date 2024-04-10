#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    int res = 0;
    for (int i = 0; i < n / 2; i++) {
        vector<int> cnt(26, 0);
        cnt[s[i] - 'a']++;
        cnt[s[n-1-i] - 'a']++;
        cnt[t[i] - 'a']++;
        cnt[t[n-1-i] - 'a']++;

        int c = 0;
        for (int x : cnt)
            c += x % 2;
        if (c == 2) {
            if (s[i] == s[n-1-i] && cnt[s[i]-'a'] == 2) {
                res += 2;
            } else
                res += 1;
        }
        if (c == 4)
            res += 2;
    }
    if (n % 2 && s[n/2] != t[n/2])
        res++;
    cout << res << endl;
}