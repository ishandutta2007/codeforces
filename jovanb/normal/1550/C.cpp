#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 200000;

int a[MAXN+5];

int pl[MAXN+5];
int pd[MAXN+5];
int moze[MAXN+5];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    stack <int> st;
    for(int i=1; i<=n; i++){
        pl[i] = 0;
        pd[i] = n+1;
        moze[i] = 0;
    }
    for(int i=1; i<=n; i++){
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        if(!st.empty()) pl[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n; i>=1; i--){
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        if(!st.empty()){
            pd[i] = st.top();
            moze[pd[i]] = max(moze[pd[i]], pl[i]+1);
        }
        st.push(i);
    }
    for(int i=1; i<=n; i++){
        pl[i] = 0;
        pd[i] = n+1;
    }
    while(!st.empty()) st.pop();
    for(int i=1; i<=n; i++){
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        if(!st.empty()) pl[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n; i>=1; i--){
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        if(!st.empty()){
            pd[i] = st.top();
            moze[pd[i]] = max(moze[pd[i]], pl[i]+1);
        }
        st.push(i);
    }
    ll res = 0;
    int j = 1;
    for(int i=1; i<=n; i++){
        while(j+1 <= n && moze[j+1] <= i) j++;
        res += j-i+1;
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}