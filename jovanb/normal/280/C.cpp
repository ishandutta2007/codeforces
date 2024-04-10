#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld rez;

vector <int> graf[100005];

void dfs(int v, int par, int depth){
    rez += 1.0/depth;
    for(auto c : graf[v]){
        if(c != par) dfs(c, v, depth+1);
    }
}

int main(){

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
    dfs(1, 0, 1);
    cout << rez;
    return 0;
}