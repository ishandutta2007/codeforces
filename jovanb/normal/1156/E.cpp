#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

vector <int> vec[N+5];

int a[N+5], lb[N+5], rb[N+5];

int vcount(int l, int r, int x){
    if(x < 0) return 0;
    return lower_bound(vec[x].begin(), vec[x].end(), r + 1) - lower_bound(vec[x].begin(), vec[x].end(), l);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        vec[a[i]].push_back(i);
    }
    stack <int> st;
    for(int i=1; i<=n; i++){
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        if(!st.empty()) lb[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n; i>=1; i--){
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        if(!st.empty()) rb[i] = st.top();
        else rb[i] = n + 1;
        st.push(i);
    }
    ll res = 0;
    for(int i=1; i<=n; i++){
        int l = lb[i] + 1, r = rb[i] - 1;
        if(r - i < i - l){
            for(int j=i+1; j<=r; j++){
                res += vcount(l, i - 1, a[i] - a[j]);
            }
        }
        else{
            for(int j=l; j<=i-1; j++){
                res += vcount(i + 1, r, a[i] - a[j]);
            }
        }
    }
    cout << res << "\n";
    return 0;
}