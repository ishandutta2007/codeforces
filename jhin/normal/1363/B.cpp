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
        int m,n,x,y,z,k,mn=3e9,mx,ans,a[500003];vector<long long>v;char ch;

        string s;
        int t;
        bool yes;
set<pair<double,int>>st;

        int main()
        {

        ios_base::sync_with_stdio(false);

        cin>>t;
        while(t--)
        {
            string s;
            cin>>s;
            n=s.size();
            int c[n];int d[n];
            memset(c,0,sizeof c);memset(d,0,sizeof d);
            int cnt1=0,cnt2=0;int cnt3=1e9;
            if(n>2)
            {

                for(int i=0;i<n;i++)
                {
                    if(s[i]=='1')cnt1++;
                    else cnt2++;
                }

                for(int i=0;i<n;i++)
                {
                    if(i==0){if(s[i]=='1')c[0]=1;else c[0]=0;}
                    else
                    {
                        c[i]=c[i-1];
                        if(s[i]=='1')c[i]++;

                }}
                for(int i=0;i<n;i++)
                {
                    if(i==0){if(s[i]=='0')d[0]=1;else d[0]=0;}
                    else
                    {
                        d[i]=d[i-1];
                        if(s[i]=='0')d[i]++;

                }}
            for(int i=0;i<n-1;i++)
                {
                    int tmp=c[i],tmp2=c[n-1];
                    cnt3=min(cnt3,d[i]+(tmp2-tmp));
                    //cout<<d[i]<<"h "<<tmp2<<" "<<tmp<<endl;
                }
                for(int i=0;i<n-1;i++)
                {
                    int tmp=d[i+1],tmp2=d[n-1];
                    cnt3=min(cnt3,c[i]+(tmp2-tmp));
                    //cout<<c[i]<<" "<<tmp2<<" "<<tmp<<endl;
                }
                //cout<<endl;


            }
               cout<<min(min(cnt1,cnt2),cnt3)<<endl;








        }










        return 0;
        }