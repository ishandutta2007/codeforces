
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e6+7;
string s;
int cnt[N][2];
void solve(){
    cin>>s;
    int n = s.length();
    for(int i = 1;i<=n;++i){
        for(int c = 0;c<2;++c)
            cnt[i][c]=cnt[i-1][c];
        if (s[i-1]=='[' || s[i-1]==']')
            ++cnt[i][i&1];
    }
    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        int c1 = cnt[r][0]-cnt[l-1][0],c2 = cnt[r][1]-cnt[l-1][1];
        int delta = abs(c1-c2);
        cout<<delta<<endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();


    return 0;
}