#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, sz[200010], one, ans;
int p[200010];
bool chk[200010];
vector<int> cyc[200010], tc;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", p + i);
    }
    for(int i = 1; i <= n; i++){
        if(chk[i]) continue;
        int t = i; c++;
        vector<int>().swap(tc);
        while(!chk[t]){
            chk[t] = true;
            tc.push_back(t);
            t = p[t];
        }
        int st;
        for(st = 0; st < tc.size(); st++){
            if(tc[st] == t) break;
        }
        for(; st < tc.size(); st++){
            sz[c]++;
            cyc[c].push_back(tc[st]);
        }
        if(sz[c] == 0) c--;
    }
    for(int i = 1; i <= c; i++){
        if(sz[i] == 1){
            one = i;
            break;
        }
    }
    if(!one){
        p[cyc[1][0]] = cyc[1][0];
        one = 1;
        ans = 1;
    }
    for(int i = 1; i <= c; i++){
        if(i == one) continue;
        p[cyc[i][0]] = cyc[one][0];
    }
    ans += c - 1;
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++) printf("%d ", p[i]);
}