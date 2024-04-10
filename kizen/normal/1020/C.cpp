#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL N, M;
LL arr[3004][3];
LL cnt[3004], chk[3004];
vector < LL > vc;

int main(){
    scanf("%lld %lld", &N, &M);
    for(LL i=1;i<=N;++i) scanf("%lld %lld", arr[i], arr[i]+1), ++cnt[arr[i][0]];
    for(LL i=1;i<=N;++i) if(arr[i][0]==1) chk[i] = 1;

    LL ans = (LL)1e18, sum = 0;
    for(LL i=1;i<=N;++i) if(!chk[i]) vc.push_back(arr[i][1]);
    sort(vc.begin(), vc.end());
    LL val = 0, big = 0;
    for(LL i=2;i<=M;++i) big = max(big, cnt[i]);
    for(LL i=0;i<big+1-cnt[1];++i) val += vc[i];
    ans = min(ans, val);
    for(LL k=0;k<N-cnt[1];++k){
        big = 0;
        LL pos;
        for(LL i=2;i<=M;++i) if(cnt[i]>big){
            big = cnt[i], pos = i;
        }
        LL pos2, low = (LL)1e18;
        for(LL i=1;i<=N;++i) if(!chk[i]&&arr[i][0]==pos&&arr[i][1]<low){
            low = arr[i][1], pos2 = i;
        }
        chk[pos2] = 1, sum += low, --cnt[pos];
        vc.clear();
        for(LL i=1;i<=N;++i) if(!chk[i]) vc.push_back(arr[i][1]);
        sort(vc.begin(), vc.end());

        val = 0, big = 0;
        for(LL i=2;i<=M;++i) big = max(big, cnt[i]);
        for(LL i=0;i<big+1-k-1-cnt[1];++i) val += vc[i];
        ans = min(ans, val+sum);
    }
    printf("%lld", ans);

    return 0;
}