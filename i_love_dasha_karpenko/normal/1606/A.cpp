#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e3+7;
void solve(){
    string s;
    cin>>s;
    int len = s.length();
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1;i<len;++i){
        if (s[i-1]=='a' && s[i]=='b')
            ++cnt1;
        if (s[i-1]=='b' && s[i]=='a')
            ++cnt2;
    }
    if (cnt1!=cnt2){
        s[0] = s[0]=='a'?'b':'a';
    }
   // assert(cnt1==cnt2);
    cout<<s<<endl;
}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}