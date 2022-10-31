#include <bits/stdc++.h>

using namespace std;
typedef long long big;
const int DIM = 4E5+7;
char get_ch(int a){
    return char('a'+a-1);
}
void solve(){
    string s;
    cin>>s;
    int l = 0,r = s.length()-1;
    int flag = 0,cur = s.length();
    while(l<=r){
        if (get_ch(cur)==s[l]){
            --cur;
            ++l;
        }
        else if (get_ch(cur)==s[r]){
            --cur;
            --r;
        }
        else{
            flag = 1;
            break;
        }
    }
    if (flag)
        cout<<"NO\n";
    else cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}