#include <bits/stdc++.h>
#define maxn 101
using namespace std;

long long a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);

    cin>>a>>b;

    while( a>=2*b || b>=2*a ){

        if(a==0||b==0) break;

        if(a>=2*b) a%=(2*b);

        if(a==0||b==0) break;

        if(b>=2*a) b%=(2*a);

    }

    cout<<a<<' '<<b<<'\n';

    return 0;
}