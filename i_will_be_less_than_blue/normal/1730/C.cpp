
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=300010;
int have[10];
int cnt[10];
void solve(){
    string s;cin>>s;
    memset(cnt,0,sizeof(cnt));
    memset(have,0,sizeof(have));
    for (auto i:s){
        cnt[i-'0']++;
    }
    string ans="";
    for (int i=0;i<s.size();i++){
        int mn=0;
        while (have[mn]+cnt[mn]==0) mn++;
        if (s[i]-'0'==mn){
            ans+=char(mn+'0');
            cnt[mn]--;
            continue;
        }
        if (cnt[mn]){
            have[min(s[i]-'0'+1,9)]++;
            cnt[s[i]-'0']--;
            continue;
        }
        ans+=char(mn+'0');
        have[mn]--;
        i--;
    }
    for (int i=0;i<10;i++){
        for (int j=0;j<have[i];j++) ans+=char(i+'0');
    }
    cout<<ans<<'\n';



}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}