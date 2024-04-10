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
        int m,x,y,z,k,cnt,mn=3e9,mx,ans,a[500003],b[500003],c[500003];bool yes1,yes2;vector<long long>v;char ch;string st[102];


        string s;
        int t,n;
        bool yes;


        int main()
        {


        ios_base::sync_with_stdio(false);


            cin>>t;
            while(t--)
            {
                cin>>n>>k>>s;z=0;yes=true;
                for(int i=0;i<n;i++)
                {
                    if(s[i]=='W'&&i==0)z++,yes=false;
                    else if(i>0&&s[i]=='W'&&s[i-1]=='W')z+=2,yes=false;
                        else if(i>0&&s[i]=='W'&&s[i-1]=='L')z++,yes=false;
                }
                if(k==0){cout<<z<<endl;continue;}
                if(yes){mn=min(n,k);cout<<(mn-1)*2+1<<endl;continue;}
                int i=0;
                while(i<n){if(s[i]=='W')break;i++;}
                x=i;y=0;
                vector<int>tmp;
                while(1)
                {

                    while(i<n){if(s[i]=='W')i++;else break;}
                    int j=i;
                    if(i==n)break;
                    while(j<n){if(s[j]=='L')j++;else break;}
                    if(j<n){
                        tmp.push_back(j-i);
                    }
                    else
                    {
                        y=j-i;
                        break;
                    }
                    i=j;
                }
                sort(tmp.begin(),tmp.end());
                for(int i=0;i<tmp.size();i++)
                {
                    if(k>=tmp[i])
                    {
                        k-=tmp[i];
                        z+=2*tmp[i]+1;
                    }
                    else if(k!=0)
                        z+=2*k,k=0;
                }
                if(k>=x)z+=2*x,k-=x;
                else z+=2*k,k=0;
                if(k>=y)z+=2*y;
                else z+=2*k;
                 cout<<z<<endl;

            }








        return 0;
        }