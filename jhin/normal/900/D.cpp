// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define ll long long
const int s=1e9+7;
vector<int> p;
map<int,int> factors;
int n,i,b,c,d,x,y,del,cnt1,cnt2,max1,max2,sum;
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%s,y>>=1)
        if(y&1)num=((num%s)*i)%s;
    return num%s;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
void fix(int x)
{
    for (auto it=factors.begin();(it->first)<x;it++)
        if(x%(it->first)==0)factors[x]=factors[x]+((factors[x]<(it->second))? s:0)-(it->second);
}

int main()
{
    cin>>x>>y;if(y%x)return cout<<0,0;
    y/=x;
    for(i=1;i*i<=y;i++)
    if(y%i==0)factors[i]=my_pow(2,i-1),factors[y/i]=my_pow(2,(y/i)-1);
    for(auto it=factors.begin();it!=factors.end();it++)
        fix(it->first);
    cout<<factors[y];
/*
1 1 = 1
1 2 = 2 - 1 = 1
1 3 = 4 - 1 = 3
1 4 = 8 - 1 - 1 = 6
1 5 = 16 - 1 = 15
1 6 = 32 -3 -1= 28
1 7 = 64 -1=63
1 8 = 128 -6 -1 -1=120*/
    return 0;
}