// Hydro submission #6247f7ee993deab6561077da@1648883694202
#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
int main()
{
    int i,n,m1=0,m2=0;
    cin>>n;
    if(n<3)
    {
        while(cin>>s);
        cout<<s<<endl;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        cin>>s;
        if(i)
        {
            if(s==s1)
            s1=s,m1++;
            else
            s2=s,m2++;
        }
        else s1=s,m1++;
    }
    if(m1>m2)
    cout<<s1;
    if(m1<m2)
    cout<<s2;
    cout<<endl;
    return 0;
}