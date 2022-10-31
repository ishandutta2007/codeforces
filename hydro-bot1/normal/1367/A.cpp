// Hydro submission #62677db2255d14008c29a3ce@1650949555545
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,l;
    cin>>t;
    string s;
    for(i=0;i<t;i++)
    {
        cin>>s;
        l=s.size();
        printf("%c",s[0]);
        for(j=1;j<l;j+=2)
        if(s[j]==s[j+1]||j==l-1)
        printf("%c",s[j]);
        else printf("%c%c",s[j],s[j+1]);
        cout<<endl;
    }
    return 0;
}