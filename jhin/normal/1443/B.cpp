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
           cin>>x>>y>>s;cnt=0;vector<int>mines;auto it=--s.end();ans=0;
           while(*it=='0'){auto it2=it;it--;s.erase(it2);}
           string s2="";
           int j=0;
           while(!s.empty()&&s[j]=='0')j++;
           for(;j<s.size();j++)
           {
               s2+=s[j];
           }
           s=s2;
           int si=s.size();
           for(int i=0;i<s.size();i++)
           {
               if(s[i]=='1'&&i!=si-1)cnt++;
               else
               {
                   if(i==si-1&&s[i]=='1')cnt++;
                   if(cnt)
                   mines.push_back(cnt);
                   cnt=0;
                   mines.push_back(cnt);
               }
           }

           int zero=0,prev=0;
            //for(int i=0;i<mines.size();i++)cout<<mines[i]<<" ";cout<<endl;
           for(int i=0;i<mines.size();i++)
           {
               if(prev==0&&mines[i]!=0)prev=mines[i];
               else if(prev!=0&&mines[i]!=0)
               {
                  if(x>zero*y)ans+=zero*y;
                   else ans+=x;
                   prev=mines[i];
                   zero=0;
                   //cout<<zero*y<<" "<<x<<endl;
               }
               else if(mines[i]==0)zero++;
                //cout<<ans<<" ";

           }
           if(!s.empty())ans+=x;
           cout<<ans<<endl;

        }








        return 0;
        }