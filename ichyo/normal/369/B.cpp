#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, k, l, r, sa, sk;
    while(cin >> n >> k >> l >> r >> sa >> sk){
        // 0..k-1, k..n
        vector<int> ans;
        int a = sk / k;
        REP(iter, sk % k) ans.push_back(a + 1);
        REP(iter, k - sk % k) ans.push_back(a);
        sk = sa - sk;
        k = n - k;
        if(k > 0){
            a = sk / k;
            REP(iter, sk % k) ans.push_back(a + 1);
            REP(iter, k - sk % k) ans.push_back(a);
        }
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i == ans.size() - 1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}