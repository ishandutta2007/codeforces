#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = 5004;
LL N, M, s;
vector < LL > arr[5004], brr[5004], number;
LL group[NS], gN, did[5004];
LL can[5004];
LL q[5004], f, r, chk[5004];
LL ansdid[5004];

void fd(LL x){
    did[x] = 1;
    for(LL i=0;i<(LL)arr[x].size();++i) if(!did[arr[x][i]]){
        fd(arr[x][i]);
    }
    number.push_back(x);
}

void sol(LL x){
    group[x] = gN;
    for(LL i=0;i<(LL)brr[x].size();++i) if(!group[brr[x][i]]){
        sol(brr[x][i]);
    }
}

int main(){
//    freopen("input.txt", "r", stdin);

    scanf("%lld %lld %lld", &N, &M, &s);
    for(LL i=0;i<M;i++){
        LL a, b;
        scanf("%lld %lld", &a, &b);
        arr[a].push_back(b);
    }
    for(LL i=1;i<=N;++i) if(!did[i]) fd(i);
    reverse(number.begin(), number.end());
    for(LL i=1;i<=N;++i) for(LL j=0;j<(LL)arr[i].size();j++) brr[arr[i][j]].push_back(i);
    for(LL i=0;i<(LL)number.size();++i) if(!group[number[i]]) ++gN, sol(number[i]);
    f = r = 0;
    q[r++] = s; chk[s] = 1;
    while(f<r){
        for(LL i=0;i<(LL)arr[q[f]].size();++i) if(!chk[arr[q[f]][i]]){
            chk[arr[q[f]][i]] = 1;
            q[r++] = arr[q[f]][i];
        }
        f++;
    }
    LL ans = 0;
    for(LL i=0;i<(LL)number.size();++i) if(!chk[number[i]]){
        ans++;
        f = r = 0;
        q[r++] = number[i]; chk[number[i]] = 1;
        while(f<r){
            for(LL i=0;i<(LL)arr[q[f]].size();++i) if(!chk[arr[q[f]][i]]){
                chk[arr[q[f]][i]] = 1;
                q[r++] = arr[q[f]][i];
            }
            f++;
        }
    }
    printf("%lld", ans);

    return 0;
}