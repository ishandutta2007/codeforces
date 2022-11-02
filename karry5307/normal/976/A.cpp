#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll length;
string bin;
int main()
{
    cin>>length>>bin;
    while(bin[0]=='0')
    {
        bin.erase(0,1);
    }
    if(bin.length()==0)
    {
        cout<<'0'<<endl;
        return 0;
    }
    cout<<'1';
    for(register int i=0;i<bin.length();i++)
    {
        if(bin[i]=='0')
        {
            cout<<'0';
        }
    }
}