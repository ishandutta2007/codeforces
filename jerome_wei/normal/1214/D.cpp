#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+5;
int N,M,A[MN],num,ans,vis[MN];
char c;
vector<int> G[MN];
bool succ;
void DFS(int x)
{
    if(x==N*M) succ = true;
    if(succ) return;
    vis[x] = 1;
    for(int r: G[x]) if(!vis[r]) DFS(r);
}
 
int main()
{
    cin >> N >> M;
    for(int i=1 ;i<=N; i++){
        for(int j=1; j<=M; j++){
            num++;
            cin >> c;
            if(c=='.'){
                A[num] = 1;
                if(i!=1) G[num-M].push_back(num);
                if(j!=1) G[num-1].push_back(num);
            }
        }
    }
    DFS(1);
    if(succ){
        succ = false;
        DFS(1);
        if(succ) cout << 2;
        else cout << 1;
    }
    else cout << 0;
}