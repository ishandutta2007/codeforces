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
       int cnt=0;
    void pfact(long long x)
    {   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
    for(long long i=3;i*i<=x;i+=2)
    if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
    if(x>1)p.push_back(x),cnt++,vv.push_back(1);
    }
        int m,n,x,y,z,k,mn=3e9,mx,ans,a[500003],b[500003],c[500003];bool yes1,yes2;vector<long long>v;char ch;string st[102];


        map<string,string>mymap;

        string s;
        string str[302];string line[4];
        void init()
        {
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)line[i]+=" ";
        }
        void getstr(int in,int jn)
        {

            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)line[i][j]=str[in+i][jn+j];

        }
        void fix(int in,int jn,int cnt)
        {
                if(cnt==0||in==4||jn==4)return;
                for(int i=0;i<4;i++)
                {
                    for(int j=1;j<3;j++)
                    {
                        if(line[i][j]=='X'&&line[i][j-1]=='X'&&line[i][j+1]=='X');
                    }
                }
               fix(in+1,jn,cnt);
               fix(in,jn+1,cnt);
        }
        int t,x1,y1,z1;
        bool yes;



        int main()
        {

        ios_base::sync_with_stdio(false);





       cin>>t;
        while(t--)
        {

            cin>>n>>m;string st[n];int arr[n][m+2];memset(arr,0,sizeof arr);
            for(int i=0;i<n;i++)cin>>st[i];
            cnt=1;ans=0;
            for(int i=0;i<n;i++)
            {
                for(int j=1;j<=m;j++)
                {

                        if(st[i][j-1]=='*')arr[i][j]=arr[i][j-1]+1;
                        else arr[i][j]=arr[i][j-1];


                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<=m;j++)
                {   cnt=0;
                    for(int z=i;z<n;z++)
                    { yes=true;
//                        for(int jj=j-cnt;jj<=j+cnt;jj++)
//                        {
//                            if(st[z][jj]!='*')yes=false;
//                        }
                        if(arr[z][j+cnt]-arr[z][j-cnt-1]!=2*cnt+1)yes=false;

                        if(yes)ans++;
                        else break;
                        cnt++;

                    }

                }
            }
            cout<<ans<<"\n";






        }



        return 0;
        }