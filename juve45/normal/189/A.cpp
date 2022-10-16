#include <bits/stdc++.h>

using namespace std;
int n, a, b, c, sol[8020];
int main()
{
cin>>n>>a>>b>>c;

int m=min(a, b);
m=min(m, c);
sol[a]=1;
sol[b]=1;
sol[c]=1;
for(int i=m;i<=n;i++)
{
    if(!sol[i]) continue;
    sol[i+a]=max(sol[i+a], sol[i]+1);
    sol[i+b]=max(sol[i+b], sol[i]+1);
    sol[i+c]=max(sol[i+c], sol[i]+1);
}

cout<<sol[n];

    return 0;
}