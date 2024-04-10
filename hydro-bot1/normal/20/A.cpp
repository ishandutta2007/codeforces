// Hydro submission #62692a889f31360077e29345@1651059337464
#include<bits/stdc++.h>
using namespace std;
string s;
int l;
bool flag=0;
int main()
{
    cin>>s;
    l=s.size();
    while(s[l-1]=='/'&&l>=1) l--;
    if(!l) cout<<"/"<<endl;
    if(l==1) cout<<s[0]<<endl;
    for(register int i=0;i<l;i++)
    {
        if(flag)
        {
            if(s[i]!='/')
            {
                cout<<s[i];
                flag=0;
            }
        }
        else
        {
            cout<<s[i];
            if(s[i]=='/') flag=1;
        }
    }
    return 0;
}