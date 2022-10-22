#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int B = 512;
int dp[B][B];
int main(){
    fors(i,0,B) dp[i][0] = 1;
    int n; cin>>n;
    fors(i,1,n+1){
        int x; scanf("%d", &x);
        if(x == 0) continue;
        for(int j = 0; j < B; ++j){
            if(dp[x-1][j]){
                int y = (j^x);
                int cur = x;
                while(cur<B && !dp[cur][y]) dp[cur][y] = 1, cur++;
            }
        }
    }
    vector<int> ans;
    fors(i,0,B){
        int ok = 0;
        fors(x,0,B) if(dp[x][i]) ok = 1;
        if(ok) ans.pb(i);
    }
    cout<<ans.size()<<endl;
    for(int x:ans) printf("%d ", x);
    return 0;
}