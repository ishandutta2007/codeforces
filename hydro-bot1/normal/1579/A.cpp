// Hydro submission #629728e81008115bd64b4e9e@1654073577254
#include<bits/stdc++.h>
using namespace std;
int m[3];
int main()
{
    int t,i,j,l;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        m[0]=0,m[1]=0,m[2]=0;
        cin>>s;l=s.size();
        for(j=0;j<l;j++)
        m[s[j]-65]++;
        printf(m[1]-m[0]-m[2]?"NO\n":"YES\n");
    }
    return 0;
}