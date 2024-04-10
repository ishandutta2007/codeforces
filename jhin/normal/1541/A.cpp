#include <bits/stdc++.h>

        using namespace std;
using ll = long long;



        const int mod=998244353;
        vector<long long> p;



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

    int pfact(int x)
    { int cnt=0; if(x%2==0){while(x%2==0)x/=2,cnt++;}
    for(int i=3;i*i<=x;i+=2)
    if(x%i==0){while(x%i==0)x/=i,cnt++;}
    if(x>1)cnt++;
    return cnt;

    }
        int m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500003],c[500003],d[500003];char ch;



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
            if(n%2)
            {

                for(int i=1;i<=n-3;i+=2)
                {
                    cout<<i+1<<" "<<i<<" ";
                }
                cout<<n-1<<" "<<n<<" "<<n-2;
            }
            else
            {
                for(int i=1;i<=n;i+=2)
                {
                    cout<<i+1<<" "<<i<<" ";
                }
            }
            cout<<endl;


        }




        return 0;
        }