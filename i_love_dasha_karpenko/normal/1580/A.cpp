//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 407;
int A[N][N],pref[N][N];
int get(int a,int b,int c,int d){
    return pref[c][d]-pref[c][b-1]-pref[a-1][d]+pref[a-1][b-1];
}
int cost(int a1,int b1,int a2,int b2){
    int ret = get(a1+1,b1+1,a2-1,b2-1);
    int cnt = get(a1,b1,a2,b1)+get(a1,b1,a1,b2)+get(a2,b1,a2,b2)+get(a1,b2,a2,b2)-(A[a1][b1]+A[a1][b2]+A[a2][b1]+A[a2][b2])*2;
    ret+=(a2-a1-1)*2+(b2-b1-1)*2-cnt;
    return ret;
}
void add(int j,int l,int r,int &val){
    int dx = j*2-(get(l,1,l,j)+get(r,1,r,j));
    int dy = (r-l-1)-get(l+1,j,r-1,j);
    int dz = get(l+1,1,r-1,j);
    val = min(val,dy-dz-dx);
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            char ch;
            cin>>ch;
            A[i][j] = ch-'0';
            pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+A[i][j];
        }
    }
    //cout<<get(1,1,5,1)<<' '<<get(5,1,5,4)<<' '<<get(<<endl;
    int res = n*m;
    for(int l = 1;l<=n;++l){
        for(int r = l+4;r<=n;++r){

            vector<int > V;
            int vl = n*m;
            for(int j = 1;j<=m;++j){
                if (j>3)
                    add(j-3,l,r,vl);
                int dx = (j-1)*2-(get(l,1,l,j-1)+get(r,1,r,j-1));
                int dy = (r-l-1)-get(l+1,j,r-1,j);
                int dz = get(l+1,1,r-1,j-1);
                res = min(res,dy+dx+dz+vl);
                if (res==6){
                    int h;
                    ++h;
                }
            }

        }
    }
    cout<<res<<endl;

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}