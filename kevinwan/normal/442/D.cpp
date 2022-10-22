#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=1e6+10;
int p[mn],g1[mn],g2[mn],v[mn];
bool eval(int x){
    int ori=v[x];
    if(x!=1&&v[g1[x]]==v[g2[x]])v[x]=v[g1[x]]+1;
    else v[x]=v[g1[x]];
    return v[x]>ori;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=2;i<=n+1;i++){
        cin>>p[i];
        v[i]=1;
        for(int j=i;j!=1;j=p[j]){
            if(g1[p[j]]!=j){
                if(v[j]>v[g1[p[j]]])g2[p[j]]=g1[p[j]],g1[p[j]]=j;
                else if(v[j]>v[g2[p[j]]])g2[p[j]]=j;
            }
            if(!eval(p[j]))break;
        }
        printf("%d ",v[1]);
    }
}