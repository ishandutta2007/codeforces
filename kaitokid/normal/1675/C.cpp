#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        n=s.size();
        int on=0,zr=n-1;
        for(int i=0;i<n;i++)
            if(s[i]=='1')on=i;
        for(int i=n-1;i>=0;i--)
            if(s[i]=='0')zr=i;
        int ans=zr-on+1;
        if(ans<0)ans=0;
        cout<<ans<<endl;
    }

    return 0;

}