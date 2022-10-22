#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<vector<int>> a;
int n, m, ans1, ans2;

bool check(int x){
    vector<int> mask(1 << m, -1);
    for (int i = 0; i < n; i++){
        int msk = 0;
        for (int j = 0; j < m; j++){
            if (a[i][j] >= x) 
                msk ^= (1 << j);
        }
        mask[msk] = i + 1;
    }
    if (mask[(1 << m) - 1] != -1){
        ans1 = ans2 = mask[(1 << m) - 1];
        return true;
    }
    //cout << "\nDEBUG: " << x << endl;
    for (int i = 0; i < (1 << m); i ++){
    //    cout << mask[i] << ' ';
        for (int j = i + 1; j < (1 << m); j ++){
            if (mask[i] != -1 && mask[j] != -1 && (i | j) == (1 << m) - 1){
                ans1 = mask[i];
                ans2 = mask[j];
                return true;
            }
        }
    }
    return false;
}

signed main(){
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int lb = 0, rb = 1e9 + 7;
    while (lb + 1 < rb){
        int mb = (lb + rb) >> 1;
        if(check(mb))
            lb = mb;
        else
            rb = mb;
    }
    check(lb);
    cout << ans1 << ' ' << ans2;
    
}