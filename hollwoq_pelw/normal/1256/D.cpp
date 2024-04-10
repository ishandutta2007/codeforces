#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long l = -1, r = -1;
    for (long long i = 0; i < n; i++){
        if (s[i] == '0'){
            if (l == -1 && r == -1) continue;
            long long t = max(l, r-k);
            swap(s[t],s[r]);
            // cout << t << ' ' << r << endl;
            l = t+1; r ++;
            k -= r-l;
        }else{
            if (l == -1 && r == -1){
                l = i;
                r = i+1;
            }else {
                r ++;
            }
        }
    }
    cout << s << endl;
}
int main(){
    int q; cin >> q;
    while(q--) solve();
    return 0;
}