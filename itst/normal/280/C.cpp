#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 100010 , MOD = 998244353;
struct Edge{
    int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , dep[MAXN] , N , cntEd;
long double sum;
 
inline void addEd(int a , int b){
    Ed[++cntEd].end = b;
    Ed[cntEd].upEd = head[a];
    head[a] = cntEd;
}
 
inline long long poww(long long a , int b){
    long long times = 1;
    while(b){
        if(b & 1)
            times = times * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return times;
}
 
void dfs(int now , int fa){
    dep[now] = dep[fa] + 1;
    sum += 1.0 / dep[now];
    for(int i = head[now] ; i ; i = Ed[i].upEd)
        if(!dep[Ed[i].end])
            dfs(Ed[i].end , now);
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
    cout << fixed << setprecision(10) << sum ;
    return 0;
}