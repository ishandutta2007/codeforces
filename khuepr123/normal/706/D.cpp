#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;

struct makeTrie{
    int occ;
    int final;
    int child[2];
}
;
struct makeTrie trie[6400005];
int triesize = 0;
int sizer = 0;

void init(int u){
    trie[u].child[0] = -1;
    trie[u].child[1] = -1;
    trie[u].final = 0;
    trie[u].occ = 0;
}

void push(bitset<30> bt){
    int p = 0;
    sizer++;
    for(int i = 29; i > -1; i--){
        if(trie[p].child[bt[i]] == -1){
            init(++triesize);
            trie[p].child[bt[i]] = triesize;
        }
        p = trie[p].child[bt[i]];
        trie[p].occ++;
    }
    trie[p].final++;
}

void dele(bitset<30> bt){
    sizer--;
    int p = 0;
    for(int i = 29; i > -1; i--){
        p = trie[p].child[bt[i]];
        trie[p].occ--;
    }
    trie[p].final--;
}
int n;
int a[maxN];

void dfs(int u, string s){
    cout << s << " " << trie[u].occ << endl;
    for(int i = 0; i < 2; i++){
        if(trie[u].child[i] == -1) continue;
        dfs(trie[u].child[i], s + char(i + '0'));
    }
}

int search(bitset<30> xorer){
    int p = 0;
    int ans = (1 << 30) - 1;
    for(int i = 29; i > -1; i--){
        bool g = !xorer[i];
        if(trie[p].child[g] == -1 || trie[trie[p].child[g]].occ == 0){
            g = !g;
            ans -= (1 << i);
        }
        p = trie[p].child[g];
    }
    return ans;
}
char c;

signed main(){
    init(0);
    int o; cin >> o;
    push(bitset<30>(0));
    while(o--){
        int ans;
        cin >> c >> ans;
        bitset<30> hh(ans);
        if(c == '+'){
            push(hh);
        }
        else if(c == '-'){
            dele(hh);
        }
        else{
            if(sizer == 0){
                cout << ans << endl; continue;
            }
            bitset<30> hh(ans);
            cout << search(hh) << endl;
        }
    }
    
    
}