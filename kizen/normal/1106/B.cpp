#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4;
int N, M;
int A[NS], C[NS];
struct data{
    int pos, val;
    bool operator<(const data&r)const{
        return val<r.val||(val==r.val&&pos<r.pos);
    }
}arr[NS];

int main(){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;++i) scanf("%d", A+i);
    for(int i=1;i<=N;++i) scanf("%d", C+i), arr[i].pos = i, arr[i].val = C[i];
    sort(arr+1, arr+N+1); int x = 1;
    while(M--){
        int t, d;
        scanf("%d %d", &t, &d);
        long long val = 0;
        val += (long long)C[t]*min(A[t], d);
        d -= min(A[t], d);
        A[t]-=val/C[t];
        while(1){
            while(x<=N&&!A[arr[x].pos]) ++x;
            if(x<=N){
                val += (long long)C[arr[x].pos]*min(A[arr[x].pos], d);
                int a = min(A[arr[x].pos], d);
                d -= min(A[arr[x].pos], d);
                A[arr[x].pos] -= a;
            }
            if(x>N||!d) break;
        }
        if(d&&x>N) puts("0");
        else printf("%lld\n", val);
    }
    return 0;
}