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
int t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003];



string s,s1;
char ch;
bool yes;





int main()
{

    cin>>t;
    while(t--)
    {

        cin>>n>>k;
        map<int,vector<int> >mp;x=0;y=0;
        map<int,int>mp2;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]].push_back(i);
        }
        int cnt=1;


        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int i=it->first;

            if(mp[i].size()>=k)
            {


            for(int j=0;j<mp[i].size();j++)
            {

                int z=mp[i][j];
                if(j<k)a[z]=j+1;
                else a[z]=0;
            }
            }
           else
            {
               for(int j=0;j<mp[i].size();j++)
            {

                int z=mp[i][j];
                a[z]=cnt++;
                if(cnt>k)cnt=1;
            }
            }

        }
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0)
            mp2[a[i]]++;
        }

        mn=1e9;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0)
            mn=min(mn,mp2[a[i]]);
        }

        for(int i=1;i<k;i++)
        {

            if(mp2[i]!=mn)
            {
                for(int j=0;j<n;j++)
                if(a[j]==i){a[j]=0;break;}
            mp2[i]--;
            }

        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";cout<<endl;



    }





















    return 0;
}