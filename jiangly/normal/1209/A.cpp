#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<bool> vis(n);
    int ans=0;
    for(int i=0;i<n;++i){
        if(!vis[i]){
            ++ans;
            for(int j=i;j<n;++j){
                if(a[j]%a[i]==0){
                    vis[j]=true;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}