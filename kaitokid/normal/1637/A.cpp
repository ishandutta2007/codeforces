#include <bits/stdc++.h>
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
        int n,lst=0,x;
        cin>>n;
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x<lst)ans=true;
            lst=x;

        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}