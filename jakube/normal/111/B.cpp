#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    vector<int> xs;
    vector<int> m(1e5+1, -1e6);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xs.push_back(x);
        
        int cnt = 0;
        for (int div = 1; div*div <= x; ++div) {
            if (div*div == x) {
                if (m[div] < i-y) 
                    cnt++;
                m[div] = i;
            }
            else if (x % div == 0) {
                if (m[div] < i-y) 
                    cnt++;
                if (m[x/div] < i-y) 
                    cnt++;
                m[div] = i;
                m[x/div] = i;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}