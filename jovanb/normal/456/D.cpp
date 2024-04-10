#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool win[1000005];
bool lose[1000005];
int nxt[1000005][26];

int cnt;

void trieadd(string s){
    int n = s.size();
    int tren=0;
    for(int i=0; i<n; i++){
        int c = s[i]-'a';
        if(!nxt[tren][c]) nxt[tren][c] = ++cnt;
        tren = nxt[tren][c];
    }
}

void dfs(int v){
    bool leaf=1;
    for(int i=0; i<26; i++){
        if(!nxt[v][i]) continue;
        leaf=0;
        int c = nxt[v][i];
        dfs(c);
        win[v] = win[v] | (1 ^ win[c]);
        lose[v] = lose[v] | (1 ^ lose[c]);
    }
    if(leaf) lose[v] = 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        trieadd(s);
    }
    dfs(0);
    if(!win[0]) cout << "Second";
    else if(lose[0]) cout << "First";
    else if(k%2) cout << "First";
    else cout << "Second";
    return 0;
}