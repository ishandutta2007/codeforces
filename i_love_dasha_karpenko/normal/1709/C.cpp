//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll

void solve(){
    string A;
    cin>>A;
    int n = A.length();
    int total = 0;
    for(char to:A){
        total += to=='(';
    }
    bool flag = 0;
    int cnt = 0;
    bool pt = 0;
    for(int to:A){
        if (to=='?'){
            if (total*2<n){
                if (flag==0 && (total+1)*2==n){
                    flag = 1;
                    pt = 1;
                    to = ')';
                }
                else{
                    total += 1;
                    to = '(';
                }
            }
            else{
                to = ')';
            }
        }
        cnt += to=='('?1:-1;
        if (cnt<0){
            cout<<"YES\n";
            return;
        }
    }
    if (pt==0){
        cout<<"YES\n";
    }
    else {
        cout << "NO\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}