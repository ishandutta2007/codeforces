#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int gde[100005];
int res;
vector <int> graf[100005];

void dfs(int v, int p){
    for(auto c : graf[v]){
        if(c == p) continue;
        dfs(c, v);
        if(gde[c] == c){
            res += 2;
            swap(gde[v], gde[c]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
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
    for(int i=1; i<=n; i++) gde[i] = i;
    dfs(1, 0);
    if(gde[1] == 1){
        res += 2;
        swap(gde[1], gde[graf[1][0]]);
    }
    cout << res << "\n";
    for(int i=1; i<=n; i++) cout << gde[i] << " ";
    return 0;
}