#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 n, k;
int64 p[20];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cin >> k;
    int64 n1 = max(n / 2 - 2, 0LL);
    int64 s = 0;
    int64 e = 1100000000000000000LL;
    map<int64, int64> cnt;
    cnt[1] = 1;
    for (int j = 0; j < n1; j++) {
        map<int64, int64> newcnt2;
        for (map<int64, int64>::iterator it = cnt.begin(); it != cnt.end();
             it++) {
            int64 f = it->first;
            newcnt2[f] += it->second;
            while (f <= e / p[j]) {
                f *= p[j];
                newcnt2[f] += it->second;
            }
        }
        cnt = newcnt2;
    }
    map<int64, int64> cnt2;
    cnt2[1] = 1;
    for (int j = n1; j < n; j++) {
        map<int64, int64> newcnt2;
        for (map<int64, int64>::iterator it = cnt2.begin(); it != cnt2.end();
             it++) {
            int64 f = it->first;
            newcnt2[f] += it->second;
            while (f <= e / p[j]) {
                f *= p[j];
                newcnt2[f] += it->second;
            }
        }
        cnt2 = newcnt2;
    }
    vector<pair<int64, int64> > p1;
    vector<pair<int64, int64> > p2;
    for (map<int64, int64>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        p1.push_back({it->first, it->second});
    }
    for (map<int64, int64>::iterator it = cnt2.begin(); it != cnt2.end();
         it++) {
        p2.push_back({it->first, it->second});
    }
    reverse(p1.begin(), p1.end());
    while (s + 1 < e) {
        int64 m = (s + e) / 2;
        int64 total = 0;
        int64 sum = 0;
        int64 b = 0;
        for (int64 a = 0; a < p1.size(); a++) {
            while (b < p2.size() && p1[a].first <= m / p2[b].first) {
                sum += p2[b].second;
                b++;
            }
            total += sum * p1[a].second;
        }
        if (total >= k) {
            e = m;
        } else {
            s = m;
        }
    }
    cout << e << endl;
}