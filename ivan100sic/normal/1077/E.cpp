#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;



int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;
        map<int, int> mp;
        for (int i=0; i<n; i++) {
                int x;
                cin >> x;
                mp[x]++;
        }
        vector<int> a;
        for (auto p : mp)
                a.push_back(p.second);
        sort(a.begin(), a.end());

        int z = 0;

        for (int i=1; i<=n; i++) {
                // baza je i
                int x = i, y = 0;
                auto it = a.begin();
                while (1) {
                        it = lower_bound(it, a.end(), x);
                        if (it == a.end())
                                break;
                        y += x;
                        x <<= 1;
                        ++it;
                }
                z = max(z, y);
        }

        cout << z << '\n';
}