#include<stdio.h>
#include<set>
using namespace std;

int main(){
    long n, k;
    long long s, m;
    scanf("%d%d",&n,&k);
    multiset <long long> S;
    for (long i = 0; i < k; ++i) S.insert(0);
    for (long i = 0; i < n; ++i) {
        scanf("%d%d",&s,&m);
        long long maxx = *S.lower_bound(0);
        S.erase(S.lower_bound(0));
        S.insert(max(maxx, s) + m);
        printf("%I64d\n",max(maxx, s) + m);
    };
};