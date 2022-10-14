            #include <bits/stdc++.h>

            using namespace std;




            const int mod=1e9+7;
            vector<long long> p;


            int ho,mi,se,ho1,mi1;
            void fix_time()
            {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
                if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
                if(ho<0)ho+=24;if(ho>24)ho-=24;
            }
            unsigned long long my_pow(int x,int y)
            {  unsigned  long long num=1;
                for(unsigned long long i=x;y>0;i=(i*i)%mod,y>>=1)
                    if(y&1)num=(num%mod*i%mod)%mod;
                        return num;
            }

            bool prime[100000001],prime2[1000001];
            void sieve(){
            for(int i=2;i<=100000000;i+=2)
            prime[i]=false,prime[i-1]=true;
            prime[2]=true;
            for(int i=3;i*i<=100000000;i+=2)
                if(prime[i])
                    for(int j=i*i;j<=100000000;j+=2*i)
                        prime[j]=false;
                        }
            vector<long long>vv,vv1;int cnt=0;
            void pfact(long long x)
            {   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
                    for(long long i=3;i*i<=x;i+=2)
                            if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
                                if(x>1)p.push_back(x),cnt++,vv.push_back(1);
            }
            long long gcd(long long a , long long b)
            {
              if(b==0) return a;
                       a%=b;
                return gcd(b,a);
            }
            int m,x,n,y,z,k,one,gd,two,mn=1e9,mid,l,r,pos;vector<int>v,v2[100003];long long sum,ans,num;char ch;
                            //vector<pair<int,char>>r1,r2;
            multiset<int> mulset;
            set<int>myset;
            map<char,int>mp;



        int a[500001],b[500001],t;string s;



            int main()
            {
                cin>>t;
                while(t--)
                {
                    cin>>n>>s;x=-1;y=-1;
                    for(int i=s.size()-1;i>=0;i--)if(s[i]=='1'){x=i;break;}
                    for(int i=0;i<s.size();i++){if(s[i]=='1'){y=i;break;}}
                    if(x==-1)cout<<s.size()<<endl;
                    else {int tmp1=n-x-1,tmp2=y;cout<<max(2*(n-tmp1),2*(n-tmp2))<<endl;}

                }
//                  cin>>n>>k;
//                  for(int i=0;i<n;i++)
//                  {
//                      cin>>a[i];
//                  }


                return 0;
            }