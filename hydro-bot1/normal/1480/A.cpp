// Hydro submission #6274cd6d997df5291339d32e@1651821934389
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,i,j;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;
        l=s.size();
        for(j=0;j<l;j++)
        printf(j%2?(s[j]-122?"z":"y"):(s[j]-97?"a":"b"));
        cout<<endl;
    }
    return 0;
}