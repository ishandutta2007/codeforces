#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
int c[200005];
vector<pair<int, int> > v;
int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        v.clear();
        int n;
        int cnt2 = 0, cnt0 = 0, lastb = 0;
        cin >> n;
        int aaa;
        for (int i = 1; i <= n; i++) {
            int aa;
            cin >> aa;
            c[i] = aa;
            if (i != 1) {
                b[aa]++;
                lastb = max(lastb, aa);
            } else
                aaa = aa;
        }
        for (int i = 1; i <= lastb; i++) {
            if (b[i] > 1)
                cnt2++;
            else if (b[i] == 0)
                cnt0++;
        }
        int cnt22 = 0, cnt00 = 0, lasta = 0;
        a[aaa]++;
        cnt00 = aaa - 1;
        lasta = aaa;
        int ccnntt = 0;
        for (int i = 2; i <= n; i++) {
            if (cnt0 == 0 && cnt2 == 0 && cnt00 == 0 && cnt22 == 0) {
                ccnntt++;
                v.push_back(pair<int, int>(i - 1, n - i + 1));
                // cout << i << endl;
            }
            b[c[i]]--;
            if (b[c[i]] == 0)
                cnt0++;
            else if (b[c[i]] == 1)
                cnt2--;
            while (b[lastb] == 0) {
                cnt0--;
                lastb--;
            }
            if (c[i] > lasta) {
                cnt00 += c[i] - lasta - 1;
                lasta = c[i];
                a[c[i]]++;
            } else {
                a[c[i]]++;
                if (a[c[i]] > 1)
                    cnt22++;
                else if (a[c[i]] == 0)
                    cnt00++;
                else if (a[c[i]] == 1)
                    cnt00--;
            }
        }
        cout << ccnntt << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].first << ' ' << v[i].second << endl;
        }
    }
}