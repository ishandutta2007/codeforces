#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,a,b,i,m,s=1000000009;
    char x[100001];
    cin>>n>>a>>b;
    cin>>x;
    if(x[a-1]==x[b-1]) cout<<0;
    else cout<<1;
    return 0;
}