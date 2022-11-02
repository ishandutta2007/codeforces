#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=1;1;x++)
    {
        if(x%2==1)
            a-=x;
        else
            b-=x;
        if(a<0)
            cout<<"Vladik";
        if(b<0)
            cout<<"Valera";
        if(min(a,b)<0)
            break;
    }
    return 0;
}