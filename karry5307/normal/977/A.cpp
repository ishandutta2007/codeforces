#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string num;
ll cnt;
int main()
{
    cin>>num>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        if(num[num.length()-1]=='0')
        {
            num.erase(num.length()-1);
        }
        else
        {
            num[num.length()-1]--;
        }
    }
    cout<<num;
}