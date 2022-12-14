#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)1e5 + 4;
int T, N, M, k;
vector<int> way[NS];
int cnt[NS], chk[NS];
priority_queue<pair<int, int>> pq;
vector<vector<int>> cli;
vector<int> cnum[NS];
vector<int> ncli;
int can[NS];
int near[NS];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &N, &M, &k);
        for(int i = 1, a, b; i <= M; ++i){
            scanf("%d %d", &a, &b);
            way[a].push_back(b), way[b].push_back(a);
            ++cnt[a], ++cnt[b];
        }
        while(!pq.empty()){
            pq.pop();
        }
        for(int i = 1; i <= N; ++i){
            pq.push({-cnt[i], i});
        }
        int one = 0;
        while(!pq.empty()){
            while(!pq.empty() && chk[pq.top().second]){
                pq.pop();
            }
            if(pq.empty()){
                break;
            }
            int num = pq.top().second; pq.pop();
            chk[num] = 1;
            if(cnt[num] < k - 1){
                for(auto&nxt:way[num]){
                    if(chk[nxt]){
                        continue;
                    }
                    --cnt[nxt];
                    pq.push({-cnt[nxt], nxt});
                }
            }
            else if(cnt[num] == k - 1){
                ncli = {num};
                int nnum = (int)cli.size();
                can[nnum] = 1;
                for(auto&nxt:way[num]){
                    if(chk[nxt]){
                        continue;
                    }
                    --cnt[nxt];
                    pq.push({-cnt[nxt], nxt});
                    ncli.push_back(nxt);
                    cnum[nxt].push_back(nnum);
                }
                cli.push_back(ncli);
            }
            else{
                one = 1;
                int acnt = 1;
                for(int i = 1; i <= N; ++i){
                    acnt += !chk[i];
                }
                printf("1 %d\n", acnt);
                printf("%d ", num);
                for(int i = 1; i <= N; ++i){
                    if(!chk[i]){
                        printf("%d ", i);
                    }
                }
                puts("");
                break;
            }
        }
        if(!one){
            for(int i = 1; i <= N; ++i){
                for(auto&nxt:way[i]){
                    near[nxt] = 1;
                }
                for(auto&j:cnum[i]){
                    for(auto&x:cli[j]){
                        if(!near[x] && x != i){
                            can[j] = 0;
                            break;
                        }
                    }
                }
                for(auto&nxt:way[i]){
                    near[nxt] = 0;
                }
            }
            for(int i = 0; i < (int)cli.size(); ++i){
                if(can[i]){
                    puts("2");
                    for(auto&j:cli[i]){
                        printf("%d ", j);
                    }
                    puts("");
                    one = 1;
                    break;
                }
            }
        }
        if(!one){
            puts("-1");
        }
        for(int i = 1; i <= N; ++i){
            way[i].clear();
            cnt[i] = chk[i] = 0;
            cnum[i].clear();
        }
        cli.clear();
    }
    return 0;
}