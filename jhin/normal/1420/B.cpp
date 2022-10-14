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
        long long m,n,x,y,z,k,cnt,mn=3e9,mx,ans,a[500003],b[500003];bool yes1,yes2;vector<long long>v;char ch;string st[102];


        string s;
        int t;
        bool yes;


        int main()
        {

        ios_base::sync_with_stdio(false);


//        cin>>t;
//
//        while(t--)
//        {
//            cin>>n;
//            for(int i=0;i<n;i++)
//            {
//                cin>>a[i];
//                b[i]=a[i];
//            }
//            sort(b,b+n);
//            map<int,int>tmp;
//            for(int i=0;i<n;i++)tmp[b[i]]=0;
//            for(int i=0;i<n;i++)
//            {
//
//               if(tmp[b[i]]==0)
//               {
//                   tmp[b[i]]=i+1;
//               }
//
//            }
//            ans=0;
//            for(int i=0;i<n;i++)
//            {
//              ans+=tmp[a[i]]-(i+1);
//              cout<<tmp[a[i]]<<" "<<(i+1)<<" "<<tmp[a[i]]-(i+1)<<endl;
//            }
//            cout<<ans<<endl;
//            if(ans<=n*(n-1)/2-1)cout<<"Yes\n";
//            else cout<<"No\n";
//        }

            cin>>t;
            while(t--)
            {
                cin>>n;ans=0;long long ar[100];memset(ar,0,sizeof ar);
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                    x=a[i];
                    y=0;

                while(x)
                {
                    x/=2;
                    y++;
                }
                ar[y]++;
                }
                for(int i=1;i<40;i++)
                {
                    ans+=((ar[i]-1)*(ar[i])/2);
                }
                cout<<ans<<endl;
            }









        return 0;
        }