#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
int main()
{
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        printf("2\n");
        printf("%d %d\n", n-1, n);
        for(int i = n; i > 2; --i){
            printf("%d %d\n", i, i-2);
        }
    }
}