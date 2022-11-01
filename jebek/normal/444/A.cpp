#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pii;

int n,m;
long double a[1000],ans;

int main()
{
    cout.precision(15);
    cout<<fixed;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
    {
        int v,u;
        long double w;
        cin>>v>>u>>w;
        ans=max(ans,(a[v]+a[u])/w);
    }
    cout<<ans<<endl;
}