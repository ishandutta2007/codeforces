#include <bits/stdc++.h>

using namespace std;
long niz[100005];
long poj[100005];
long br[100005];
int main()
{
    long n,i,x,m;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    br[n]=0;
    for(i=n-1;i>=0;i--){
        br[i]=br[i+1]+1-poj[niz[i]];
        poj[niz[i]]=1;
    }
    for(i=0;i<m;i++){
        cin>>x;
        cout<<br[x-1]<<endl;
    }
    return 0;
}