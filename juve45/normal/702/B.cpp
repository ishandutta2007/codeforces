#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> m;
int n, a[100009], p2[50];
int main()
{

    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }

int k=0;
    for(int i=1;i<1000000000;i*=2)
    {
        p2[++k]=2*i;
    }

    for(int i=1;i<=n;i++)
    {
            m[a[i]]--;
        for(int j=1;j<=k;j++)
        {
            if(m.find(p2[j]-a[i])!=m.end())
            {
                ans+=1LL*(m[p2[j]-a[i]]);
            }
        }
    }


    cout<<ans<<'\n';
    return 0;
}