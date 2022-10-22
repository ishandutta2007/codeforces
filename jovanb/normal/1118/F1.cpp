#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> graf[300005];
int col[300005];
int bn[300005];
int rn[300005];

int b, r;

int cnt;

void dfs(int v, int par){
    for(auto c : graf[v]){
        if(c != par){
            dfs(c, v);
            bn[v] += bn[c];
            rn[v] += rn[c];
        }
    }
    if(col[v] == 1) rn[v]++;
    if(col[v] == 2) bn[v]++;
    if(bn[v] && rn[v]) return;
    if(b-bn[v] && r-rn[v]) return;
    cnt++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> col[i];
        if(col[i] == 2) b++;
        if(col[i] == 1) r++;
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    cout << cnt;
    return 0;
}