#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 2e5+7;
int A[N];
void solve(){
    int n;
    cin>>n;
    ll sum = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        sum+=A[i];
    }
    if ((sum*2)%n){
        cout<<"0\n";
        return;
    }
    ll need = (sum*2)/n;
    map<int,int> M;
    ll res = 0;
    for(int i = 1;i<=n;++i){
        res+=M[need-A[i]];
        M[A[i]]++;
    }
    cout<<res<<endl;
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