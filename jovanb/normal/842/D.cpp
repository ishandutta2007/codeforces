#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int vecbio[300005];
int nxt[5000005][2];
int br[5000005];

int tcnt;

int sv;

void trieadd(int x){
    int tr = 0;
    br[0]++;
    for(int j=19; j>=0; j--){
        if((1 << j) & x){
            if(!nxt[tr][1]) nxt[tr][1] = ++tcnt;
            tr = nxt[tr][1];
        }
        else{
            if(!nxt[tr][0]) nxt[tr][0] = ++tcnt;
            tr = nxt[tr][0];
        }
        br[tr]++;
    }
}

int kveri(){
    int res = 0;
    int tr = 0;
    for(int j=19; j>=0; j--){
        if((1 << j) & sv){
            if(!nxt[tr][1]){
                nxt[tr][1] = ++tcnt;
                tr = nxt[tr][1];
                res ^= (1 << j);
            }
            else if(br[nxt[tr][1]] == (1 << j)){
                tr = nxt[tr][0];
            }
            else{
                tr = nxt[tr][1];
                res ^= (1 << j);
            }
        }
        else{
            if(!nxt[tr][0]){
                nxt[tr][0] = ++tcnt;
                tr = nxt[tr][0];
            }
            else if(!nxt[tr][0] || br[nxt[tr][0]] == (1 << j)){
                tr = nxt[tr][1];
                res ^= (1 << j);
            }
            else{
                tr = nxt[tr][0];
            }
        }
    }
    return res ^ sv;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(vecbio[x]) continue;
        vecbio[x] = 1;
        trieadd(x);
    }
    while(m--){
        int x;
        cin >> x;
        sv ^= x;
        cout << kveri() << "\n";
    }
    return 0;
}