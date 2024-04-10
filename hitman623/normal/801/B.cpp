#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    string x,y,z;
    long i;
    cin>>x>>y;
    for(i=0;i<y.size();i++)
    if(y[i]>x[i]) {cout<<-1;exit(0);}
    cout<<y;
    return 0;
}