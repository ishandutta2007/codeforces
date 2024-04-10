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
                   int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500003],d[500003];vector<int>v,vr,v2[100003];long long sum,ans,num;char ch;
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
                    map<int,int>mymp,mymp2;
                    vector<int>myst;
                    multiset<int>mset; set<int>nset;
                    string s,ss;char seq[10001][10001];
                    map<char,int>mpt[10001];int nums[11],sums[11];long long s1,s2,e1,e2;
                    int tree[1000001],A[1000001];
                     int arr[1000001][3];
                      set<int > vc[200002];
                      vector<int>vx[100003];


                    int main()
                    {

                        ios_base::sync_with_stdio(false);

                         cin>>n;
                         for(int i=0;i<n-2;i++)
                         {
                             cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
                             vc[arr[i][0]].insert(arr[i][1]);vc[arr[i][0]].insert(arr[i][2]);a[arr[i][0]]++;
                             vc[arr[i][1]].insert(arr[i][0]);vc[arr[i][1]].insert(arr[i][2]);a[arr[i][1]]++;
                             vc[arr[i][2]].insert(arr[i][1]);vc[arr[i][2]].insert(arr[i][0]);a[arr[i][2]]++;

                         }

                         for(int i=1;i<=n;i++)
                         {
                             for(auto it=vc[i].begin();it!=vc[i].end();it++)
                             {
                                 vx[i].push_back(*it);
                             }
                             if(vc[i].size()==2){x=i;}
                         }


                         v.push_back(x);

                             int fi=vx[x][0];
                             int si=vx[x][1];
                             if(a[fi]==3)swap(fi,si);
                                v.push_back(fi),v.push_back(si);

                             vis[x]=true;vis[fi]=true;vis[si]=true;cnt=3;
                         while(cnt<n)
                         {

                            cnt++;//cout<<fi<<endl;
                            if(vx[fi].size()>2){
                            int p1=vx[fi][0];
                            int p2=vx[fi][1];
                            int p3=vx[fi][2];
                            if(vx[fi].size()>3){
                            int p4=vx[fi][3];
                            if(!vis[p4])
                            {v.push_back(p4),vis[p4]=true;
                            fi=si;si=p4;
                            }}
                            if(!vis[p1])
                            {v.push_back(p1),vis[p1]=true;
                            fi=si;si=p1;
                            }
                            else if(!vis[p2])
                            {v.push_back(p2),vis[p2]=true;
                            fi=si;si=p2;
                            }
                            else if(!vis[p3])
                            {v.push_back(p3),vis[p3]=true;
                            fi=si;si=p3;
                            }}
                         }
//for(int i=1;i<=n;i++){cout<<i<<": ";for(int j=0;j<vx[i].size();j++)cout<<vx[i][j]<<" ";cout<<endl;}
for(int i=v.size()-1;i>=0;i--)cout<<v[i]<<" ";



                        return 0;
                    }