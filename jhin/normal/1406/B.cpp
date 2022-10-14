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
        long long m,n,x,y,z,k,cnt,mn=3e9,mx,ans,a[500003],b[500003],c[500003];bool yes1,yes2;vector<long long>v;char ch;string st[102];


        string s;
        int t;
        bool yes;


        int main()
        {

        ios_base::sync_with_stdio(false);


        cin>>t;
        while(t--)
        {
            cin>>n;vector<long long>ng,ps;z=0;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
                if(a[i]<0)ng.push_back(a[i]);
                else if(a[i]>0)ps.push_back(a[i]);
                else z=1;
            }
            int si1=ng.size(),si2=ps.size();
            if(si1+si2<5)
            {cout<<0<<endl;
            continue;}
            long long tmp1=0,tmp2=0,tmp3=0,tmp4=0;
            sort(ng.begin(),ng.end());
            sort(ps.begin(),ps.end());
            if(ng.size()>3)
            {
                ans=1;
                int si=ng.size();
                if(ps.empty())
                {
                    for(int i=ng.size()-1;i>=si-5;i--)
                    {
                        ans*=ng[i];
                    }
                    //cout<<ans<<endl;
                }
                else{
                    int si=ps.size();
                    tmp1=ng[0]*ng[1];
                    tmp2=ng[2]*ng[3];
                    if(si>4)
                    {tmp3=ps[si-2]*ps[si-3];
                     tmp4=ps[si-4]*ps[si-5];
                     vector<long long>tmp;
                     tmp.push_back(tmp1);tmp.push_back(tmp2);tmp.push_back(tmp3);tmp.push_back(tmp4);
                     sort(tmp.begin(),tmp.end());
                     ans=tmp[3]*tmp[2]*ps[si-1];
                    }
                    else if(si>2)
                    {
                        tmp3=ps[si-2]*ps[si-3];
                        vector<long long>tmp;
                        tmp.push_back(tmp1);tmp.push_back(tmp2);tmp.push_back(tmp3);
                        sort(tmp.begin(),tmp.end());
                        ans=tmp[1]*tmp[2]*ps[si-1];
                    }
                    else if(si==1||si==2)
                    {
                        ans=tmp1*tmp2*ps[si-1];
                    }
                }

            }
            else
                if(ng.size()>1)
            {

                    int si=ps.size();
                    tmp1=ng[0]*ng[1];

                    if(si>4)
                    {tmp3=ps[si-2]*ps[si-3];
                     tmp4=ps[si-4]*ps[si-5];
                     vector<long long>tmp;
                     tmp.push_back(tmp1);tmp.push_back(tmp3);tmp.push_back(tmp4);
                     sort(tmp.begin(),tmp.end());
                     ans=tmp[1]*tmp[2]*ps[si-1];
                     //cout<<tmp[2]<<" "<<tmp[3]<<" "<<ps[si-1]<<endl;
                    }
                    else if(si>2)
                    {
                        tmp3=ps[si-2]*ps[si-3];
                        vector<long long>tmp;
                        tmp.push_back(tmp1);tmp.push_back(tmp3);
                        sort(tmp.begin(),tmp.end());
                        ans=tmp1*tmp3*ps[si-1];
                    }
                    else
                    {ans=1;
                        for(int i=0;i<n;i++)ans*=a[i];
                    }


            }
            else if(ng.size()==1)
            {
                if(ps.size()==4)
                {
                    ans=ps[0]*ps[1]*ps[2]*ps[3]*ng[0];
                }
                else
                {
                    ans=1;
                int si=ps.size();
                for(int i=ps.size()-1;i>=si-5;i--)ans*=ps[i];
                }

            }
            else
            {
                ans=1;
                int si=ps.size();
                for(int i=ps.size()-1;i>=si-5;i--)ans*=ps[i];
            }
            if(z)ans=max(ans,ans*0);
            cout<<ans<<endl;
        }










        return 0;
        }