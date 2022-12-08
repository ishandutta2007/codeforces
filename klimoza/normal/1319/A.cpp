#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

//#define int long long

typedef long long ll;

using namespace std;

void solve();
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cout.precision(15); cout << fixed;
    solve();
    return 0;
}

void solve(){
    int n; cin >> n;
    vector<int> r(n), b(n);
    for(int i = 0 ; i < n; i++)
        cin >> r[i];
    for(int i= 0 ;i < n; i++)
        cin >> b[i];
    bool fl = false;
    for(int i = 0; i < n; i++){
        if(r[i] && !b[i]){
            fl = true;
            break;
        }
    }
    if(!fl){
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i <= 2000; i++){
        int tmp = 0;
        for(int j = 0; j < n; j++){
            if(b[j] && r[j]) continue;
            if(!b[j] && !r[j]) continue;
            if(r[j]) tmp += i;
            else tmp--;
        }
        if(tmp > 0){
            cout << i << endl;
            break;
        }
    }
}