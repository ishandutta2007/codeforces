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
                    for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
                        if(y&1)num=(num*i);
                    return num;
                }

                bool prime[1000001],prime2[1000001];
                void sieve(){
                    for(int i=2;i<=1000000;i+=2)
                        prime[i]=false,prime[i-1]=true;
                    prime[2]=true;
                    for(int i=3;i*i<=1000000;i+=2)
                        if(prime[i])
                            for(int j=i*i;j<=1000000;j+=2*i)
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
           long long m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003];vector<int>v,vr,v2[100003];long long sum,ans,num;char ch;
                //vector<pair<int,char>>r1,r2;
                map<char,vector<int> > mp1;
                set<int>myset;//its not muuultiset
               bool yes,lft,rt;
                multiset<string>lfts[100001],rts[100001];
                vector<pair<long long,long long> >v1,tmpv;
                char movx,movy;
                multiset<int>muls;

                int t,sum2,y3,z3,mx2,mx;bool used;//))(())))
                bool hast[200001];
                int prevx,prevy;
                map<int,int>mymp,mymp2;
                vector<int>myst;
                multiset<int>mset; set<int>nset;
                string s,ss;char seq[10001][10001];
                map<char,int>mpt[10001];int nums[11],sums[11];long long s1,s2,e1,e2;

                    int main()
                {

            ios_base::sync_with_stdio(false);


            cin>>n>>m;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }sort(a,a+n);
            for(int i=0;i<m;i++)
            {
                cin>>b[i];mset.insert(b[i]);
            }

            for(int i=0;i<n;i++)
            {
                if(a[i]>*mset.begin())return cout<<-1,0;
            }
            for(int i=0;i<n;i++)
            {
                auto it=mset.lower_bound(a[i]);
                if(a[i]==(*it))
                {
                    for(int j=0;j<m;j++)ans+=b[j];
                    for(int z=0;z<n;z++)
                    {
                        if(z==i)continue;
                        ans+=a[z]*m;

                    }
                    cout<<ans;
                    return 0;
                }
            }
ans+=a[n-1];auto it=mset.begin();it++;
for(;it!=mset.end();it++)ans+=*it;
ans+=(*mset.begin());
ans+=a[n-2]*(m-1);
for(int i=0;i<n-2;i++)ans+=a[i]*m;
cout<<ans;

                return 0;
                }