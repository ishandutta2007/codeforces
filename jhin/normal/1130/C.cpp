// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;




const int mod=1e9+7;
vector<long long> p;


int ho,mi,se;
void fix_time()
{   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
    if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>24)ho-=24;
}
long long my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
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
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,x1,k,mx,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500000];string s2;vector<int>v,v2[100003];long long sum,ans,num;char ch;
//vector<pair<int,char>>r1,r2;
bool visited[52][52],visited2[52][52];
char mym[52][52];
vector<pair<int,int> >vx1,vx2;
map<string,int> mp1;
void go(int x,int y)
{
 if(!visited[x+1][y]&&mym[x+1][y]=='0'){visited[x+1][y]=true;go(x+1,y);vx1.push_back({x+1,y});}
 if(!visited[x-1][y]&&mym[x-1][y]=='0'){visited[x-1][y]=true;go(x-1,y);vx1.push_back({x-1,y});}
 if(!visited[x][y+1]&&mym[x][y+1]=='0'){visited[x][y+1]=true;go(x,y+1);vx1.push_back({x,y+1});}
 if(!visited[x][y-1]&&mym[x][y-1]=='0'){visited[x][y-1]=true;go(x,y-1);vx1.push_back({x,y-1});}
}
void go2(int x,int y)
{
 if(!visited2[x+1][y]&&mym[x+1][y]=='0'){visited2[x+1][y]=true;go2(x+1,y);vx2.push_back({x+1,y});}
 if(!visited2[x-1][y]&&mym[x-1][y]=='0'){visited2[x-1][y]=true;go2(x-1,y);vx2.push_back({x-1,y});}
 if(!visited2[x][y+1]&&mym[x][y+1]=='0'){visited2[x][y+1]=true;go2(x,y+1);vx2.push_back({x,y+1});}
 if(!visited2[x][y-1]&&mym[x][y-1]=='0'){visited2[x][y-1]=true;go2(x,y-1);vx2.push_back({x,y-1});}
}
set<int>myset;//its not muuultiset
string s;bool yes,lft,rt;
multiset<string>lfts[100001],rts[100001];
vector<pair<int,int> >v1,tmpv;
char movx,movy;
vector<int>vx[100001];
int post[10000000][2];
long long t,sum2,y3,z3,mxx,mxy;bool used;//))(())))
bool hast[200001];

int main()
{

ios_base::sync_with_stdio(false);

cin>>n;
cin>>x>>y>>x2>>y2;
visited[x][y]=true;vx1.push_back({x,y});
visited2[x2][y2]=true;vx2.push_back({x2,y2});
for(int i=0;i<n;i++)mym[0][i]='1';for(int i=0;i<n;i++)mym[i][0]='1';
for(int i=0;i<n;i++)mym[n-1][i]='1';for(int i=0;i<n;i++)mym[i][n-1]='1';
for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>mym[i][j];
go(x,y);
go2(x2,y2);
//for(int i=0;i<vx1.size();i++)cout<<vx1[i].first<<" "<<vx1[i].second<<"  ";cout<<endl;
//for(int i=0;i<vx2.size();i++)cout<<vx2[i].first<<" "<<vx2[i].second<<"  ";cout<<endl;
for(int i=0;i<vx1.size();i++)
{ int tmpx=vx1[i].first,tmpy=vx1[i].second;
   for(int j=0;j<vx2.size();j++)
   {int tmpx2=vx2[j].first,tmpy2=vx2[j].second;
       mn=min(mn,(tmpx-tmpx2)*(tmpx-tmpx2)+(tmpy-tmpy2)*(tmpy-tmpy2));
   }
}
cout<<mn;

return 0;
}