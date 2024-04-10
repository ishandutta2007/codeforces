#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> graf[200005];

int x, y;

void dfs(int v, int par, int col){
    if(col == 0) x++;
    else y++;
    for(auto c : graf[v]){
        if(c != par) dfs(c, v, 1-col);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0, 0);
    cout << min(x, y) - 1;
    return 0;
}