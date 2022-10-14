// system.cout(translate *from glut);
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
long long gcd(long long a , long long b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos;string s2;vector<int>v,v2[100003];long long sum,ans,num;char ch;
//vector<pair<int,char>>r1,r2;
map<string,int> mp1;
set<int>myset;//its not muuultiset
string s1[10004],s3[10004];bool yes,lft,rt;

vector<pair<int,int> >v1,tmpv;
char movx,movy;

int t,sum2,y3,z3,mx2,mx;bool used;//))(())))
bool hast[200001];
int prevx,prevy;
int my[5004][5004],my1[5004][5004];
map<pair<long long,long long>,int>mymp,mymp2;
vector<int>vtm[5004];
int main()
{

ios_base::sync_with_stdio(false);

cin>>n>>m;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)cin>>my[i][j];
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)cin>>my1[i][j];
}
for(int j=0;j<m;j++)
{
    s1[j]+=char(my[0][j]+'0');

    int tmp=j,tmp2=0;
    while(tmp>0)
    {
        tmp--;tmp2++;if(tmp2==n)break;
        s1[j]+=char(my[tmp2][tmp]+'0');

    }
}
for(int i=1;i<n;i++)
{
    s1[m+i-1]+=char(my[i][m-1]+'0');

    int tmp=m-1,tmp2=i;
    while(tmp>0)
    {
        tmp--;tmp2++;if(tmp2==n)break;
        s1[m+i-1]+=char(my[tmp2][tmp]+'0');

    }
}
for(int j=0;j<m;j++)
{
    s3[j]+=char(my1[0][j]+'0');

    int tmp=j,tmp2=0;
    while(tmp>0)
    {
        tmp--;tmp2++;if(tmp2==n)break;
        s3[j]+=char(my1[tmp2][tmp]+'0');

    }
}
for(int i=1;i<n;i++)
{
    s3[m+i-1]+=char(my1[i][m-1]+'0');

    int tmp=m-1,tmp2=i;
    while(tmp>0)
    {
        tmp--;tmp2++;if(tmp2==n)break;
        s3[m+i-1]+=char(my1[tmp2][tmp]+'0');

    }
}
for(int i=0;i<1001;i++){sort(s1[i].begin(),s1[i].end());sort(s3[i].begin(),s3[i].end());if(s1[i]!=s3[i])return cout<<"NO",0;}
cout<<"YES";

return 0;
}