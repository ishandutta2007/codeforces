#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    while(cin >> n) {
        vector<int> a(n);
        REP(i, n) cin >> a[i];

        vector<int> lis(1, INT_MIN);
        vector<int> b(n);
        REP(i, n) {
            int k = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            b[i] = k;
            if(lis.size() == k) {
                lis.push_back(a[i]);
            } else {
                lis[k] = a[i];
            }
        }

        int L = lis.size() - 1;
        vector<int> size(L + 1);
        vector<int> c(n);
        vector<int> max_a(L + 1, INT_MIN);
        for(int i = n - 1; i >= 0; i--) {
            int s = b[i];
            if((s == L) || (a[i] < max_a[s+1])) {
                size[s]++;
                c[i] = true;
                max_a[s] = max(max_a[s], a[i]);
            } else {
                c[i] = false;
            }
        }

        REP(i, n) {
            if(c[i] == 0) {
                cout << 1;
            } else {
                int s = b[i];
                assert(size[s] >= 1);
                cout << (size[s] > 1 ? 2 : 3);
            }
        }
        cout << endl;
    }
    return 0;
}