//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e4+7;
int A[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    if (n==1){
        if (A[1]==0){
            cout<<"1 2\n";
        }
        else{
            cout<<"2 1\n";
        }
        return;
    }
    if (A[1]==0){
        int flag = 0;
        for(int i = 1;i<=n;++i){
            cout<<i<<' ';
            if (flag==0 && (A[i+1]==1 || i+1>n)){
                cout<<n+1<<' ';
                flag = 1;
            }
        }
        cout<<'\n';
    }
    else{
        cout<<n+1<<' ';
        for(int i = 1;i<=n;++i){
            cout<<i<<' ';
        }
        cout<<'\n';
    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    //t = 1;
    while(t--)
        solve();
    return 0;
}