#include <bits/stdc++.h>
#define ONE 1000000
using namespace std;
int n, k, f, s, s2;

map <int, int> m;

int main()
{
cin>>n;
int it=0;
for(int i=1;i<=n;i++)
{
    cin>>k;
    s+=k;
}

for(int i=1;i<n;i++)
{
    cin>>k;
    s-=k;
    s2+=k;
}

for(int i=1;i<n-1;i++)
{
    cin>>k;
    s2-=k;
}

cout<<s<<'\n'<<s2<<'\n';

    return 0;

}