// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>deg(n);
    for(int i=0;i<n-1;++i){
        int u,v;
        cin>>u>>v;
        ++deg[u-1];
        ++deg[v-1];
    }
    for(int i=0;i<n;++i){
        if(deg[i]==2){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}