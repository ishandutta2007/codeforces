                            #include <bits/stdc++.h>

                            using namespace std;




                            const int mod=1e9+7;
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
                           int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500003],d[500003];vector<int>vr,v2[100003];long long sum,ans,num;char ch;
                                            //vector<pair<int,char>>r1,r2;
                            map<char,vector<int> > mp1;
                            set<int>myset;//its not muuultiset
                            bool yes,lft,rt;
                            multiset<string>lfts[100001],rts[100001];
                            vector<pair<long long,long long> >v1,tmpv;
                            char movx,movy;
                            multiset<int>muls;
                            bool vis[100001];
                            int t,sum2,y3,z3,mx2,mx;bool used;//))(())))
                            bool hast[200001];
                            int prevx,prevy;
                            int grid[14][14];
                            map<int,int>mymp,mymp2;
                            vector<int>myst;
                            multiset<int>mset; set<int>nset;
                            string s,ss;

                              vector<int>vx[100003];
                              vector<long long>v;
bool arr[100003];
vector<long long> arra[100003],mns,mns2,mxs,mxs2;


                            int main()
                            {

                                ios_base::sync_with_stdio(false);


                                cin>>t;
                                for(int j=0;j<t;j++)
                                {


                                cin>>n;mn=1e9;mx=0;
                                for(int i=0;i<n;i++)
                                {
                                    cin>>x;
                                    arra[j].push_back(x);
                                    if(mn>=x)
                                    {
                                        mn=x;
                                    }
                                    else if(!arr[j])
                                    {
                                       arr[j]=true;cnt++;
                                    }
                                   mx=max(mx,x);
                                }
                                if(!arr[j])
                                {mns.push_back(mn);mns2.push_back(mn);
                                mxs.push_back(mx);mxs2.push_back(mx);}


                                }
                                for(int i=0;i<t;i++)
                                {
                                    if(arr[i])ans+=t;
                                    else {ans+=cnt;

                                    }

                                }
                                sort(mns.begin(),mns.end());
                                sort(mxs.begin(),mxs.end());
                                for(int i=0;i<mns.size();i++)
                                {
                                    auto it=lower_bound(mxs.begin(),mxs.end(),mns[i]+1);
                                    int add=mxs.end()-it;
                                    ans+=add;
                                }

cout<<ans;
                                return 0;
                            }