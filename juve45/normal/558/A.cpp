#include <bits/stdc++.h>

using namespace std;

pair<int, int> x[120];

int n;

int main()
{
cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i].first>>x[i].second;
    }

    sort(x+1, x+n+1);

    int I=1;
    while(x[I].first<0)
        I++;

    int Ii=I;
    Ii--;
    while(Ii!=0 && I!=n+1)
    {
        ans+=x[Ii].second+x[I].second;
        Ii--;
        I++;
    }
    if(I==n+1 && Ii==0)
    {
        cout<<ans;
        return 0;
    }
    if(I==n+1)
        ans+=x[Ii].second;
    if(Ii==0)ans+=x[I].second;
    cout<<ans;

    return 0;
}