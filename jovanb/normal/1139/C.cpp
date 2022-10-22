#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;
int cnt;

int add(int a, int b){
    return(0LL+a+b+MOD)%MOD;
}

int mul(int a, int b){
    return(1LL*a*b)%MOD;
}

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

bool visited[100005];
vector <int> graf[100005];

void dfs(int v){
    visited[v] = 1;
    cnt++;
    for(auto c : graf[v]){
        if(!visited[c]) dfs(c);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    int sol = pw(n, k);
    for(int i=1; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(!c){
            graf[a].push_back(b);
            graf[b].push_back(a);
        }
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt = 0;
            dfs(i);
            sol = add(sol, -pw(cnt, k));
        }
    }
    cout << sol << "\n";
    return 0;
}