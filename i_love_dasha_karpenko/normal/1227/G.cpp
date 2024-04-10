//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e3+7;
int A[N],ptr = 0,equ[N][N];
int ans[N][N];
void place(int l,int r,int &val,int col){
    if (l==0 || r==0 || l==r || !val)
        return;
    equ[col][l] = ++ptr;
    --val;
    ans[col][l] = 1;
}
void place1(int l,int r,int &val,int col){
    if (l==0 || r==0 || val==0)
        return;
    if (l==r){
        ans[col][l] = 1;
        --val;
        return;
    }
    for(int i = l+1;i<r;++i){
        if (!val)
            break;
        equ[col][i] = equ[col][i-1];
        ans[col][i] = 1;
        --val;
    }
}
void place2(int l,int r,int &val,int col){
    if (l==0 || r==0 || l==r || val==0)
        return;
    equ[col][r] = equ[col][r-1];
    ans[col][r] = 1;
    --val;
}
void solve(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        sum+=A[i];
    }
    if (sum==n){
        cout<<"1\n";
        for(int i = 1;i<=n;++i)
            cout<<'1';
        cout<<endl;
        return;
    }
    equ[0][0] = -1;
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<=n+1;++j)
            equ[i][j] = equ[i-1][j];
        int last = 0;
        for(int j = 1;j<=n+1;++j){
            if (equ[i-1][j-1]!=equ[i-1][j]){
                place(last,j-1,A[i],i);
                last = j;
            }
        }
        place(last,n+1,A[i],i);
        last = 0;
        for(int j = 1;j<=n+1;++j){
            if (equ[i-1][j-1]!=equ[i-1][j]){
                place1(last,j-1,A[i],i);
                last = j;
            }
        }
        place1(last,n+1,A[i],i);
        last = 0;
        for(int j = 1;j<=n+1;++j){
            if (equ[i-1][j-1]!=equ[i-1][j]){
                place2(last,j-1,A[i],i);
                last = j;
            }
        }
        place2(last,n+1,A[i],i);
    }
    cout<<n+1<<endl;
    for(int j = 1;j<=n+1;++j) {
        for (int i = 1; i <= n; ++i)

            cout << ans[i][j];
        cout << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}