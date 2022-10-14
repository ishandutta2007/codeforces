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



ll my_pow(int x,int y)
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
set<int>numm;
int pfact(int x)
{ int cnt=0; if(x%2==0){while(x%2==0)x/=2,cnt++;numm.insert(2);}
for(int i=3;i*i<=x;i+=2)
if(x%i==0){while(x%i==0)x/=i,cnt++;numm.insert(i);}
if(x>1)cnt++,numm.insert(x);
return cnt;

}
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],sum;



string s;

bool yes;



int main()
{

 ios_base::sync_with_stdio(false);





        cin>>t;
        while(t--)
        {
            cin>>n;
            int tmp[10001][2];
            int tmb[n];
            memset(tmp,-1,sizeof tmp); memset(tmb,0,sizeof tmb);
            set<int>indx;
            for(int i=0;i<n;i++)
            indx.insert(i);
            for(int i=0;i<n;i++)
            {
               cin>>a[i];
               if(a[i]<0)
               {
                   int old=tmp[abs(a[i])][1];
                   if(old!=-1){
                    tmb[old]=-1;
                    tmb[i]=1;
                    tmp[abs(a[i])][1]=-1;
                    indx.erase(old);indx.erase(i);
                   }
                   else
                   {
                       old=tmp[abs(a[i])][0];
                   if(old!=-1){
                    tmb[old]=1;
                    tmb[i]=1;
                    tmp[abs(a[i])][0]=-1;
                    indx.erase(old);indx.erase(i);
                   }
                   else
                   {
                      tmp[abs(a[i])][1]=i;
                   }
                   }
               }
               else
               {
                   int old=tmp[abs(a[i])][0];
                   if(old!=-1){
                    tmb[old]=-1;
                    tmb[i]=1;
                    tmp[abs(a[i])][0]=-1;
                    indx.erase(old);indx.erase(i);
                   }
                   else
                   {
                       old=tmp[abs(a[i])][1];
                   if(old!=-1){
                    tmb[old]=1;
                    tmb[i]=1;
                    tmp[abs(a[i])][1]=-1;
                    indx.erase(old);indx.erase(i);
                   }
                   else
                   {
                      tmp[abs(a[i])][0]=i;
                   }
                   }
               }

            }
            int si=indx.size();
            if(si%2)
            {
            if(si!=1)
            {

                auto it=indx.begin();

                int ind0=*it;
                it++;
                int ind1=*it;
                it++;
                int ind2=*it;

                    tmb[ind0]=abs(a[ind1]*a[ind2]);
                    tmb[ind1]=abs(a[ind0]*a[ind2]);
                    tmb[ind2]=abs(a[ind0]*a[ind1]);
                  if((a[ind0]>0&&a[ind1]>0&&a[ind2]>0)||(a[ind0]<0&&a[ind1]<0&&a[ind2]<0))tmb[ind0]*=-2;
                  else
                  {
                      if(a[ind0]>0&&a[ind1]<0&&a[ind2]<0||(a[ind0]<0&&a[ind1]>0&&a[ind2]>0))tmb[ind0]*=2;
                      else if(a[ind0]>0&&a[ind1]>0&&a[ind2]<0||(a[ind0]<0&&a[ind1]<0&&a[ind2]>0))tmb[ind2]*=2;
                      else if(a[ind0]>0&&a[ind1]<0&&a[ind2]>0||(a[ind0]<0&&a[ind1]>0&&a[ind2]<0))tmb[ind1]*=2;
                  }
                  it=indx.begin();indx.erase(it);it=indx.begin();indx.erase(it);it=indx.begin();indx.erase(it);

            }
            if(indx.size()==1)
            {
                int ind2=*indx.begin();
                int ind0=0;
                if(ind2==0)ind0++;
                int ind1=ind0+1;
                for(;ind1<n;ind1++)
                    if(abs(a[ind1])==abs(a[ind0]))break;



                    tmb[ind0]=abs(a[ind1]*a[ind2]);
                    tmb[ind1]=abs(a[ind0]*a[ind2]);
                    tmb[ind2]=abs(a[ind0]*a[ind1]);
                  if((a[ind0]>0&&a[ind1]>0&&a[ind2]>0)||(a[ind0]<0&&a[ind1]<0&&a[ind2]<0))tmb[ind0]*=-2;
                  else
                  {
                      if(a[ind0]>0&&a[ind1]<0&&a[ind2]<0||(a[ind0]<0&&a[ind1]>0&&a[ind2]>0))tmb[ind0]*=2;
                      else if(a[ind0]>0&&a[ind1]>0&&a[ind2]<0||(a[ind0]<0&&a[ind1]<0&&a[ind2]>0))tmb[ind2]*=2;
                      else if(a[ind0]>0&&a[ind1]<0&&a[ind2]>0||(a[ind0]<0&&a[ind1]>0&&a[ind2]<0))tmb[ind1]*=2;
                  }


            }
            }
            auto it=indx.begin();
            for(;it!=indx.end();)
            {
                if(indx.size()==1)break;
                auto it2=it;
                it++;
                int i=*it;
                int j=*it2;
                if(a[i]*a[j]<0)
                    tmb[i]=abs(a[j]),tmb[j]=abs(a[i]);
                else tmb[i]=-abs(a[j]),tmb[j]=abs(a[i]);
                indx.erase(it2);
                it2=it;
                it++;
                indx.erase(it2);
            }



            for(int i=0;i<n;i++)
                cout<<tmb[i]<<" ";cout<<endl;






        }













    return 0;
}