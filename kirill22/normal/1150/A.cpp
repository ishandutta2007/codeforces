#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD =1e9 + 7;
signed main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    for(int i=0;i<m;i++){
        cin >>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int x = 0;
    int ii=0;
    while(k > 0 && ii < n){
        if(a[ii] > b[m-1]){
            break;
        }
        x += k / a[ii];
        k -= (k / a[ii]) * a[ii];
        ii++;
    }
    cout << b[m - 1] * x + k;
}