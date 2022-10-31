#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 300+7;
pair<int,int> A[N*N];
bool mc(pair<int,int> &a,pair<int,int> &b){
    if (a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}
int T[N][N];
int n,m;
void add(int t,int pos,int delta){
    for(int i = pos;i<=m;i+=(i&-i))
        T[t][i]+=delta;
}
int get(int t,int pos){
    int ret = 0;
    for(int i = pos;i>0;i-=(i&-i))
        ret+=T[t][i];
    return ret;
}
void solve(){

    cin>>n>>m;
    for(int i = 1;i<=n*m;++i){
        cin>>A[i].first;
        A[i].second = i;
    }
    sort(A+1,A+1+n*m,mc);
    for(int i = 1;i<=n*m;++i){
        A[i].first = i;
        swap(A[i].first,A[i].second);
    }
    sort(A+1,A+1+n*m);
    ll res = 0;
    for(int i = 1;i<=n*m;++i){
        int row = A[i].second/m-(A[i].second%m==0);
        int col = A[i].second-row*m;
        ++row;
        res+=get(row,col);
        add(row,col,1);
    }
    cout<<res<<endl;
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=m;++j){
            T[i][j] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}