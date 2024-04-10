#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a')
#define gp(i,j) int((i-1)*m+j-1)
const int N = 1e6+7;
int n,m;

char A[N],B[N];

void solve(){
    cin>>n>>m;

    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j)
            cin>>A[gp(i,j)];
    int res = 0;
    for(int col = 0;col<2;++col){
        set<int> S;
        for(int s = 2;s<=n+m;++s){
            if ((s&1)!=col)
                continue;
            int start = max(1,s-m),fin = min(n,s-1);
            for(int i = start;i<=fin;++i){
                int j = s-i;
                if (j<1 || j>m || A[gp(i,j)]!='1')
                    continue;
                auto it = S.upper_bound(i-j);
                if (it!=S.begin()){
                    it = prev(it);
                    S.erase(it);
                }
                S.insert(i-j);
            }
        }

        res+=S.size();
    }
    cout<<res<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}