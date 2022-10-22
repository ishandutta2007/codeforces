#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> nums1(n), nums2(n);
        for(int i = 0; i < n; i++) {
            cin >> nums1[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> nums2[i];
        }
        vector<ll> pref(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + (nums1[i-1] - nums2[i-1]);
        }
        vector<int> l(m), r(m), zeroCount(m, 2);
        vector<vector<int>> assign(n+1);
        set<int> notZeroes;
        queue<int> allZeroes;
        for(int i = 0; i <= n; i++) {
            if(pref[i] != 0) {
                notZeroes.insert(i);
            }
        }
        notZeroes.insert(n+1);
        for(int i = 0; i < m; i++) {
            cin >> l[i] >> r[i];
            l[i]--;
            assign[l[i]].push_back(i);
            assign[r[i]].push_back(i);
            if(pref[l[i]] == 0) zeroCount[i]--;
            if(pref[r[i]] == 0) zeroCount[i]--;
            if(zeroCount[i] == 0) {
                allZeroes.push(i);
            }
        }
        while(allZeroes.size()) {
            int g = allZeroes.front();
            allZeroes.pop();
            auto it = notZeroes.lower_bound(l[g]);
            while((*it) <= r[g]) {
                int toRemove = (*it);
                pref[toRemove] = 0;
                for(int a : assign[toRemove]) {
                    zeroCount[a]--;
                    if(zeroCount[a] == 0) {
                        allZeroes.push(a);
                    }
                }
                it++;
                notZeroes.erase(toRemove);
            }
        }
        bool ok = true;
        for(int i = 0; i <= n; i++) {
            if(pref[i]) ok = false;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}