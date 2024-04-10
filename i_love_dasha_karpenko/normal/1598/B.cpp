#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e3+7;
int A[N][5];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<5;++j){
            cin>>A[i][j];
        }
    }
    for(int d1 = 0;d1<5;++d1){
        for(int d2 = d1+1;d2<5;++d2){
            int cnt[3] = {0,0,0};
            for(int i = 1;i<=n;++i){
                if (A[i][d1]==1 && A[i][d2]==1)
                    ++cnt[0];
                else if (A[i][d1]==1)
                    ++cnt[1];
                else if (A[i][d2]==1)
                    ++cnt[2];
            }
            if (cnt[0]+cnt[1]+cnt[2]!=n)
                continue;
            int g = abs(cnt[2]-cnt[1]);
            if (cnt[0]<g || (cnt[0]&1)!=(g&1))
                continue;
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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