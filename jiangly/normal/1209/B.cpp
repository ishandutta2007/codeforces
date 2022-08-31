#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int> x(n);
    int tot=0;
    for(int i=0;i<n;++i){
        char c;
        cin>>c;
        x[i]=c-'0';
        tot+=x[i];
    }
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i];
    }
    int ans=tot;
    for(int t=1;t<=1000;++t){
        for(int i=0;i<n;++i){
            if(t>=b[i]&&(t-b[i])%a[i]==0){
                tot-=x[i];
                x[i]^=1;
                tot+=x[i];
            }
        }
        ans=max(ans,tot);
    }
    cout<<ans<<endl;
    return 0;
}