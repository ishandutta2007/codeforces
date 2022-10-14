#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pi =pair<int,int>;

#define f first

#define s second

# define be(v) (v).begin(),(v).end()

#define eb(v)  (v).begin(),(v).end(),greater<int>()



const int mod=998244353;
vector<ll> p;



ll my_pow(ll x,ll y)
{  ll num=1;
    for(ll i=x;y>0;i=(i*i),y>>=1)
        if(y&1){num=(num*i);}
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
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],sum;



string s;

bool yes;



int main()
{

 ios_base::sync_with_stdio(false);





        cin>>n>>t>>s;
        for(int i=0;i<n-2;i++)
        if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')cnt++;

        while(t--)
        {
            char ch;
            int i;
            cin>>i>>ch;
            i--;
            if(i<n-2)
            {
               if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')cnt--;
            }
            if(i<n-1&&i>0)
            if(s[i-1]=='a'&&s[i]=='b'&&s[i+1]=='c')cnt--;

            if(i>1)
            if(s[i-2]=='a'&&s[i-1]=='b'&&s[i]=='c')cnt--;


            if(ch=='a'&&i<n-2)
            {

                if(s[i+1]=='b'&&s[i+2]=='c')cnt++;


            }
            if(ch=='b'&&i<n-1&&i>0)
            {

                if(s[i-1]=='a'&&s[i+1]=='c')cnt++;

            }
            if(ch=='c'&&i>1)
            {

                if(s[i-2]=='a'&&s[i-1]=='b')cnt++;

            }
            cout<<cnt<<endl;
            s[i]=ch;
        }













    return 0;
}