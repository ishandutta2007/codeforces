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


        string s[100011];
        int t;
        bool yes;


        int main()
        {

        ios_base::sync_with_stdio(false);


        cin>>t;
        while(t--)
        {
            cin>>n>>x>>y;

            z=1;mn=1e9;
            while(z<51)
            {
                int tr=1;
                while(tr<51)
                {
                    yes1=false,yes2=false;vector<int>tmp;yes=false;

            for(int i=z,j=1;j<101;i+=tr,j++)
            {

                if(i==x)yes1=true;
                if(i==y)yes2=true;
                tmp.push_back(i);
                //cout<<i<<" "<<yes1<<" "<<yes2<<endl;
                if(i>y&&!yes2)break;

            }
            //cout<<"hi"<<endl;
                    int si=tmp.size();
                    for(int i=0;i<=si-n;i++)
                    {
                        if(tmp[i]<=x&&tmp[i+n-1]>=y&&yes1&&yes2)
                        {
                            mn=min(mn,tmp[i+n-1]);

                            break;
                        }
                    }



                tr++;
                }
            z++;

            }

            z=1;
            while(z<51)
            {
                int tr=1;
                while(tr<51)
                {
                    yes1=false,yes2=false;vector<int>tmp;yes=false;

            for(int i=z,j=1;j<101;i+=tr,j++)
            {

                if(i==x)yes1=true;
                if(i==y)yes2=true;
                tmp.push_back(i);
                //cout<<i<<" "<<yes1<<" "<<yes2<<endl;
                if(i>y&&!yes2)break;

            }
            //cout<<"hi"<<endl;
                    int si=tmp.size();
                    for(int i=0;i<=si-n;i++)
                    {
                        if(tmp[i]<=x&&tmp[i+n-1]>=y&&yes1&&yes2&&tmp[i+n-1]==mn)
                        {
                            for(int j=i;j<i+n;j++)cout<<tmp[j]<<" ";
                            cout<<endl;
                            yes=true;
                            break;
                        }
                    }


                if(yes)break;
                tr++;
                }
            z++;
            if(yes)break;
            }




        }











        return 0;
        }