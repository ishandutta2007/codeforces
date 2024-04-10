#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
struct Edge{
    int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , dep[MAXN] , jump[MAXN][20] , sum[MAXN] , cntEd , N , K;

inline void addEd(int a , int b){
    Ed[++cntEd].end = b;
    Ed[cntEd].upEd = head[a];
    head[a] = cntEd;
}

void dfs(int now , int fa){
    dep[now] = dep[fa] + 1;
    jump[now][0] = fa;
    for(int i = 1 ; i < 20 ; i++)
        jump[now][i] = jump[jump[now][i - 1]][i - 1];
    for(int i = head[now] ; i ; i = Ed[i].upEd)
        if(Ed[i].end != fa)
            dfs(Ed[i].end , now);
}

inline int jumpToLCA(int x , int y){
    if(dep[x] < dep[y])
        swap(x , y);
    for(int i = 19 ; i >= 0 ; i--)
        if(dep[x] - (1 << i) >= dep[y])
            x = jump[x][i];
    if(x == y)
        return x;
    for(int i = 19 ; i >= 0 ; i--)
        if(jump[x][i] != jump[y][i]){
            x = jump[x][i];
            y = jump[y][i];
        }
    return jump[x][0];
}

void Dfs(int now){
    for(int i = head[now] ; i ; i = Ed[i].upEd)
        if(Ed[i].end != jump[now][0]){
            Dfs(Ed[i].end);
            sum[now] += sum[Ed[i].end];
        }
}

int main(){
    cin >> N;
    for(int i = 1 ; i < N ; i++){
        int a , b;
        cin >> a >> b;
        addEd(a , b);
        addEd(b , a);
    }
    dfs(1 , 0);
    for(cin >> K ; K ; K--){
        int a , b , t;
        cin >> a >> b;
        t = jumpToLCA(a , b);
        sum[a]++;
        sum[b]++;
        sum[t] -= 2;
    }
    Dfs(1);
    for(int i = 1 ; i < N ; i++)
        printf("%d " , dep[Ed[i << 1].end] > dep[Ed[(i << 1) - 1].end] ? sum[Ed[i << 1].end] : sum[Ed[(i << 1) - 1].end]);
    return 0;
}