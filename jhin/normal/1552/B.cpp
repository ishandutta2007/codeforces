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
int t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],sum;



string s,s1;

bool yes;





int main()
{

    cin>>t;
    while(t--)
    {

        cin>>n;
        int tmp[n][5];
        for(int i=0;i<n;i++)
        {
            cin>>tmp[i][0]>>tmp[i][1]>>tmp[i][2]>>tmp[i][3]>>tmp[i][4];
        }
        x=n-1;yes=false;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                cnt=0;
                for(int z=0;z<5;z++)
                {
                   if(tmp[i][z]<tmp[j][z])cnt++;
                }

                if(cnt<3){i=j-1;break;}
                else if(j==n-1){x=i;yes=true;break;}
            }
           // cout<<i<<" ";
            //cout<<yes<<endl;
            if(yes)break;
        }
        //cout<<endl;
        yes=true;
        //cout<<x<<endl;
          for(int i=0;i<n;i++)
        {
            if(i==x)continue;
            cnt=0;
            for(int z=0;z<5;z++)
                {
                   if(tmp[x][z]<tmp[i][z])cnt++;
                }
                if(cnt<3)yes=false;

        }
        if(yes)cout<<x+1<<endl;
        else cout<<-1<<endl;






    }






















    return 0;
}