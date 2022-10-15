#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
int l[200200],r[200200];
int main()
{
    cin>>n>>m>>s>>t;
    int L=0,R=n-1;
    for(int i=0;i<m;i++)
    {
        while(s[L]!=t[i])
            L++;
        l[i]=L;
        L++;
    }
    for(int i=m-1;i>=0;i--)
    {
        while(s[R]!=t[i])
            R--;
        r[i]=R;
        R--;
    }
    int ans=0;
    for(int i=0;i<m-1;i++)
        ans=max(ans,r[i+1]-l[i]);
    cout<<ans<<endl;
    return 0;
}