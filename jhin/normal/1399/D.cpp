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

        long long gcd(long long a , long long b)
        {
          if(b==0) return a;
                   a%=b;
            return gcd(b,a);
        }
        long long m,n,x,y,z,k,cnt,mn=3e9,mx,ans,a[500003],b[500003],c[500003];vector<long long>v;char ch;


        string s;
        int t;
        bool yes;


        int main()
        {

        ios_base::sync_with_stdio(false);

        cin>>t;
        while(t--)
        {
            cin>>n>>s;set<int> zer,on;int st[n];memset(st,0,sizeof st);
            st[0]=1;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='0')zer.insert(i);
                else on.insert(i);
            }
            int cnt=1;
            while(1)
            {

                auto it=zer.begin();
                auto it2=on.begin();
                if(it2==on.end())
                {
                    if(it==zer.end())break;
                    else{
                        int ind=*it;
                            st[ind]=cnt;cnt++;
                        zer.erase(it);

                    }
                }
                else if(it==zer.end())
                {
                   if(it2==on.end())break;
                    else{
                        int ind=*it2;
                            st[ind]=cnt;cnt++;
                        on.erase(it2);

                    }
                }
                else{
                int zero=*it,oe=*it2;
                if(zero<oe)
                {
                   while(1)
                   {

                       zer.erase(it);st[zero]=cnt;
                       it2=on.lower_bound(zero);
                       if(it2==on.end())break;
                       else
                       {
                           oe=*it2;st[oe]=cnt;on.erase(it2);
                           it=zer.lower_bound(oe);
                           if(it==zer.end())break;
                           else
                           {
                               zero=*it;


                           }
                       }
                   }
                }
                else
                {
                  while(1)
                   {

                       on.erase(it2);st[oe]=cnt;
                       it=zer.lower_bound(oe);
                       if(it==zer.end())break;
                       else
                       {
                           zero=*it;st[zero]=cnt;zer.erase(it);
                           it2=on.lower_bound(zero);
                           if(it2==on.end())break;
                           else
                           {
                               oe=*it2;


                           }
                       }
                   }
                }
cnt++;
            }}
            cout<<cnt-1<<endl;
            for(int i=0;i<n;i++)cout<<st[i]<<" ";cout<<endl;

        }










        return 0;
        }