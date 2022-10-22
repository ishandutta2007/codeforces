#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int s;
ll niz[100005];
ll dp1[100005];
ll dp2[100005];
vector <int> graf[100005];

void dfs(int v, int par){
    ll cnt=0;
    vector <ll> vec;
    if(v != s) niz[v]--;
    for(auto c : graf[v]){
        if(c == par) continue;
        dfs(c, v);
        cnt += dp2[c];
        if(dp1[c] >= 2) vec.push_back(dp1[c]);
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for(auto c : vec){
        if(niz[v]){
            niz[v]--;
            dp1[v] += c+1;
        }
    }
    dp1[v] += 2*min(cnt, niz[v]);
    dp2[v] = niz[v]-min(cnt, niz[v]);
    if(!dp1[v]) dp2[v]++;
    else if(v != s) dp1[v]++;
   // cout << v << " " << dp1[v] << " " << dp2[v] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    cin >> s;
    dfs(s, 0);
    cout << dp1[s];
    return 0;
}