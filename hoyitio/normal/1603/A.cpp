#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define lowbit(x) (x&(-(x)))
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int main(){
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        fors(i,1,n+1) scanf("%d", &a[i]);
        int ok = 1;
        fors(i,1,n+1){
            int fnd = 0;
            for(int x = 2; x <= i+1; ++x){
                if(a[i]%x){fnd=1;break;}
            }
            if(!fnd) {ok = 0; break;}
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}