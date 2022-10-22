#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        string s;
        cin>>n>>k>>s;
        if(k==0){cout<<1<<endl;continue;}

        bool bl=false;
        for(int i=0;i<n;i++)
        if(s[i]!=s[n-i-1]){bl=true;break;}
        if(bl)cout<<2<<endl;
        else cout<<1<<endl;
               }
    return 0;
}