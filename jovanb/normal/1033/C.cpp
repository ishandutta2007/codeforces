#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int win[100005];
vector <int> graf[100005];
bool visited[100005];
int niz[100005];

void dfs(int v){
    visited[v] = 1;
    for(auto c : graf[v]){
        if(!visited[c]) dfs(c);
        if(!win[c]) win[v] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<=n; i++){
        int x = niz[i];
        for(int j=i+x; j<=n; j+=x){
            if(niz[j] > niz[i]) graf[i].push_back(j);
        }
        for(int j=i-x; j>=1; j-=x){
            if(niz[j] > niz[i]) graf[i].push_back(j);
        }
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i);
    }
    for(int i=1; i<=n; i++){
        if(win[i]) cout << "A";
        else cout << "B";
    }
    return 0;
}