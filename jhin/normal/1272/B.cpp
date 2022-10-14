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
                   long long m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500003],d[500003];vector<long long>v,vr,v2[100003];long long sum,ans,num;char ch;
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
                    string s,ss;char seq[10001][10001];
                    map<char,int>mpt[10001];int nums[11],sums[11];long long s1,s2,e1,e2;
                    int tree[1000001],A[1000001];
                     int arr[1000001][3];

                      vector<int>vx[100003];

bool my[26];
                    int main()
                    {

                        ios_base::sync_with_stdio(false);
//                        cin>>n>>x;
//                        cin>>s;
//
//                        for(int i=0;i<x;i++)
//                        {
//                            cin>>ch;
//                            my[ch]=true;
//                        }
//                        for(int i=0;i<s.size();i++)
//                        {
//
//                            if(my[s[i]]){y++;if(i==n-1)v.push_back(y);}
//                            else v.push_back(y),y=0;
//                        }
//                        for(int i=0;i<v.size();i++)
//                        {
//                            ans+=(v[i]*(v[i]+1))/2;
//                            //cout<<v[i]<<" ";
//                        }
//                        cout<<ans;
                         cin>>t;

                         while(t--)
                         {
                            cin>>s;map<char,int>tmp;
                            for(int i=0;i<s.size();i++)
                            {
                                tmp[s[i]]++;
                            }
                            int ups=tmp['U'];
                             int dos=tmp['D'];
                              int lefts=tmp['L'];
                               int rights=tmp['R'];
                               if(ups==0||dos==0)
                               {
                                   if(lefts>0&&rights>0)cout<<2<<endl<<"LR\n";
                                   else cout<<0<<endl;
                               }
                               else if(rights==0||lefts==0)
                               {
                                   if(ups>0&&dos>0)cout<<2<<endl<<"UD\n";
                                   else cout<<0<<endl;
                               }
                               else
                               {
                                   int mini=min(ups,dos);
                                   int mini2=min(lefts,rights);
                                   cout<<mini*2+mini2*2<<endl;
                                   for(int i=0;i<mini2;i++)cout<<"L";
                                   for(int i=0;i<mini;i++)cout<<"U";
                                   for(int i=0;i<mini2;i++)cout<<"R";
                                   for(int i=0;i<mini;i++)cout<<"D";
                                   cout<<endl;

                               }


                         }
                        return 0;
                    }