#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    bool f = 0;
    char c = getchar();
    while(c != EOF && !isdigit(c)){
        if(c == '-')
            f = 1;
        c = getchar();
    }
    while(c != EOF && isdigit(c)){
        a = (a << 3) + (a << 1) + (c ^ '0');
        c = getchar();
    }
    return f ? -a : a;
}

struct query{
    int l , r , ind;
}now[200010];
int cnt[1000010] , num[200010] , N , M , T;
long long cur , ans[200010];

bool operator <(query a , query b){
    return a.l / T == b.l / T ? ((a.l / T & 1) ? a.r > b.r : a.r < b.r) : a.l < b.l;
}

inline void add(int ind){
    cur = cur - 1ll * cnt[ind] * cnt[ind] * ind + 1ll * (cnt[ind] + 1) * (cnt[ind] + 1) * ind;
    ++cnt[ind];
}

inline void del(int ind){
    cur = cur - 1ll * cnt[ind] * cnt[ind] * ind + 1ll * (cnt[ind] - 1) * (cnt[ind] - 1) * ind;
    --cnt[ind];
}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("86D.in" , "r" , stdin);
    //freopen("86D.out" , "w" , stdout);
#endif
    N = read();
    T = sqrt(N);
    M = read();
    for(int i = 1 ; i <= N ; ++i)
        num[i] = read();
    for(int i = 1 ; i <= M ; ++i){
        now[i].l = read();
        now[i].r = read();
        now[i].ind = i;
    }
    sort(now + 1 , now + M + 1);
    int L = 1 , R = 0;
    for(int i = 1 ; i <= M ; ++i){
        while(R < now[i].r)
            add(num[++R]);
        while(R > now[i].r)
            del(num[R--]);
        while(L > now[i].l)
            add(num[--L]);
        while(L < now[i].l)
            del(num[L++]);
        ans[now[i].ind] = cur;
    }
    for(int i = 1 ; i <= M ; ++i)
        printf("%lld\n" , ans[i]);
    return 0;
}