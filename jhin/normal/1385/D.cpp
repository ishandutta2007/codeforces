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
        {  p.clear();
        vv.clear();
        cnt=0;
             if(xx%2==0){p.push_back(2);while(xx%2==0)xx/=2,cnt++;vv.push_back(cnt);}
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
        int m,n,x,y,z,k,mn=3e9,mx,ans,a[500003],b[500003],c[500003];vector<long long>v;char ch;


        string s;
        int t;
        bool yes;

        void solve(string sr,char ch,int an)
        {
            int si=sr.size();int cnt1=0,cnt2=0,co1=0,co2=0;string s1="",s2="";
            if(si==2)
            {
                if((sr[0]==ch&&sr[1]==ch+1)||sr[1]==ch&&sr[0]==ch+1){mn=min(mn,an);}
                else if(sr[0]==ch||sr[1]==ch)mn=min(mn,an+1);
                else if(sr[0]==ch+1||sr[1]==ch+1) mn=min(mn,an+1);
                else mn=min(mn,an+2);
                return;
            }
            for(int i=0;i<si/2;i++){if(sr[i]==ch)cnt1++;else co1++; s1+=sr[i];}
            for(int i=si/2;i<si;i++){if(sr[i]==ch)cnt2++;else co2++;s2+=sr[i];}


              ch++;
              solve(s2,ch,an+co1);
              solve(s1,ch,an+co2);

            return;
        }
        int main()
        {

        ios_base::sync_with_stdio(false);

        cin>>t;
        while(t--)
        {
            cin>>n>>s;
            if(n==1){if(s[0]=='a')cout<<"0\n";else cout<<"1\n";}
            else{
            mn=1e9;
            solve(s,'a',0);
            if(mn==1e9)mn=0;
            cout<<mn<<endl;
            }

        }









        return 0;
        }