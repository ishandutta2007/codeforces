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

int getsum(long long xx)
{
    long long ssum=0;
    while(xx)
    {
       ssum+=xx%10;
       xx/=10;
    }
    return ssum;
}


        int main()
        {

        ios_base::sync_with_stdio(false);




       cin>>t;


       while(t--)
       {
          cin>>n>>x;
          multiset<int>st;
          int tmp=x;

          int arr[32],arr2[32];
          memset(arr,0,sizeof arr);memset(arr2,0,sizeof arr2);
          cnt=0;
          while(tmp)
          {
             if(tmp%2)arr[cnt]++;
             cnt++;tmp/=2;
          }
          for(int i=0;i<n;i++)
          {
              cin>>y;cnt=0;
              while(y)
              {

                  y/=2;
                  cnt++;
              }
              arr2[cnt-1]++;
          }
          cnt=0;
          while(1)
          {
              for(int i=30;i>=0;i--)
              {
                  if(arr[i]&&arr2[i])arr2[i]--;

                  else if(arr[i]&&!arr2[i])
                  {
                      int num=my_pow(2,i);
                      for(int j=i-1;j>=0;j--)
                      {
                          while(arr2[j]&&num>0)
                          {
                              int mnu=my_pow(2,j);
                              if(num-mnu>=0)num-=mnu,arr2[j]--;
                              else break;
                          }
                          if(arr2[j])break;
                      }
                  }
              }
              cnt++;
              yes=true;
              for(int i=0;i<31;i++)
                if(arr2[i])yes=false;
              if(yes)break;
          }
          cout<<cnt<<endl;



       }

        return 0;
        }