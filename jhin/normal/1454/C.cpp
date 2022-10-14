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
        int m,n,x,y,z,k,cnt,mn=3e9,mx,ans,a[500003],b[500003],c[500003];bool yes1,yes2;vector<long long>v;char ch;string st[102];


        string s;
        int t,x1,y1,z1;
        bool yes;



        int main()
        {

        ios_base::sync_with_stdio(false);


        cin>>t;
        while(t--)
        {

            cin>>n;
            map<int,int>myp;
            for(int i=0;i<n;i++)
            {cin>>a[i];
            myp[a[i]]=0;
            }
            if(n==1)cout<<"0\n";
            else{

            for(int i=0;i<n;i++)
            {
                if(i==n-1&&i>0&&a[i]!=a[i-1]&&myp[a[i]]==0)myp[a[i]]++;
                else if(i<n-1){
                        yes=false;
                if(a[i]!=a[i+1]){myp[a[i]]++;yes=true;}
                if((myp[a[i]]==0||(myp[a[i]]==1&&yes))&&i>0&&a[i]!=a[i-1])myp[a[i]]++;


                }
                //cout<<myp[a[i]]<<" ";
            }
            mn=1e9;

            for(int i=0;i<n;i++)
            {
                mn=min(mn,myp[a[i]]);

            }
            cout<<mn<<"\n";
            }




        }



        return 0;
        }