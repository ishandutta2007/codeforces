#include <bits/stdc++.h>

        using namespace std;




        const int mod=998244353;
        vector<long long> p;


        int ho,mi,se,ho1,mi1;
        void fix_time()
        {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
            if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
            if(ho<0)ho+=24;if(ho>=24)ho-=24;
        }
        unsigned long long my_pow(int x,int y)
        {  unsigned  long long num=1;
            for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
                if(y&1){num=(num%mod*i%mod)%mod;}
                    return num;
        }

        bool prime[10000001],prime2[1000001];
        void sieve(){
        for(int i=2;i<=10000000;i+=2)
        prime[i]=false,prime[i-1]=true;
        prime[2]=true;
        for(int i=3;i*i<=10000000;i+=2)
            if(prime[i])
                for(int j=i*i;j<=10000000;j+=2*i)
                    prime[j]=false;
                    }
        vector<long long>vv,vv1;

        long long gcd(long long a , long long b)
        {
          if(b==0) return a;
                   a%=b;
            return gcd(b,a);
        }
       long long cnt=0;
    void pfact(long long x)
    {   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
    for(long long i=3;i*i<=x;i+=2)
    if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
    if(x>1)p.push_back(x),cnt++,vv.push_back(1);
    }
        long long m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500003],c[500003],d[500003];vector<long long>v;char ch;



        string s;



        int t;
        bool yes;




        int main()
        {

        ios_base::sync_with_stdio(false);




       cin>>t;


       while(t--)
       {
          cin>>n;mn=1e9;vector<int>vcs[4];
          for(int i=0;i<n;i++)
          {cin>>a[i];mn=min(mn,a[i]);}
          for(int i=0;i<n;i++)
          {if(mn==a[i]){x=i;break;}}
          int cnt=mn;
          if(mn!=a[0])
          {
              vcs[0].push_back(1);vcs[1].push_back(x+1);vcs[2].push_back(mn);vcs[3].push_back(mn+x);
          }
          for(int i=1;i<n;i++)
          {
              vcs[0].push_back(1);vcs[1].push_back(i+1);vcs[2].push_back(mn);vcs[3].push_back(mn+i);
          }
          cout<<vcs[0].size()<<endl;
          for(int i=0;i<vcs[0].size();i++)
            cout<<vcs[0][i]<<" "<<vcs[1][i]<<" "<<vcs[2][i]<<" "<<vcs[3][i]<<"\n";



       }

        return 0;
        }