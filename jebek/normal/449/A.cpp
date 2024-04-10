#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,k,ans;
long long DP()
{
    if(k<n)
        return m*(n/(k+1));
    return m/(k-n+2);
}

int main()
{
    cin>>n>>m>>k;
    if(k>n+m-2)
    {
        cout<<-1<<endl;
        return 0;
    }
    ans=DP();
    swap(n,m);
    ans=max(ans,DP());
    cout<<ans<<endl;
}