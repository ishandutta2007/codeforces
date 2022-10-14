// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;



#define f for(int i=0;i<n;i++)
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
vector<int>vv;int cnt=0;
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
long long m,x,n,y,z,k,mx,one,gd,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500000];string s,s2;vector<int>v,v2[100003];long long sum,ans,num;char ch;
vector<pair<int,char>>r1,r2;
map<int,int> mp;
set<int>myset;

int t;bool used;long long x1,x2,x3,x4,y1,y2,y3,y4,b1,b2,w1,w2,b3,w3;
bool check(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4)
{

    if (x1 > x4 || x3 > x2)
        return false;


    if (y2 < y3 || y4 < y1)
        return false;

    return true;
}
int main()
{

ios_base::sync_with_stdio(false);
cin>>t;
while(t--)
{
    cin>>n>>m;
    x=(n*m+1)/2;
    y=(n*m)/2;b1=y;w1=x;b2=y;w2=x;b3=y;w3=x;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;



            long long tmp=(x2-x1+1)*(y2-y1+1);

            if((x1+y1)%2&&tmp%2)tmp++;tmp/=2;
            w1+=tmp;
            b1-=tmp;
            w3+=tmp;
            b3-=tmp;
           long long tmp2=(x4-x3+1)*(y4-y3+1);

            if((x3+y3)%2==0&&tmp2%2)tmp2++;tmp2/=2;
            w2-=tmp2;
            b2+=tmp2;
            w3-=tmp2;
            b3+=tmp2;

if(!check(x1,x2,x3,x4,y1,y2,y3,y4))cout<<w3<<" "<<b3<<endl;
else
{
    long long x5,x6,y5,y6;
    x5 = max(x1, x3);
y5 = max(y1, y3);
x6 = min(x2, x4);
y6 = min(y2, y4);
            long long tmp3=(x6-x5+1)*(y6-y5+1);

            if((x5+y5)%2&&tmp3%2)tmp3++;tmp3/=2;
            w1-=tmp3;
            b1+=tmp3;
            w1-=tmp2;
            b1+=tmp2;
            cout<<w1<<" "<<b1<<endl;
}
}

return 0;
}