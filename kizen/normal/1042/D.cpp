#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = (LL)2e5+4;
LL N, T;
LL arr[NS];
struct dat{
    LL val, num;
    dat(){}
    dat(LL val, LL num):val(val), num(num){}
    bool operator<(const dat&r)const{
        return val<r.val;
    }
}hap[NS];
LL tree[NS*4];

void push(LL num, LL s, LL e, LL pos){
    if(s==e) ++tree[num];
    else{
        if(pos<=(s+e)/2) push(num*2, s, (s+e)/2, pos);
        else push(num*2+1, (s+e)/2+1, e, pos);
        tree[num] = tree[num*2]+tree[num*2+1];
    }
}

LL getsum(LL num, LL s, LL e, LL fs, LL fe){
    if(s==fs&&e==fe) return tree[num];
    else{
        LL rv = 0;
        if(fs<=(s+e)/2) rv += getsum(num*2, s, (s+e)/2, fs, min(fe, (s+e)/2));
        if(fe>(s+e)/2) rv += getsum(num*2+1, (s+e)/2+1, e, max(fs, (s+e)/2+1), fe);
        return rv;
    }
}
LL happos[NS];

int main(){
    scanf("%lld %lld", &N, &T);
    for(LL i=1;i<=N;++i) scanf("%lld", arr+i), arr[i]+=arr[i-1], hap[i].val = arr[i], hap[i].num = i;
    sort(hap+1, hap+N+1);
    for(LL i=1;i<=N;++i) happos[hap[i].num] = i;
    LL ans = 0;
    for(LL i=N;i>=1;--i){
        push(1, 1, N, happos[i]);
        LL lpos = lower_bound(hap+1, hap+N+1, dat(arr[i-1]+T, 0))-hap;
        --lpos;
        if(lpos) ans += getsum(1, 1, N, 1, lpos);
    }
    printf("%lld", ans);
    return 0;
}