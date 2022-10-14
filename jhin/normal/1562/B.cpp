#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pi =pair<int,int>;

#define f first

#define s second

# define be(v) (v).begin(),(v).end()

#define eb(v)  (v).begin(),(v).end(),greater<int>()



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
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],sum;



string s;

bool yes;



int main()
{

 ios_base::sync_with_stdio(false);



            char pr[4]={'2','3','5','7'};
            vector<string>prm;
            for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                string tmp="";
                tmp+=pr[i];tmp+=pr[j];
                int nu=int(pr[j]-'0');
                int nu2=int(pr[i]-'0');
                nu+=nu2*10;
                bool isp=true;
                for(int i=2;i<nu;i++)if(nu%i==0)isp=false;
                if(!isp)
                prm.push_back(tmp);
            }
            cin>>t;
            while(t--)
            {
                cin>>n>>s;
                bool ispr=true;
                string anst="";
                for(int i=0;i<n;i++)
                {
                    if(s[i]!='2'&&s[i]!='3'&&s[i]!='5'&&s[i]!='7'){anst=s[i];break;}

                }
                if(anst.empty())
                {
                    for(int i=0;i<prm.size();i++)
                    {
                        string tmp=prm[i];
                        for(int j=0;j<n;j++)
                        {
                            if(s[j]==tmp[0])
                            {
                                for(int z=j+1;z<n;z++)
                                {
                                    if(s[z]==tmp[1])anst=tmp;
                                }
                            }
                        }
                    }
                }
                cout<<anst.size()<<endl;
                cout<<anst<<endl;



            }
























    return 0;
}