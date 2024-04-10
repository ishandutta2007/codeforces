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

        cin>>n;string st[n];
        map<char,vector<int> >mp;
        for(int i=0;i<n;i++)
        {
            cin>>st[i];
            map<char,int>tmp;
             int si=st[i].size();
            for(int j=0;j<si;j++)
            {
                tmp[st[i][j]]++;
            }
            for(char ch='a';ch<='e';ch++)
            {
                int num=si-tmp[ch];
                mp[ch].push_back(tmp[ch]-num);
            }

        }mx=0;
        for(char ch='a';ch<='e';ch++)
            {
                sort(mp[ch].begin(),mp[ch].end(),greater<int>());
                cnt=0;
                sum=0;
                for(int i=0;i<mp[ch].size();i++)
                {
                    sum+=mp[ch][i];
                    if(sum>0)cnt++;
                    else break;
                }
                mx=max(mx,cnt);
            }
            cout<<mx<<endl;



    }





















    return 0;
}