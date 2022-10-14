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
        int m,n,x,y,z,k,cnt,mn=3e9,mx,ans,a[500003],b[500003],c[500003];vector<long long>v;char ch;


        string s;
        int t;
        bool yes;


        int main()
        {

        ios_base::sync_with_stdio(false);

        cin>>n;multiset<int>muls;
        for(int i=0;i<n;i++){cin>>a[i];b[a[i]]++;}
        for(int i=0;i<=500001;i++)
        {
          if(b[i])muls.insert(b[i]);
        }
        cin>>t;char ch;
        while(t--)
        {
            cin>>ch>>x;yes=false;

            if(ch=='-')
            {
                auto it=muls.lower_bound(b[x]);
                if(it!=muls.end())
                muls.erase(it);
                b[x]--;
                if(b[x])
                muls.insert(b[x]);
            }
            else
            {
                //for(auto itr=muls.begin();itr!=muls.end();itr++)cout<<*itr<<" ";cout<<endl;
               auto it=muls.lower_bound(b[x]);
                if(it!=muls.end()&&b[x])
                muls.erase(it);

                b[x]++;
               // cout<<"bx "<<b[x]<<endl;
                muls.insert(b[x]);
                //for(auto itr=muls.begin();itr!=muls.end();itr++)cout<<*itr<<" ";cout<<endl;
            }
            auto it =muls.lower_bound(8);
            if(it!=muls.end())yes=true;
            it =muls.lower_bound(4);
            if(it!=muls.end()){it++;if(it!=muls.end())yes=true;}
            it =muls.lower_bound(2);
            if(it!=muls.end())
            {
                it++;
                if(it!=muls.end())
                {
                    x=*it;
                    auto it2=muls.lower_bound(4);
                    if(it2!=it&&it2!=muls.end())yes=true;

                }
            }
            it=muls.lower_bound(2);
            if(it!=muls.end())
            {
                auto it2=muls.lower_bound(6);
                if(it2!=it&&it2!=muls.end())yes=true;
                //cout<<*it<<" "<<*it2<<endl;

            }
            //for(auto itr=muls.begin();itr!=muls.end();itr++)cout<<*itr<<" ";cout<<endl;
            if(yes)cout<<"YES\n";
            else cout<<"NO\n";



        }










        return 0;
        }