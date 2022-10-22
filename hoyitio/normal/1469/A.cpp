#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 1e3 + 5;
char s[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        scanf("%s", s+1);
        int n = strlen(s+1);
        if(n&1){
            printf("No\n");
        }else{
            if(s[1] == ')' || s[n] == '(') puts("No");
            else puts("Yes");
        }
    }
}