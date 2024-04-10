#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
vector < LL > A, B;
vector < LL > num, chk;
LL N, M;

int main(){
    scanf("%lld %lld", &N, &M);
    LL sum = 0;
    for(LL i=1;sum+i<=N+M;++i) num.push_back(i), sum+=i, chk.push_back(0);
    for(LL i=(LL)num.size()-1;i>=0;--i) if(N>=num[i]){
        N-=num[i], A.push_back(num[i]), chk[i] = 1;
    }
    for(LL i=0;i<(LL)num.size();++i) if(!chk[i]) B.push_back(num[i]);
    sort(A.begin(), A.end()), sort(B.begin(), B.end());
    printf("%lld\n", (LL)A.size());
    for(LL i=0;i<(LL)A.size();++i) printf("%lld ", A[i]);
    puts("");
    printf("%lld\n", (LL)B.size());
    for(LL i=0;i<(LL)B.size();++i) printf("%lld ", B[i]);
    return 0;
}