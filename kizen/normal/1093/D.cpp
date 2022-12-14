#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int NS = (int)3e5+4, MOD = 998244353;
int T;
int N, M;
vector < int > way[NS];
vector < LL > number;
int col[NS], cnt[4], flag;

void dfs(int num, int far){
    col[num] = far, ++cnt[far];
    for(int i=0;i<(int)way[num].size();++i){
        if(col[way[num][i]]){
            if(col[way[num][i]]==far) flag = 1;
        }
        else{
            dfs(way[num][i], 3-far);
        }
    }
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i=0;i<M;++i){
            int a, b; scanf("%d %d", &a, &b);
            way[a].push_back(b), way[b].push_back(a);
        }
        flag = 0;
        number.clear();
        LL ans;
        for(int i=1;i<=N;++i) if(!col[i]){
            cnt[1] = cnt[2] = 0;
            dfs(i, 1);
            ans = 0;
            int val = 1;
            for(int j=1;j<=cnt[1];++j) val = val*2%MOD;
            ans = (ans+val)%MOD;
            val = 1;
            for(int j=1;j<=cnt[2];++j) val = val*2%MOD;
            ans = (ans+val)%MOD;
            number.push_back(ans);
        }
        ans = 1;
        for(int i=0;i<(int)number.size();++i) ans = ans*number[i]%MOD;
        if(!flag) printf("%lld\n", ans);
        else puts("0");
        for(int i=0;i<=N;++i) way[i].clear(), col[i] = 0;
    }
    return 0;
}