#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+5;
int n,k;
vector<int> g[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        g[a].push_back(0);
        int t=0;
        while(a!=0){
            a/=2;
            ++t;
            g[a].push_back(t);
        }
    }
    int ans=1e9;
    for(int i=0;i<=200000;++i){
        if(g[i].size()>=k){
            sort(g[i].begin(),g[i].end());
            int sum=0;
            for(int j=0;j<k;++j){
                sum+=g[i][j];
            }
            ans=min(ans,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}