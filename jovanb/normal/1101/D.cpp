#include <bits/stdc++.h>
using namespace std;

bool prime[200005];
int niz[200005];
vector <int> graf[200005];
vector <int> divisors[200005];
unordered_map <int, int> dole[200005];
int res;

void dfs(int v, int parent){
    for(auto c : graf[v]){
        if(c == parent) continue;
        dfs(c, v);
    }
    for(auto x : divisors[niz[v]]){
        //cout << v << " " << x << " ";
        vector <int> vec;
        int a=-1, b=-1;
        for(auto c : graf[v]){
            if(c == parent) continue;
            if(niz[c]%x == 0){
                int r = dole[c][x];
                if(r > b){
                    a = b;
                    b = r;
                }
                else if(r > a) a = r;
            }
        }
        //cout << a << " " << b << endl;
        if(b == -1){
            res = max(res, 1);
            dole[v][x] = 1;
        }
        else if(a == -1){
            res = max(res, b+1);
            dole[v][x] = b+1;
        }
        else{
            res = max(res, a+b+1);
            dole[v][x] = b+1;
        }
        //cout << dole[v][x] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cerr.tie(0);
    cout.tie(0);

    for(int i=2; i<=200000; i++){
        prime[i] = 1;
    }
    for(int i=2; i<=200000; i++){
        if(!prime[i]) continue;
        for(int j=i; j<=200000; j+=i){
            prime[j] = 0;
            divisors[j].push_back(i);
        }
    }
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
    dfs(1, 0);
    cout << res;
    return 0;
}