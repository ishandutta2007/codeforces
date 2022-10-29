#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;

int main()
{
    long a,b,i=1;
    cin>>a>>b;
    while(1)
    {
        if(i%2)
        {
            if(a>=i)
            a-=i;
            else {cout<<"Vladik";exit(0);}
        }
        else
        {
            if(b>=i)
            b-=i;
            else {cout<<"Valera";exit(0);}
        }
        i++;
    }
    return 0;
}