#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long a,b,c,d,i;
    cin>>a>>b>>c>>d;
    for(i=0;i<100000;++i)
    if((b-d+i*a)%c==0 && b-d+i*a>=0) {cout<<b+i*a;exit(0);}
    cout<<-1;
    return 0;
}