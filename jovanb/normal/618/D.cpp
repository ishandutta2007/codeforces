#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll len=1;
int deg[200005];
ll d[200005];
bool visited[200005];
bool treba[200005];
vector <int> graf[200005];
ll br;

void dfs(int v){
    visited[v] = 1;
    int brt=2;
    for(auto c : graf[v]){
        if(!visited[c]){
            dfs(c);
            if(treba[c] && brt){
                brt--;
                br++;
            }
        }
    }
    if(brt) treba[v] = 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    if(x < y){
        dfs(1);
        cout << x*br+y*(n-1-br);
        return 0;
    }
    for(int i=1; i<=n; i++){
        if(deg[i] == n-1){cout << (n-2)*y+x; return 0;}
    }
    cout << (n-1)*y;
    return 0;
}