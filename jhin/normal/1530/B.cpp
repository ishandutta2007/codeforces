#include <bits/stdc++.h>

using namespace std;

using ll = long long;



const int mod=1e9+7;
vector<ll> p;



ll my_pow(int x,int y)
{  ll num=1;
    for(ll i=x;y>0;i=(i*i),y>>=1)
        if(y&1){num=(num%mod*i%mod)%mod;}
            return num;
}

bool prime[100000001];
void sieve(){
for(int i=2;i<=1000000;i+=2)
prime[i]=false,prime[i-1]=true;
prime[2]=true;
for(int i=3;i*i<=1000000;i+=2)
    if(prime[i])
        for(int j=i*i;j<=1000000;j+=2*i)
            prime[j]=false;
            }


ll gcd(ll a , ll b)
{
  if(b==0) return a;
           a%=b;
    return gcd(b,a);
}

int pfact(int x)
{ int cnt=0; if(x%2==0){while(x%2==0)x/=2,cnt++;}
for(int i=3;i*i<=x;i+=2)
if(x%i==0){while(x%i==0)x/=i,cnt++;}
if(x>1)cnt++;
return cnt;

}
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003];



string s;
char ch;
bool yes;






int main()
{

    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        char ar[x][y],ar2[x][y];
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
                ar[i][j]='0',ar2[i][j]='0';
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<y;i+=2)ar[0][i]='1',cnt1++;
        for(int i=1;i<x;i++)
        {
            if(ar[i-1][y-1]!='1'&&ar[i-1][y-2]!='1')ar[i][y-1]='1',cnt1++;
        }
        for(int i=y-2;i>=0;i--)
        {
            if(ar[x-1][i+1]!='1'&&ar[x-2][i+1]!='1')ar[x-1][i]='1',cnt1++;
        }
        for(int i=x-2;i>0;i--)
        {
            if(ar[i+1][0]!='1'&&ar[i+1][1]!='1'&&ar[i-1][1]!='1'&&ar[i-1][0]!='1')ar[i][0]='1',cnt1++;
        }
        for(int i=1;i<y;i+=2)ar2[0][i]='1',cnt2++;
        for(int i=1;i<x;i++)
        {
            if(ar2[i-1][y-1]!='1'&&ar2[i-1][y-2]!='1')ar2[i][y-1]='1',cnt2++;
        }
        for(int i=y-2;i>=0;i--)
        {
            if(ar2[x-1][i+1]!='1'&&ar2[x-2][i+1]!='1')ar2[x-1][i]='1',cnt2++;
        }
        for(int i=x-2;i>0;i--)
        {
            if(ar2[i+1][0]!='1'&&ar2[i+1][1]!='1'&&ar2[i-1][1]!='1'&&ar2[i-1][0]!='1')ar2[i][0]='1',cnt2++;
        }
        if(cnt1>cnt2)
          for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
                cout<<ar[i][j];cout<<endl;
        }
        else
          for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
                cout<<ar2[i][j];cout<<endl;
        }


    }






    return 0;
}