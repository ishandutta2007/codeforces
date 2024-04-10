#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll num;
int main()
{
    for(register int i=0;i<5;i++)
    {
        for(register int j=0;j<5;j++)
        {
            cin>>num;
            if(num)
            {
                cout<<abs(i-2)+abs(j-2);
                return 0;
            }
        }
    }
}