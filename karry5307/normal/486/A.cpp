#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll num;
int main()
{
    cin>>num;
    if(num%2)
    {
        cout<<-((num+1)/2);
    }
    else
    {
        cout<<num/2<<endl;
    }
}