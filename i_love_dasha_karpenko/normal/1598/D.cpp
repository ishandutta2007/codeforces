#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 2e5+7;
pair<int,int> A[N];
int cnt[2][N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cnt[0][i] = cnt[1][i] = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i].first>>A[i].second;
        ++cnt[0][A[i].first];
        ++cnt[1][A[i].second];
    }
    //sort(A+1,A+1+n);
    int p1 = 0,p2 = 1;
    ll res = ll(n)*(n-1)*(n-2)/6;
    ll df = 0;
    for(int i = 1;i<=n;++i){
        df+=ll(cnt[0][A[i].first]-1)*(cnt[1][A[i].second]-1);
    }
    cout<<res-df<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}