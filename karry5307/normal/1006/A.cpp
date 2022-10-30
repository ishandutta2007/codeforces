#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,num;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num;
        num%2?cout<<num<<" ":cout<<num-1<<" ";
    }
}