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
        long long m,x,n,y,z,k,mn=3e9,mx,ans,a[500001],b[500003];vector<int>v;char ch;

        string s;
        int t;
        bool yes;




        int main()
        {

        ios_base::sync_with_stdio(false);

        cin>>t;
        while(t--)
        {
           cin>>n>>m>>k;vector<long long>tmp1(n),tmp2(m),tmp3(k);mn=3e18;
           for(int i=0;i<n;i++)cin>>tmp1[i];
           for(int i=0;i<m;i++)cin>>tmp2[i];
           for(int i=0;i<k;i++)cin>>tmp3[i];
           sort(tmp1.begin(),tmp1.end());
           sort(tmp2.begin(),tmp2.end());
           sort(tmp3.begin(),tmp3.end());
           for(int i=0;i<n;i++)
           {
               auto it=lower_bound(tmp2.begin(),tmp2.end(),tmp1[i]);
               long long tmpr1=0,tmpr2=0,tmpr3=0,tmpr4=0;
               if(it!=tmp2.end())
               tmpr1=*it;
               if(it!=tmp2.begin()){it--;
               tmpr2=*it;
               }
               auto it2=lower_bound(tmp3.begin(),tmp3.end(),tmp1[i]);

               if(it2!=tmp3.end())
               tmpr3=*it2;
               if(it2!=tmp3.begin()){it2--;
               tmpr4=*it2;
               }
               if(tmpr1!=0)
               {
                   if(tmpr3!=0)
                   {
                    ans=(tmp1[i]-tmpr1)*(tmp1[i]-tmpr1)+(tmpr1 -tmpr3)*(tmpr1 -tmpr3)+(tmp1[i]-tmpr3)*(tmp1[i]-tmpr3);
                    mn=min(mn,ans);
                   }
                   if(tmpr4!=0)
                    {
                    ans=(tmp1[i]-tmpr1)*(tmp1[i]-tmpr1)+(tmpr1 -tmpr4)*(tmpr1 -tmpr4)+(tmp1[i]-tmpr4)*(tmp1[i]-tmpr4);
                    mn=min(mn,ans);
                   }
               }
               if(tmpr2!=0)
               {
                   if(tmpr3!=0)
                   {
                    ans=(tmp1[i]-tmpr2)*(tmp1[i]-tmpr2)+(tmpr2 -tmpr3)*(tmpr2 -tmpr3)+(tmp1[i]-tmpr3)*(tmp1[i]-tmpr3);
                    mn=min(mn,ans);
                   }
                   if(tmpr4!=0)
                    {
                    ans=(tmp1[i]-tmpr2)*(tmp1[i]-tmpr2)+(tmpr2-tmpr4)*(tmpr2 -tmpr4)+(tmp1[i]-tmpr4)*(tmp1[i]-tmpr4);
                    mn=min(mn,ans);
                   }
               }



           }
          //// cout<<mn<<" h";
        for(int i=0;i<m;i++)
           {
               auto it=lower_bound(tmp1.begin(),tmp1.end(),tmp2[i]);
               long long tmpr1=0,tmpr2=0,tmpr3=0,tmpr4=0;
               if(it!=tmp1.end())
                tmpr1=*it;
               if(it!=tmp1.begin()){it--;tmpr2=*it;}
               auto it2=lower_bound(tmp3.begin(),tmp3.end(),tmp2[i]);

               if(it2!=tmp3.end())
                tmpr3=*it2;
               if(it2!=tmp3.begin()){it2--;tmpr4=*it2;}
                if(tmpr1!=0)
               {
                   if(tmpr3!=0)
                   {
                    ans=(tmpr1-tmp2[i])*(tmpr1-tmp2[i])+(tmp2[i] -tmpr3)*(tmp2[i] -tmpr3)+(tmpr1-tmpr3)*(tmpr1-tmpr3);
                    mn=min(mn,ans);
                   }
                   if(tmpr4!=0)
                    {
                    ans=(tmpr1-tmp2[i])*(tmpr1-tmp2[i])+(tmp2[i] -tmpr4)*(tmp2[i] -tmpr4)+(tmpr1-tmpr4)*(tmpr1-tmpr4);
                    mn=min(mn,ans);
                   }
               }
               if(tmpr2!=0)
               {
                   if(tmpr3!=0)
                   {
                     ans=(tmpr2-tmp2[i])*(tmpr2-tmp2[i])+(tmp2[i] -tmpr3)*(tmp2[i] -tmpr3)+(tmpr2-tmpr3)*(tmpr2-tmpr3);
                    mn=min(mn,ans);
                   }
                   if(tmpr4!=0)
                   {
                     ans=(tmpr2-tmp2[i])*(tmpr2-tmp2[i])+(tmp2[i] -tmpr4)*(tmp2[i] -tmpr4)+(tmpr2-tmpr4)*(tmpr2-tmpr4);
                    mn=min(mn,ans);
                   }
               }
           }
//cout<<mn<<" h";
        for(int i=0;i<k;i++)
           {
               auto it=lower_bound(tmp1.begin(),tmp1.end(),tmp3[i]);
               long long tmpr1=0,tmpr2=0,tmpr3=0,tmpr4=0;
               if(it!=tmp1.end())
                tmpr1=*it;
               if(it!=tmp1.begin()){it--;tmpr2=*it;}
               auto it2=lower_bound(tmp2.begin(),tmp2.end(),tmp3[i]);

               if(it2!=tmp2.end())
                tmpr3=*it2;
               if(it2!=tmp2.begin()){it2--;tmpr4=*it2;}
                if(tmpr1!=0)
               {
                   if(tmpr3!=0)
                   {
                    ans=(tmpr1-tmpr3)*(tmpr1-tmpr3)+(tmpr3-tmp3[i])*(tmpr3 -tmp3[i])+(tmpr1-tmp3[i])*(tmpr1-tmp3[i]);
                    mn=min(mn,ans);
                   }
                   if(tmpr4!=0)
                    {
                    ans=(tmpr1-tmpr4)*(tmpr1-tmpr4)+(tmpr4-tmp3[i])*(tmpr4 -tmp3[i])+(tmpr1-tmp3[i])*(tmpr1-tmp3[i]);

                    mn=min(mn,ans);
                   }
               }
               if(tmpr2!=0)
               {
                    if(tmpr3!=0)
                   {
                    ans=(tmpr2-tmpr3)*(tmpr2-tmpr3)+(tmpr3-tmp3[i])*(tmpr3 -tmp3[i])+(tmpr2-tmp3[i])*(tmpr2-tmp3[i]);
                    mn=min(mn,ans);
                   }
                   if(tmpr4!=0)
                    {
                    ans=(tmpr2-tmpr4)*(tmpr2-tmpr4)+(tmpr4-tmp3[i])*(tmpr4 -tmp3[i])+(tmpr2-tmp3[i])*(tmpr2-tmp3[i]);

                    mn=min(mn,ans);
                   }
               }



           }
           cout<<mn<<endl;

        }













        return 0;
        }