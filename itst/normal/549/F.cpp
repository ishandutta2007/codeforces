#include<bits/stdc++.h>
#define MAXN 300001
using namespace std;

int sum[MAXN] , ST[MAXN][21] , num[MAXN] , logg[MAXN] = {-1} , N , k;
long long ans;
vector < int > v[1000001];

inline int cmp(int a , int b){
    return num[a] > num[b] ? a : b;
}

inline int query(int a , int b){
    int t = logg[b - a + 1];
    return cmp(ST[a][t] , ST[b - (1 << t) + 1][t]);
}

inline int bina(int l , int r , int num){
    return upper_bound(v[num].begin() , v[num].end() , r) - lower_bound(v[num].begin() , v[num].end() , l);
}

void solve(int l , int r){
    if(l >= r)
        return;
    int t = query(l , r);
    solve(l , t - 1);
    solve(t + 1 , r);
    if(t - l < r - t)
        for(int i = t ; i >= l ; i--)
            ans += bina(t , r , (sum[i - 1] + num[t]) % k);
    else
        for(int i = t ; i <= r ; i++)
            ans += bina(l - 1 , t - 1 , (k + sum[i] - num[t] % k) % k);
    ans--;
}
int main(){
    for(int i = 1 ; i < MAXN ; i++)
        logg[i] = logg[i >> 1] + 1;
    scanf("%d%d" , &N , &k);
    v[0].push_back(0);
    for(int i = 1 ; i <= N ; i++){
        scanf("%d" , num + i);
        sum[i] = (sum[i - 1] + num[i]) % k;
        v[sum[i]].push_back(i);
        ST[i][0] = i;
    }
    for(int i = 1 ; 1 << i <= N ; i++)
        for(int j = 1 ; j + (1 << i) - 1 <= N ; j++)
            ST[j][i] = cmp(ST[j][i - 1] , ST[j + (1 << i - 1)][i - 1]);
    solve(1 , N);
    printf("%lld" , ans);
    return 0;
}