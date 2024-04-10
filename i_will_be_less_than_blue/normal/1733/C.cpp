//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef pair<int, int> Pii;
typedef long long ll;
//#define prev aboba
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
vector<pair<int,int> >ans;
const int N=200010;
int a[N];
void go(int i,int j){
    ans.push_back({i,j});
    if ((a[i]+a[j])%2) a[j]=a[i];
    else a[i]=a[j];
}
void solve(){
    ans.clear();
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int last=-1;
    for (int i=n;i>=1;i--){
        if (a[i]%2==a[1]%2){
            if (last!=-1) go(i,last);
            last=i;
        }
    }
    for (int i=2;i<=n;i++){
        if (a[i]%2!=a[1]%2){
            go(i-1,i);
        }
    }
    if (!is_sorted(a+1,a+n+1)) exit(1);


    cout<<ans.size()<<'\n';
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
18
89 32 12 4 13 3 89 32 12 4 13 3 89 32 12 4 13 3
*/