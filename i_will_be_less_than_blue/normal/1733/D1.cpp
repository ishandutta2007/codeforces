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
int s[N];
void solve(){
    int n,x,y;cin>>n>>x>>y;
    string a;cin>>a;
    string b;cin>>b;
    for (int i=0;i<n;i++) s[i]=(a[i]!=b[i]);
    int cnt=0;
    int l=n+1;
    int r=-1;
    for (int i=0;i<n;i++){
        cnt+=s[i];
        if (s[i]){
            l=min(l,i);
            r=max(r,i);
        }
    }
    if (cnt%2){
        cout<<-1<<endl;
        return;
    }
    if (x>=y){
        if (cnt==2 && l+1==r){
            cout<<min(x,2*y)<<'\n';
        } else {
            cout<<(cnt/2)*1ll*y<<'\n';
        }
    } else {
        exit(1);
    }






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