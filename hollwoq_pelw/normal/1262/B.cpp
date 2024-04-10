#include <bits/stdc++.h> 
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<int> poss;
        for (int i = 0; i < n; i++) poss.insert(i + 1);
        vector<int> ans, a(n);
        int cur = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (auto x:a){
            if (x > cur){
                if (!poss.count(x)) {
                    ok = false;
                    break;
                }
                ans.push_back(x);
                poss.erase(x);
                cur = x;
            } else {
                int v = *poss.begin();
                if (v <= x) {
                    ans.push_back(v);
                    poss.erase(v);
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            cout << -1 << "\n";
        } else {
            for (int i : ans) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}