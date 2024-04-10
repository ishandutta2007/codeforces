#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int SIGMA = 128;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    string s;
    while (cin >> n >> s) {
        vector<int> cnt(SIGMA);
        for (char c : s) cnt[c]++;

        int odd = 0;
        for (int i = 0; i < SIGMA; i++) odd += cnt[i] % 2;

        vector<string> ans;
        for (int d = n; d >= 1; d--) {
            if (n % d != 0) continue;
            int count = n / d;
            if (count < odd) continue;
            if (d % 2 == 0 && odd > 0) continue;
            
            for (int i = 0; i < count; i++) {
                string mid = "";
                if (d % 2 == 1) {
                    int cc = -1;
                    for (int c = 0; c < SIGMA; c++) {
                        if (cc == -1 && cnt[c] > 0) cc = c;
                        if ((cc == -1 || cnt[cc] % 2 == 0) && cnt[c] % 2 == 1) cc = c;
                    }
                    assert(cc != -1 && cnt[cc] > 0);
                    cnt[cc]--;
                    mid = string(1, cc); 
                }
                string right = "";
                for (int c = 0; c < SIGMA; c++) {
                    while (cnt[c] >= 2 && (int)right.length() < d / 2) {
                        cnt[c] -= 2;
                        right += (char)c;
                    }
                }
                string left = right;
                reverse(left.begin(), left.end());
                ans.push_back(left + mid + right);
            }
            break;
        }
        assert(!ans.empty());
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
    }
    
    return 0;
}