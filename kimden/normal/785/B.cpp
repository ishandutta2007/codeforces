#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int ml1 = 0, mr1 = 1000000001, ml2 = 0, mr2 = 1000000001;
    vector<int> l1(n), r1(n);
    for(int i = 0; i < n; ++i){
        cin >> l1[i] >> r1[i];
        ml1 = max(ml1, l1[i]);
        mr1 = min(mr1, r1[i]);
    }
    int m;
    cin >> m;
    vector<int> l2(m), r2(m);
    for(int i = 0; i < m; ++i){
        cin >> l2[i] >> r2[i];
        ml2 = max(ml2, l2[i]);
        mr2 = min(mr2, r2[i]);
    }
    cout << max(0, max(ml2 - mr1, ml1 - mr2)) << endl;
    return 0;
}