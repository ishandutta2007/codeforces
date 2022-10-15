/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    int year=0;
    while(1)
    {
        year++;
        a*=3;
        b*=2;
        if(a>b) break;
    }

    cout<<year<<endl;
    return 0;
}