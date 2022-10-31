#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 1E2+7;
int A[DIM],B[DIM];
void solve(){
    int k,n,m;
    cin>>k>>n>>m;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    for(int j = 1;j<=m;++j)
        cin>>B[j];
    vector<int> ans;
    int ptra = 1,ptrb = 1;
    while(ptra<=n || ptrb<=m){
        if (ptra<=n && (A[ptra]==0 || A[ptra]<=k)){
            if (A[ptra]==0)
                ++k;
            ans.push_back(A[ptra]);
            ++ptra;
        }
        else if (ptrb<=m && (B[ptrb]==0 || B[ptrb]<=k)){
            if (B[ptrb]==0)
                ++k;
            ans.push_back(B[ptrb]);
            ++ptrb;
        }
        else break;
    }
    if (ans.size()!=n+m)
        cout<<"-1\n";
    else{
        for(int to:ans)
            cout<<to<<' ';
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}