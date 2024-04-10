#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int> fa(n);
    for(int i=0;i<n;++i){
        fa[i]=i;
    }
    auto find=[&](int x){
        while(fa[x]!=x){
            x=fa[x]=fa[fa[x]];
        }
        return x;
    };
    int ans=0;
    for(int i=0;i<k;++i){
        int u,v;
        cin>>u>>v;
        u=find(u-1);
        v=find(v-1);
        if(u!=v){
            fa[v]=u;
        }else{
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}