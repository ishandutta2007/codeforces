#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n; int a[maxN]; bool chk[maxN];
// rice is villager

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}

int room[maxN] = {0}; int big[maxN] = {0};
vector<int> chi[maxN]; int rice[maxN] = {0};

void dfs(int node){
    if(chi[node].size() == 0){
        big[node] = rice[node]; room[node] = 1; return; // total is rice
    }
    int maxrice = 0; room[node] = 0; big[node] = 0;
    // update rice node in progress
    for(int j = 0; j < chi[node].size(); j++){
        dfs(chi[node][j]);
        int kk = chi[node][j];
        maxrice = max(maxrice, big[kk]);
        rice[node] += rice[kk]; room[node] += room[kk];
    }
    big[node] = maxrice;
    // only see rice[node], room[node] and big[node] now
    if(big[node] * room[node] < rice[node]){
        big[node] = (rice[node] - 1) / room[node] + 1; /// change some wckign thing here
    }
    else{
        // bruh no rice left
    }
    
    // chi[node][j] is, uh, the goddamn long and big CHILD NAME
    
    
}

signed main(){
    ios_base::sync_with_stdio(0); int x = 0;
    cin >> n; for(int i = 2; i <= n; i++){
        cin >> x; chi[x].pb(i); // insert city child
    }
    for(int i = 1; i <= n; i++){
        cin >> rice[i]; // insert population
    }
    typre();
    
    dfs(1);
    
    cout << big[1];
    // from node i to all chi[i][all]:
    // spread rice :: ))
    // if all rice spread: spread the largest first
    // if there's stil rice left: 
    
}