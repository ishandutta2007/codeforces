#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=150005;
int T,n;
int a[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        int mn=1e6;
        int ans=0;
        for(int i=n;i>=1;--i){
            if(a[i]>mn){
                ++ans;
            }else{
                mn=a[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}