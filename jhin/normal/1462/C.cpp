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
        int m,n,x,y,z,k,mn=3e9,mx,ans,a[100003];bool yes1,yes2;vector<long long>v;set<long long>sol;char ch;string st[102];


        map<string,string>mymap;

        string s;
        string str[302];string line[4];


        int t,x1,y1,z1;
        bool yes;
//        void getmin(vector<int>ve)
//        {
//            for(int j=1;j<=9;j++){
//                    bool yes=true;
//            for(int i=0;i<ve.size();i++)
//            {
//               if(ve[i]==j)yes=false;
//            }
//            if(yes){
//                vector<int>tmp=ve;int su=0;int num=1;
//                tmp.push_back(j);
//                for(int z=0;z<tmp.size();z++)
//                {
//                    su+=tmp[z];
//                    if(z==0)num*=tmp[z];
//                    else
//                    {
//                        num*=10;num+=tmp[z];
//                    }
//                }
//                if(su==n)
//                {
//                    mn=min(mn,num);
//                    return;
//                }
//                if(su<n)
//                getmin(tmp);
//            }
//            }
//        }




        int main()
        {

        ios_base::sync_with_stdio(false);





       cin>>t;
        while(t--)
        {

            cin>>n;
            if(n>45){cout<<"-1\n";
            continue;}
            vector<int>ve;
            for(int i=1;i<10;i++)ve.push_back(i);
            int su=45;
            while(su>n)
            {
               int num=*ve.begin();
               ve.erase(ve.begin());
               su-=num;
            }
            int dif=n-su;
            if(dif!=0){
            ve.push_back(dif);
            cout<<*(--ve.end());
            }
            int si=ve.size();
            if(dif!=0)
            si-=1;
            for(int i=0;i<si;i++)cout<<ve[i];
            cout<<"\n";









        }



        return 0;
        }