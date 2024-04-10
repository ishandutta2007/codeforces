#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int freq[26], num[200005];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        memset(freq, 0, sizeof(freq));
        for (int i = s.size() - 1; i >= 0; i--) {
            freq[s[i] - 'a']++;
            num[i] = freq[s[i] - 'a'];
        }
        int id = 0;
        for (int i = 0; i < s.size(); i++) {
            if (num[i] == 1) {
                id = i;
                break;
            }
        }
        for (int i = id; i < s.size(); i++) printf("%c", s[i]);
        printf("\n");
    }

    return 0;
}