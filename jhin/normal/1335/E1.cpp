        #include <bits/stdc++.h>

        using namespace std;




        const int mod=998244353;
        vector<long long> p;


        int ho,mi,se,ho1,mi1,cnt;
        void fix_time()
        {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
            if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
            if(ho<0)ho+=24;if(ho>=24)ho-=24;
        }
        unsigned long long my_pow(int x,int y)
        {  unsigned  long long num=1;
            for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
                if(y&1)num=(num*i);
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
        void pfact(long long xx)
        {   if(xx%2==0){p.push_back(2);while(xx%2==0)xx/=2,cnt++;vv.push_back(cnt);}
                for(long long i=3;i*i<=xx;i+=2)
                        if(xx%i==0){cnt=0;p.push_back(i);while(xx%i==0)xx/=i,cnt++;vv.push_back(cnt);}
                            if(xx>1)p.push_back(xx),cnt++,vv.push_back(1);
        }
        long long gcd(long long a , long long b)
        {
          if(b==0) return a;
                   a%=b;
            return gcd(b,a);
        }
        int m,x,n,y,z,k,mn=3e9,mx,ans,a[500001],b[500003];vector<int>v;char ch;

        string s;
        int t;
        bool yes;




        int main()
        {

        ios_base::sync_with_stdio(false);

        cin>>t;
        while(t--)
        {
            cin>>n;
            for(int i=0;i<n;i++)cin>>a[i];mx=0;
            if(n==1)cout<<1<<endl;
            else{
            int mp[2004][27];
            for(int i=0;i<n;i++)
            {
                if(i==0)
                {
                    for(int j=0;j<27;j++)
                    {
                        mp[i][j]=0;
                    }
                    mp[i][a[i]]++;
                }

                else
                {
                    for(int j=0;j<27;j++)
                    {
                        mp[i][j]=mp[i-1][j];
                    }
                    mp[i][a[i]]++;
                }
                mx=max(mx,mp[i][a[i]]);
            }
            for(int i=0;i<n-1;i++)
            {
                for(int j=i+1;j<n;j++){
                int tmp[27],tmp2[27];
                int mx1=0,mx2=0,mx3=0;mn=1e9;
                for(int z=0;z<27;z++)
                {

                    tmp[z]=mp[n-1][z]-mp[j-1][z];
                }
                for(int z=0;z<27;z++)
                {
                    tmp2[z]=mp[j-1][z]-mp[i][z];
                }
                for(int z=0;z<27;z++)
                {
                    mn=min(tmp[z],mp[i][z]);
                    mx1=max(mx1,2*mn);
                    mx2=max(mx2,tmp2[z]);
                    //cout<<mx1<<" "<<mx2<<endl;
                }
                //cout<<mx1<<" h"<<mx2<<endl;
                mx=max(mx1+mx2,mx);

            }}
            if(mx==0)mx=1;
            cout<<mx<<endl;
            }

        }













        return 0;
        }