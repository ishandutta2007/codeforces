#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
ll pw[63];
int main()
{
    pw[0] = 1;
    fors(i,1,63) pw[i] = pw[i-1]*2;
    int T; cin>>T;
    while(T--){
        ll k; scanf("%lld", &k);
        if(k&1){
             printf("%d\n", -1); continue;
        }
        vector<int> a; a.clear();
        int cur = 61;
        while(k > 0 && cur ){
            if(pw[cur+1]-2 <= k){
                k -= pw[cur+1]-2; a.pb(cur);
            }else cur--;
        }
        if(cur == 0){
            printf("%d\n", -1); continue;
        }
        else{
            int sum = 0; for(int x: a) sum+=x;
            printf("%d\n", sum);
            fors(i,0,a.size()){
                int x = a[i];
                printf("1"); x--;
                while(x--) printf(" 0");
                if(i+1 == a.size()) printf("\n");
                else printf(" ");
            }
        }
    }
}