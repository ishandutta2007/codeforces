#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++){
        int idx;
        cin >> idx;
        ans[idx - 1] = i + 1;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i];
        if(i == n - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}