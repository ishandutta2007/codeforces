    #include <bits/stdc++.h>

                    using namespace std;




                    const int mod=998244353;
                    vector<long long> p;


                    int ho,mi,se,ho1,mi1,cnt;
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

                    bool prime[100000001],prime2[1000001];
                    void sieve(){
                    for(int i=2;i<=100000000;i+=2)
                    prime[i]=false,prime[i-1]=true;
                    prime[2]=true;
                    for(int i=3;i*i<=100000000;i+=2)
                        if(prime[i])
                            for(int j=i*i;j<=10000000;j+=2*i)
                                prime[j]=false;
                                }
                    vector<long long>vv,vv1;
                    void pfact(long long xx)
                    {   if(xx%2==0){p.push_back(2);while(xx%2==0)xx/=2,cnt++;vv.push_back(cnt);}
                            for(long long i=3;i*i<=xx;i+=2)
                                    if(xx%i==0){cnt=0;p.push_back(i);while(xx%i==0)xx/=i,cnt++;vv.push_back(cnt);}
                                        if(xx>1)p.push_back(xx),cnt++,vv.push_back(1);
                    }
                    long long gcd(long long a , long long b)
                    {
                      if(b==0) return a;
                               a%=b;
                        return gcd(b,a);
                    }
                   int m,x,n,y,z,k,one,gd,two,mn=3e9,mid,mx,l,r,pos,a[500003],b[500003],c[500003],d[500003];vector<int>vr,v2[100003];long long sum,ans,num;char ch;
                                    //vector<pair<int,char>>r1,r2;
                    map<char,vector<int> > mp1;
                    //its not muuultiset
                    bool yes;
                    char movx,movy;

                    bool vis[100001];
                    long long t,sum2,y3,z3,mx2;bool used;//))(())))



                    multiset<int>mulset; set<int>myset;
                    string s;

                    vector<int>vx[200003];
            bool visited[500000];


                int main()
                {

                    ios_base::sync_with_stdio(false);

                  cin>>t;
                  while(t--)
                  {
                      int aa,bb,cc,dd;
                      yes=true;
                      cin>>aa>>bb>>cc>>dd;
                      int x1,x2,y1,y2;
                      cin>>x>>y>>x1>>y1>>x2>>y2;
                      int tmpx=x,tmpy=y;
                      int tmp=aa-bb;
                      int tmp2=cc-dd;
                      if(tmpx<x1||tmpx>x2||tmpy<y1||tmpy>y2)yes=false;
                      else
                      {
                        if(tmpx==x1&&tmpx==x2&&(aa!=0||bb!=0))yes=false;
                        else if(tmpy==y1&&tmpy==y2&&(cc!=0||cc!=0))yes=false;
                        tmpx-=tmp;
                        tmpy-=tmp2;
                        if(tmpx<x1||tmpx>x2||tmpy<y1||tmpy>y2)yes=false;

                      }
                      if(yes)cout<<"Yes\n";
                      else cout<<"No\n";


                  }




                    return 0;
                }