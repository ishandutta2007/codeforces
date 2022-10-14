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
long long gcd(long a , long b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,mx,one,gd,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500000];string s,s2;vector<int>v,v2[100003];long long sum,ans,num;char ch;
vector<pair<int,char>>r1,r2;
map<int,int> mp;
set<int>myset;

int t;bool used;long long x1,x2,x3,x4,y1,y2,y3,y4,b1,b2,w1,w2,b3,w3;

int main()
{


ios_base::sync_with_stdio(false);
cin>>t;int d;
while(t--)
{
    cin>>n>>x>>y>>d;x1=0;x2=0;
    if(abs(x-y)%d==0)cout<<abs(x-y)/d;
    else
    {
        if((y-1)%d==0){x1=(x-1+d-1)/d+(y-1)/d;}
        if((n-y)%d==0){x2=(n-x+d-1)/d+(n-y)/d;}
        if(x1||x2)
        {
            if(x1!=0&&x2!=0)cout<<min(x1,x2);
            else cout<<max(x1,x2);
        }
        else cout<<-1;
    }
    cout<<endl;
}


return 0;
}