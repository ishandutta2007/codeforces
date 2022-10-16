#include <iostream>

using namespace std;
int n, a, x[1000], ans;
int main()
{
    cin>>n>>a;

    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    int i, j;
    for(i=a, j=a;i>0 && j<=n;i--, j++)
    {
        if(x[i]==x[j] && x[i]==1)
        {
            if(i!=j)
            ans++;
            ans++;
        }
    }
    for(int k=j;k<=n;k++)
            ans+=x[k];

    for(int k=i;k>=0;k--)
            ans+=x[k];

    cout<<ans<<'\n';
    return 0;
}