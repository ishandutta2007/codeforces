#include <bits/stdc++.h>
#define DMAX 500009
using namespace std;

int a, b, n, t;
int v[DMAX];
int dp1[DMAX];
int dp2[DMAX];

int caut_bin(int dr, int st, int val)
{
    if(st==dr)
        return st;
    int mid=(st+dr)/2;
    if(val>=dp2[mid])
        return caut_bin(mid, st, val);
        return  caut_bin(dr, mid+1, val);
}

string s;

int solve(string s)
{
    for(int i=0;i<n;i++)
{
    if(s[i]=='h')
        v[i+1]=0;
    else v[i+1]=1;
}

dp1[1]=v[1]*b + 1;
for(int i=2;i<=n;i++)
    dp1[i]=dp1[i-1]+a+1+v[i]*b;

dp2[n+1]=-1000000009;
dp2[n]=1+v[n]*b;
for(int i=n-1;i>=1;i--)
    dp2[i]=dp2[i+1]+a+1+v[i]*b;

int index=1;
int sol=0;
while(index!=n && dp1[index]<=t)
{
    int cost=dp1[index];
    if(cost<=t && index>sol)
        sol=index;

    int cost2=dp1[index] + index*a;

    if(cost2<=t)
    {
        int c=t-cost2;
    int g=caut_bin(n+1, 1, c);//dp2[g]<=c

    if(index+n-g+1>sol)
        sol=index+n-g+1;
    }
    index++;
}
return sol;
}

int main()
{
cin>>n>>a>>b>>t;

cin>>s;
string s2=s;
string::iterator it=s.begin();
it++;
reverse(it, s.end());
int ans=max(solve(s), solve(s2));

cout<<min(ans, n)<<'\n';
    return 0;
}