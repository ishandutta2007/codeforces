#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 +50;
char s[maxn];
vector<int> g;
int main()
{
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        scanf("%s", s+1);
        int cur = 1;
        g.clear();
        for(int i = 2; i <= n+1; ++i){
            if(s[i] != s[i-1]){
                //cout<<"cur:"<<cur<<endl;
                g.pb(cur); cur = 1;
            }else cur++;
        }
        int ans = 0;
        int p = 0, ed = 0;
        while(p < g.size()){
            while(ed < p) ed++;
            while(ed < g.size() && g[ed] == 1) {
               //cout<<"g:"<<g[ed]<<endl;
                ed++;
            }
            //cout<<"p:"<<p<<" ed:"<<ed<<endl;
            if(ed >= g.size()){
                p += 2;
            }else{
                g[ed]--;
                p++;
            }
            ans++;
            //cout<<"p:"<<p<<" ed:"<<ed<<endl;
        }
        printf("%d\n", ans);
    }
}
/*
1
7
0111000
*/