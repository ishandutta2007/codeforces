#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long lint;

lint n,m,k;

lint solCount(lint lim){
    long long sol = 0;
    for (int i=1; i<=m; i++) {
        sol += min(lim/i,n);
    }
    return sol;
}

int main(){
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    lint s = 1, e = n*m, mid;
    while (s!=e) {
        mid = (s+e)/2;
        if(solCount(mid)>=k) e = mid;
        else s = mid+1;
    }
    printf("%I64d",s);
}