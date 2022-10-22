#include <bits/stdc++.h>
using namespace std;

bool lose = true;
int par[200005];
vector <int> graf[200005];
vector <int> graf1[200005];
vector <int> moze;
bool visited[200005];
stack <int> stek;
bool usteku[200005];

void dfs(int v){
    visited[v] = true;
    for(auto c : graf[v]){
        if(!visited[c]){
            par[c] = v;
            dfs(c);
        }
    }
}

void topsort(int v){
    if(lose == false) return;
    stek.push(v);
    usteku[v] = true;
    for(auto c : graf[v]){
        if(usteku[c] == true){lose = false; return;}
        topsort(c);
    }
    stek.pop();
    usteku[v] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int n, m, j, x;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> x;
        if(x == 0) moze.push_back(i);
        while(x--){
            cin >> j;
            graf1[i].push_back(j);
            graf[i].push_back(j+n);
            graf[i+n].push_back(j);
        }
    }
    int poc;
    cin >> poc;
    dfs(poc+n);
    for(auto c : moze){
        if(visited[c]){
            cout << "Win\n";
            stack <int> stek;
            int x = c;
            while(1){
                if(x > n) stek.push(x-n);
                else stek.push(x);
                if(x == poc+n) break;
                x = par[x];
            }
            while(!stek.empty()){
                cout << stek.top() << " ";
                stek.pop();
            }
            return 0;
        }
    }
    topsort(poc);
    if(lose == false) cout << "Draw";
    else cout << "Lose";
    return 0;
}