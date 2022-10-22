#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[27];
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
        string s;
        for(int i=0;i<27;i++)fr[i]=0;
        cin>>s;
        int ans=s.size();
        for(int i=0;i<s.size();i++)
            if((fr[s[i]-'A']++)==0)ans++;

            cout<<ans<<endl;
    }
    return 0;

}