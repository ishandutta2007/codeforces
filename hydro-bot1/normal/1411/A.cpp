// Hydro submission #6274ca23997df5291339c9d9@1651821092217
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,i,j,m;
    cin>>t;
    string s;
    for(i=0;i<t;i++)
    {
        cin>>l>>s;m=0;
        for(j=l-1;j+1;j--)
        if(s[j]==41) m++;
        else break;
        printf(m>l-m?"YES\n":"NO\n");
    }
    return 0;
}