#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=5010;
vector<int> k[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i,j,a,b;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>a>>b;
        k[a].push_back((b-a+n)%n);
    }
    for(i=1;i<=n;i++)sort(k[i].begin(),k[i].end());
    for(i=1;i<=n;i++){
        int ans=0;
        for(j=0;j<n;j++){
            if(k[(i+j-1)%n+1].size())ans=max(ans,(int)(j+k[(i+j-1)%n+1][0]+(k[(i+j-1)%n+1].size()-1)*n));
        }
        printf("%d ",ans);
    }
}