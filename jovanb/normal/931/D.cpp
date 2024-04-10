#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <int> graf[100005];
int brh[100005];

void dfs(int v, int h){
    brh[h]++;
    for(auto c : graf[v]) dfs(c, h+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, x;
    cin >> n;
    for(int i=2; i<=n; i++){
        cin >> x;
        graf[x].push_back(i);
    }
    dfs(1,1);
    x=0;
    for(int i=1; i<=n; i++){
        if(brh[i]%2 == 1) x++;
    }
    cout << x;
    return 0;
}