#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll maxn,minn,a,b,c;
int main()
{
    cin>>a>>b>>c;
    maxn=max(max(a,b),c);
    minn=min(min(a,b),c);
    cout<<maxn-minn;
}