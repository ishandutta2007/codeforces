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
        long long m,x,y,z,k,cnt,mn=3e9,mx,ans,a[500003],b[500003],c[500003];bool yes1,yes2;vector<long long>v;char ch;string st[102];
        int n;

        string s;
        int t;
        bool yes;


        int main()
        {


        ios_base::sync_with_stdio(false);


            cin>>t;
            while(t--)
            {
                cin>>n>>m; long long tmp[n+4][m+4];memset(tmp,0,sizeof tmp);
                for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                {
                    cin>>tmp[i][j];
                }
                for(int i=1;i<=n/2;i++)
                for(int j=1;j<=m/2;j++)
                {
                    a[0]=tmp[i][j];a[1]=tmp[n-i+1][j];
                    a[2]=tmp[i][m-j+1];a[3]=tmp[n-i+1][m-j+1];
                    sort(a,a+4);
                    int mid=(a[1]+a[2])/2;
                    int sm=0;
                    sm+=abs(a[0]-mid)+abs(a[1]-mid)+abs(a[2]-mid)+abs(a[3]-mid);
                    mid++;
                    int sm2=0;
                    sm2=abs(a[0]-mid)+abs(a[1]-mid)+abs(a[2]-mid)+abs(a[3]-mid);
                    ans+=min(sm,sm2);
                }
                if(n%2)
                {
                    for(int j=1;j<=m/2;j++)
                    {   int i=n/2+1;
                        int mid=tmp[i][j]+tmp[i][m-j+1];
                        mid/=2;
                        ans+=abs(mid-tmp[i][j])+abs(mid-tmp[i][m-j+1]);
                    }

                }
                if(m%2)
                {
                    for(int i=1;i<=n/2;i++)
                    {
                        int j=m/2+1;
                        int mid=tmp[i][j]+tmp[n-i+1][j];
                        mid/=2;
                        ans+=abs(mid-tmp[i][j])+abs(mid-tmp[n-i+1][j]);
                    }
                }
                cout<<ans<<endl;
                ans=0;
            }







        return 0;
        }