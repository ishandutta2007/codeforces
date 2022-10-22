#include <bits/stdc++.h>

using namespace std;
long long br[56],i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
    br[0]=0;
    int n,j;
    cin>>n;
    for(i=1;i<=n;i++){
        br[i]=1;
        for(j=1;j<=i;j++)br[i]*=2;
        br[i]+=br[i-1];
    }
    cout<<br[n];
    return 0;
}