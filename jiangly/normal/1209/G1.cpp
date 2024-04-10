#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    vector<int> rt(200000);
    vector<int> cnt(200000);
    for(int i=0;i<n;++i){
        cin>>a[i];
        --a[i];
        rt[a[i]]=i;
        ++cnt[a[i]];
    }
    int ans=n;
    for(int i=0;i<n;++i){
        int mx=cnt[a[i]];
        int y=rt[a[i]];
        for(int j=i+1;j<=y;++j){
            y=max(y,rt[a[j]]);
            mx=max(mx,cnt[a[j]]);
        }
        ans-=mx;
        i=y;
    }
    cout<<ans<<endl;
    return 0;
}