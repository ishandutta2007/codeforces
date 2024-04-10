#include <bits/stdc++.h>
using namespace std;

const long N = 100005;

long k;

bool ima[N];
bool touch[N];
bool moze[N];

vector <long> temp[N];
vector <long> drvo[N];
long br[N];

void zasadi(long v){
    touch[v] = 1;
    for(auto c : temp[v]){
        if(!touch[c]){
            drvo[v].push_back(c);
            touch[c] = 1;
            zasadi(c);
        }

    }
}

void dfs(long v){
    if(ima[v]) br[v]++;
    else br[v] = 0;
    if(br[v] > k) return;
    moze[v] = 1;
    for(auto c : drvo[v]){
        br[c] = br[v];
        dfs(c);
    }
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n, x, y, bro=0;
    cin >> n >> k;
    for(long i=1; i<=n; i++) cin >> ima[i];
    for(long i=1; i<n; i++){
        cin >> x >> y;
        temp[x].push_back(y);
        temp[y].push_back(x);
    }
    zasadi(1);
    dfs(1);
    for(long i=1; i<=n; i++) if(drvo[i].empty()) bro += moze[i];
    cout << bro << endl;
    return 0;
}