#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>dv[200009];
int f(int x)
{

    return (x&(-x));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<=200000;i++)
        for(int j=2*i;j<=200000;j+=i)dv[j].push_back(i);

    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        ll ans=0;
        for(int i=l+2;i<=r;i++)
        {
            ll z=i-l;
            ans+=(z*(z-1))/2;
            z=0;
            ll p=0;

            for(int j=0;j<dv[i].size();j++){if(dv[i][j]>=l)z++;
            if((f(dv[i][j])==f(i))&&(2*dv[i][j]>=l) &&(2*dv[i][j]<i))p++;
            }
            ans-=(z*(z-1))/2;

            if(((i%3)==0)&&((i%5)==0))
            {
                int u=(i/5)*2;
                if(u>=l)ans--;
            }
            if(((i%2)==0)&&((i%3)==0))
                if((i/2)>=l)ans--;
        }
        cout<<ans<<endl;

    }

    return 0;
}