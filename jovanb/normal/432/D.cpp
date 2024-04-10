#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int res[100005];
int br[100005];
int sol[100005];
bool visited[100005];
vector <int> graf[100005];

void dfs(int v){
    visited[v] = 1;
    sol[v] += br[v];
    for(auto c : graf[v]){
        if(!visited[c]){
            dfs(c);
            sol[v] += sol[c];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    int n = s.size();
    int len=0;
    int x=1;
    res[0] = 0;
    res[1] = 0;
    while(x < n){
        if(s[x] == s[len]){
            len++;
            res[x+1] = len;
            x++;
            br[len]++;
        }
        else if(len){
            len = res[len];
        }
        else res[++x] = 0;
    }
    for(int i=1; i<=n; i++){
        graf[res[i]].push_back(i);
    }
    for(int i=0; i<=n; i++){
        if(!visited[i]) dfs(i);
    }
    x = n;
    stack <int> stek;
    while(x){
        stek.push(x);
        x = res[x];
    }
    cout << stek.size() << "\n";
    while(!stek.empty()){
        cout << stek.top() << " " << sol[stek.top()]+1 << "\n";
        stek.pop();
    }
    return 0;
}