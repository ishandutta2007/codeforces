#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bool ans=true;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(ans==false)continue;
            bool th=false;
            for(int j=i;j>=1;j--)
            {
                if(x%(j+1)){th=true;break;}
            }
            if(th==false)ans=false;
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}