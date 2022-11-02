#include<bits/stdc++.h>
using namespace std;
string str;
bool appear[300];
int length;
int main()
{
    cin>>length>>str;
    for(register int i=0;i<length;i++)
    {
        for(register char c='A';c<='Z';c++)
        {
            if(str[i]==c)
            {
                appear[c-'A']=1;
            }
            else
            {
                if(str[i]-32-c==0)
                {
                    appear[c+32-'a']=1;
                }
            }
        }
    }
    for(register int i=0;i<26;i++)
    {
        if(appear[i]==0)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}