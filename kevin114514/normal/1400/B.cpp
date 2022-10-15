#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        if(e>f)
        {
            swap(c,d);
            swap(e,f);
        }
        int ans=0;
        for(int i=0;i<=c;i++)
        {
            if(i*e>a)
                break;
            int ae=i;
            int af=(a-ae*e)/f;
            af=min(af,d);
            int be=min(c-ae,b/e);
            int bf=min(d-af,(b-be*e)/f);
            ans=max(ans,ae+af+be+bf);
        }
        cout<<ans<<endl;
    }
    return 0;
}