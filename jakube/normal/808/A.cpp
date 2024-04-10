#include<bits/stdc++.h>
using namespace std;

int pow(int x, int v) {
    return v ? x*pow(x, v-1) : 1;
}

int main()
{
    int y,count=0,x,d;
    cin>>y;
    d=y;
    while(y!=0)
    {
        count++;
        if((y/10)==0)
        x=y;
        y=y/10;
    }
    if(count==1)
    cout<<"1";
    else
    {
        x=(x+1)*pow(10,count-1);
        cout<<x-d;
    }
    return 0;
}