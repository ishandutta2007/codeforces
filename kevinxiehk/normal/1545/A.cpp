#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n;
    cin >> n;
    int arr[n + 5];
    int arr2[n + 5];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    vector<int> a, aa, b, bb;
    sort(arr2, arr2 + n);
    for(int i = 0; i < n; i++) {
        if(i % 2) {
            a.pb(arr[i]);
            aa.pb(arr2[i]);
        }
        else{
            b.pb(arr[i]);
            bb.pb(arr2[i]);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != aa[i]) {
            cout << "NO\n";
            return;
        }
    }
    for(int i = 0; i < b.size(); i++) {
        if(b[i] != bb[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    cin >> t;
    
    while(t--) solve();
    return 0;
}