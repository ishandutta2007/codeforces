#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,num;
int main()
{
    cin>>cnt>>num;
    num%=(cnt*(cnt+1)/2);
    for(register int i=1;i<=cnt;i++)
    {
        if(num<i)
        {
            cout<<num<<endl;
            return 0;
        }
        num-=i;
    }
}
//code