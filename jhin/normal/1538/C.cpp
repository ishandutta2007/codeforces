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
            cin>>n>>x>>y;ans=0;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];

            }
            sort(a,a+n);

            for(int i=0;i<n;i++)
            {

                auto it=lower_bound(a,a+n,y-a[i]+1);
                int ind=it-a;
                if(ind>i)
                ans+=(ind-i-1);

            }

            //cout<<ans<<endl;
            for(int i=0;i<n;i++)
            {

                auto it=lower_bound(a,a+n,x-a[i]);
                int ind=it-a;
                if(ind>i)
                ans-=(ind-i-1);

            }
            cout<<ans<<endl;         //1 2 3 4 5 6






        }



        return 0;
        }