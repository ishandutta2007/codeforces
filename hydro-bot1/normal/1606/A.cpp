// Hydro submission #6297299d1008115bd64b4f1f@1654073757932
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;
        s[s.size()-1]=s[0];
        cout<<s<<endl;
    }
    return 0;
}