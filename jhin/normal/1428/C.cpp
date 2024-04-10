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


//            cin>>t;
//            while(t--)
//            {
//                cin>>n>>k;
//                for(int i=0;i<n;i++)cin>>a[i];
//                vector<double>br,er,bspeed,espeed;int speed=1;
//                for(int i=n-1;i>=0;i--)
//                {
//                    if(i==n-1)er.push_back(l-a[i]),speed++,espeed.push_back(speed);
//                    else
//                    {
//
//                    double chk=*(--er.end());
//                    double len=a[i+1]-a[i];
//                    er.push_back(len/spead+chk);
//                    speed++;
//                    espeed.push_back(speed);
//                    }
//                }
//                speed=1;
//                for(int i=0;i<n;i++)
//                {
//                    if(i==0)br.push_back(a[i]),speed++;
//                    else
//                    {
//                        double chk=*(--br.end());
//                        double len=a[i]-a[i-1];
//                        br.push_back(len/spead+chk);
//                        auto it=lower_bound(er.begin(),er.end(),chk);
//                        int ind=it-er.begin();
//                        ind=n-ind-1;
//                        if(a[i]>=a[ind])
//                        {
//                            if(a[i]==a[ind])ans=*(--br.end());
//                            else
//                            {
//                                int esped=espeed[ind];1 9
//                                3 2
//
//                            }
//                        }
//                    }
//                }
//            }

cin>>t;
while(t--)
{
    cin>>s;

    n=s.size();
    multiset<char>tmp;int cnt=0,ans=n,cntb=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')cnt++;
        else
        {
            if(cnt>0)cnt--,ans-=2;

               else if(s[i]=='B'&&cntb>0)ans-=2,cntb--;
                else cntb++;

        }
    }
    cout<<ans<<endl;
}




        return 0;
        }