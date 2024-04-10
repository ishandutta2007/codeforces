#include<bits/stdc++.h>
using namespace std;
int num,res; 
int main()
{
    cin>>num;
    res=num%10;
    num/=10;
    if(res-5>=0)
    {
        num++;
    }
    cout<<num*10;
}