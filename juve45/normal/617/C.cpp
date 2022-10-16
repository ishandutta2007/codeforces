#include <bits/stdc++.h>

#define DMAX 2015

using namespace std;

vector <long long>a, b;
long long n, r, r2, ans=1LL<<62;

struct Point{
    long long x, y;
}P[DMAX], R1, R2;

long long dist2(Point a, Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

class cmpa
{
    public:
    bool operator()(const long long &i, const long long &j)
    {
        return (dist2(P[i], R1) < dist2(P[j], R1));
    }
};


class cmpb
{
    bool operator()(const long long &i, const long long &j)
    {
        return dist2(P[i], R2)<dist2(P[j], R2);
    }
};

int main()
{
cin>>n>>R1.x>>R1.y>>R2.x>>R2.y;

for(long long i=1;i<=n;i++)
{
    cin>>P[i].x>>P[i].y;
    a.push_back(i);
    b.push_back(i);
}

sort(a.begin(), a.end(), cmpa() );

r=0;
r2=0;
for(long long j=0;j<n;j++)
{
    if(r2<dist2(P[a[j]], R2))
    r2=dist2(P[a[j]], R2);
}
if(ans>r+r2)
    ans=r+r2;

for(long long i=0;i<n;i++)
{
    r=dist2(P[a[i]], R1);
    r2=0;
    for(long long j=i+1;j<n;j++)
    {
        if(r2<dist2(P[a[j]], R2))
        r2=dist2(P[a[j]], R2);
    }
    if(ans>r+r2)
        ans=r+r2;
}
cout<<ans<<'\n';
    return 0;
}