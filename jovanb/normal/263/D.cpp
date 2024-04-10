#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int pos[100005];
int niz[100005];
int cnt;
vector <int> graf[100005];

int n, m, k;

void output(int l, int r){
    cout << r-l+1 << "\n";
    for(int i=l; i<=r; i++) cout << niz[i] << " ";
    exit(0);
}

void dfs(int v){
    niz[++cnt] = v;
    pos[v] = cnt;
    for(auto c : graf[v]){
        if(pos[c]){
            if(pos[v]-pos[c]+1 > k) output(pos[c], pos[v]);
        }
    }
    for(auto c : graf[v]){
        if(!pos[c]){
            dfs(c);
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n >> m >> k;
    while(m--){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1);
    return 0;
}