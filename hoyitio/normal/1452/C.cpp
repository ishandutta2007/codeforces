#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        scanf("%s", s);
        int len = strlen(s);
        int c1 = 0, c2 = 0;
        int ans = 0;
        fors(i,0,len){
            if(s[i] == '(') c1++;
            else if(s[i] == ')'){
                if(c1) c1--, ans++;
            }else if(s[i] == '[') c2++;
            else if(s[i] == ']') if(c2) c2--, ans++;
        }
        printf("%d\n", ans);
    }
}