#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int siz = (1LL << 24);

int ans[siz];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int c[3] = {s[0] - 'a', s[1] - 'a', s[2] - 'a'};
        for(int i = 1; i < 8; i++) {
            int x = 0, ct = 0;
            for(int j = 0; j < 3; j++) {
                if(i & (1 << j)) {
                    ct++;
                    x |= (1 << c[j]);
                }
            }
            if(ct % 2) ans[x]++;
            else ans[x]--;
        }
    }
    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < (1 << 24); j++) {
            if(j & (1 << i)) {
                ans[j] += ans[j ^ (1 << i)];
            }
        }
    }
    int final_ans = 0;
    for(int i = 0; i < siz; i++) {
        final_ans ^= (ans[i] * ans[i]);
    }
    cout << final_ans << '\n';
}