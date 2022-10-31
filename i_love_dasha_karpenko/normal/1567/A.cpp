//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gt(tuple,el) (get<el>(tuple))
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    for(int i = 0;i<n;++i){
        if (s[i]=='L' || s[i]=='R')
            cout<<s[i];
        else{
            if (s[i]=='U')
                cout<<'D';
            else cout<<'U';
        }
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}