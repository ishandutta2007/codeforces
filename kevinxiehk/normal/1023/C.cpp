#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    stack<char> sth;
    int diff = n - k;
    for(int i = 0; i < n; i++) {
        if(!sth.empty()) {
            if(sth.top() == '(' && s[i] == ')' && diff > 0) {
                diff -= 2;
                sth.pop();
                //cout << i << '\n';
            } 
            else sth.push(s[i]);
        }
        else sth.push(s[i]);
    }
    string ans = "";
    while(!sth.empty()) {
        //cout << sth.top() << ' ';
        ans += sth.top();
        sth.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    //cin>>t;
    t=1;

    while(t--)solve();
    return 0;
}