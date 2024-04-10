// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
const int mod=1e9+7;
vector<int> p;

ll n,x,y,sum,cnt1,cnt2;
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=((num%mod)*i)%mod;
    return num%mod;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}

char a[1001];
int fb[1000000];
int main()
{
   ios_base::sync_with_stdio(false);
   cin>>n;
   fb[1]=1;
   for(int i=2;fb[i-1]<=1000;i++)
   {
       fb[i]=fb[i-1]+fb[i-2];
   }
   for(int i=0;i<=n;i++)
   {
       a[i]='o';
   }
   for(int i=1;fb[i]<=n;i++)
   {
     a[fb[i]]='O';
   }
   for(int i=1;i<=n;i++)
    cout<<a[i];


    return 0;
}