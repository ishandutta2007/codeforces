// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;

int x,y,cnt1,cnt2,k,n,m,t,d,sum,op;int ans=1e7;ll z;
int ho,mi,se;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
}
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=((num%mod)*i)%mod;
    return num%mod;
}
bool prime[1000001];
void sieve(){
    for(int i=2;i<=1000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=1000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=1000000;j+=2*i)
                prime[j]=false;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
map<ll,ll> pos;vector<ll> nums;
ll mx=1e18,ii=1e6,l,r,ope;double test;bool used[1000003],havroot[1000003];
int main()
{
ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=2;i<=1000;i++)
        havroot[i*i]=true;
    for(ll i=2;i<=ii;i++)
    {
        if(!used[i]&&!havroot[i])
        {
            ll j=i;
            while(double(j)*i<=double(mx)/i){ope++;j*=i*i;nums.push_back(j);if(j<=1000000)used[j]=true;}
        }

    }sort(nums.begin(),nums.end());

   for(int i=0;i<n;i++)
   {
       cin>>l>>r;test=sqrt(l);
       ll ans=int(sqrt(r))-int(test);if(test==double(int(test)))ans++;
       auto tmp=lower_bound(nums.begin(),nums.end(),r);
       if(*tmp!=r)tmp--;
       cout<<ans+(tmp-lower_bound(nums.begin(),nums.end(),l))+1<<endl;
   }



    return 0;
}