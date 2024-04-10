#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int mult = 1,pr = 0;
    while(mult<n)
        mult*=k,++pr;
    cout<<pr<<endl;
    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            int x1 = i-1,x2 = j-1,e = 0;
            while(x1!=x2){
                x1/=k;
                x2/=k;
                ++e;
            }
            cout<<e<<' ';
        }
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)
        solve();
}