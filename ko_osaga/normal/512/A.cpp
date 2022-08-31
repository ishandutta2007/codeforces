#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int vis[26];
int n;
int adj[26][26];
int adj2[26][26];

char str[105][105];
int l[105];
vector<int> ord;

void dfs(int x){
    vis[x] = 1;
    for(int i=0; i<26; i++){
        if(adj[x][i] == 1 && !vis[i]) dfs(i);
    }
    ord.push_back(x);
}

int main(){
    memset(adj,0x3f,sizeof(adj));
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%s",str[i]);
    }
    for (int i=0; i<n-1; i++) {
        int p = 0;
        while (str[i][p] == str[i+1][p]) {
            p++;
        }
        if(str[i][p] == 0 && str[i+1][p] == 0) continue;
        if(str[i][p] == 0 && str[i+1][p]) continue;
        if(str[i][p] && str[i+1][p] == 0){
            puts("Impossible");
            return 0;
        }
        adj[str[i+1][p] - 'a'][str[i][p] - 'a'] = 1;
    }
    memcpy(adj2,adj,sizeof(adj));
    for (int i=0; i<26; i++) {
        for (int j=0; j<26; j++) {
            for (int k=0; k<26; k++) {
                adj2[j][k] = min(adj2[j][k],adj2[j][i] + adj2[i][k]);
            }
        }
    }
    for (int i=0; i<26; i++) {
        if(adj2[i][i] < 1e8){
            puts("Impossible"); // no cycle assertion
            return 0;
        }
    }
    for (int i=0; i<26; i++) {
        if(!vis[i]) dfs(i);
    }
    for (int i=0; i<ord.size(); i++) {
        putchar(ord[i] + 'a');
    }
}