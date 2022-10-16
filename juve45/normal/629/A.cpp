#include <bits/stdc++.h>

using namespace std;

char s[110][110];
long long l[110], r[110];
long long n;
int main()
{
cin>>n;
long long sum=0;
for(long long i=0;i<n;i++)
    cin>>s[i];

for(long long i=0;i<n;i++)
{
for(long long j=0;j<n;j++)
    {
    if(s[i][j]=='C')
l[i]++,
r[j]++;}
}

for(long long i=0;i<=n;i++)
    sum+=((l[i]*(l[i]-1))/2)+(((r[i]-1)*r[i])/2);
cout<<sum<<'\n';

return 0;
}