#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

inline ull read(){
    ull a = 0;
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    while(isdigit(c)){
        a = (a << 3) + (a << 1) + (c ^ '0');
        c = getchar();
    }
    return a;
}

const int MAXN = 3e5 + 10;
int num[MAXN] , rig[MAXN][65] , lef[MAXN][65] , cnt[MAXN][2] , sum[MAXN] , ST[21][MAXN] , logg2[MAXN] , N;
long long ans;

inline int cmp(int a , int b){
    return num[a] > num[b] ? a : b;
}

void init_st(){
    for(int i = 2 ; i <= N ; ++i)
        logg2[i] = logg2[i >> 1] + 1;
    for(int i = 1 ; 1 << i <= N ; ++i)
        for(int j = 1 ; j + (1 << i) - 1 <= N ; ++j)
            ST[i][j] = cmp(ST[i - 1][j] , ST[i - 1][j + (1 << (i - 1))]);
}

inline int query(int x , int y){
    int t = logg2[y - x + 1];
    return cmp(ST[t][x] , ST[t][y - (1 << t) + 1]);
}

void solve(int l , int r){
    if(l > r)
        return;
    if(l == r){
        ans += num[l] == 0;
        return;
    }
    int k = query(l , r);
    //cout << l << ' ' << r << ' ' << k << endl;
    solve(l , k - 1);
    solve(k + 1 , r);
    if(k - l < r - k)
        for(int i = k ; i >= l ; --i)
            ans += cnt[r][sum[i - 1] & 1] - cnt[min(max(k - 1 , rig[i][num[k]] - 1) , r)][sum[i - 1] & 1];
    else
        for(int i = k ; i <= r ; ++i)
            if(lef[i][num[k]] >= l)
                ans += cnt[min(k - 1 , lef[i][num[k]] - 1)][sum[i] & 1] - (l == 1 ? 0 : cnt[l - 2][sum[i] & 1]);
    //cout << l << ' ' << r << ' ' << ans << endl;
}

int main(){
    N = read();
    cnt[0][0] = 1;
    for(int i = 1 ; i <= N ; ++i){
        ull a = read();
        while(a){
            if(a & 1)
                ++num[i];
            a >>= 1;
        }
        sum[i] = sum[i - 1] + num[i];
        cnt[i][0] = cnt[i - 1][0] + !(sum[i] & 1);
        cnt[i][1] = cnt[i - 1][1] + (sum[i] & 1);
        ST[0][i] = i;
        //cout << num[i] << ' ';
    }
    for(int i = 0 ; i <= 64 ; ++i){
        int p = 0;
        for(int j = 1 ; j <= N ; ++j)
            while(p < j && sum[j] - sum[p] >= i << 1)
                rig[++p][i] = j;
        while(p < N)
            rig[++p][i] = N + 1;
        for(int j = N ; j ; --j)
            while(p >= j && sum[p] - sum[j - 1] >= i << 1)
                lef[p--][i] = j;
    }
    init_st();
    //cout << endl;
    solve(1 , N);
    cout << ans;
    return 0;
}