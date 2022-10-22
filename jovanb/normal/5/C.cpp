#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 1000000;

int levo[MAXN+5];
int res[MAXN+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    stack <int> st;
    int n = s.size();
    for(int i=1; i<=n; i++){
        if(s[i-1] == ')'){
            if(st.empty()) continue;
            levo[i] = st.top();
            st.pop();
        }
        else st.push(i);
    }
    for(int i=1; i<=n; i++){
        if(levo[i]){
            res[i] = levo[i];
            if(levo[levo[i]-1]) res[i] = res[levo[i]-1];
        }
    }
    int cnt = 0, mx = 0;
    //for(int i=1; i<=n; i++) cout << res[i] << " ";
    for(int i=1; i<=n; i++) if(res[i]) mx = max(mx, i-res[i]+1);
    for(int i=1; i<=n; i++) if(res[i] && i-res[i]+1 == mx) cnt++;
    if(mx == 0){
        cout << "0 1\n";
        return 0;
    }
    cout << mx << " " << cnt;
    return 0;
}