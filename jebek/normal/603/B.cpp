#include <iostream>
#include<algorithm>

using namespace std;

bool mark[2000000];
long long n,k,t,ans=1;
const int MOD=1e9+7;

void dfs(int v)
{
    t=(t*k)%n;
    mark[v]=true;
    int u=(v*k)%n;
    if(!mark[u])
        dfs(u);
}

int main()
{
    cin>>n>>k;
    if(k==0){
        for(int i=1;i<n;i++)
            ans=(ans*n)%MOD;
        cout<<ans<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
        if(!mark[i])
        {
            t=1;
            dfs(i);
            if(t==1)
                ans=(ans*n)%MOD;
        }
    cout<<ans<<endl;
}