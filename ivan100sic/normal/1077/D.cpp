#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;



int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, k;
        cin >> n >> k;
        vector<int> a(200001, 0);
        for (int i=0; i<n; i++) {
                int x;
                cin >> x;
                a[x]++;
        }

        int l = 1, r = n, o = -1;
        while (l <= r) {
                int m = (l+r) >> 1;
                int z = 0;
                for (int i=1; i<=200000; i++) {
                        z += a[i] / m;
                }
                if (z >= k) {
                        o = m;
                        l = m+1;
                } else {
                        r = m-1;
                }
        }

        cerr << "o: " << o << '\n';
        for (int i=1; i<=200000; i++) {
                int x = a[i] / o;
                while (x > 0 && k > 0) {
                        cout << i << ' ';
                        k--;
                        x--;
                }
        }
        cout << '\n';
}