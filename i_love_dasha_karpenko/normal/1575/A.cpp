#pragma GCC Optimize("O3")
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 3e5+7;
pair<string,int> A[N];
int n,m;
bool mc(pair<string,int> &a,pair<string,int> &b){
    for(int i = 0;i<m;++i){
        if (a.first[i]==b.first[i])
            continue;
        if (!(i&1))
            return a.first[i]<b.first[i];
        else return b.first[i]<a.first[i];
    }
    return 0;
}
void solve(){

    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        cin>>A[i].first,A[i].second = i;
    sort(A+1,A+1+n,mc);
    for(int i = 1;i<=n;++i)
        cout<<A[i].second<<' ';
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--)
        solve();
}