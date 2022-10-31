// Hydro submission #62972974b0c5e75beb1581d3@1654073717029
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,p,i,j;
    cin>>t;
    char c;
    string s;
    for(i=0;i<t;i++)
    {
        cin>>s;
        l=s.size(),p=l,c=123;
        for(j=0;j<l;j++)
        if(s[j]<c)
        {
            c=s[j];
            p=j;
        }
        printf("%c\n",c);
        for(j=0;j<l;j++)
        if(j-p) printf("%c",s[j]);
        else continue;
        cout<<endl;
    }
    return 0;
}