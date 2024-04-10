#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    cout << n << endl;
    for(int i = 0; i < n; i++) {
        int idx = i;
        for(int j = i + 1; j < n; j++) {
            if(a[idx] > a[j]) {
                idx = j;
            }
        }
        swap(a[idx], a[i]);
        cout << idx << " " << i << endl;
    }
    return 0;
}