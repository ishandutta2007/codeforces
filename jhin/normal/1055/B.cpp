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

bool prime[16000003];
void sieve(){
    for(int i=2;i<=16000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=4000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=16000000;j+=2*i)
                prime[j]=false;
}

void pfact(long long x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(long long i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,mx,sum,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,t,a[500003],b[500003],c[500000];string s,s2;vector<int>v,v2[100003];long long ans,num;char ch;
vector<pair<int,char>>r1,r2;
map<int,pair<int,int>> mp;
set<int>myset;


int main()
{

ios_base::sync_with_stdio(false);
cin>>n>>m>>l;
for(int i=0;i<n;i++)
{
    cin>>a[i];if(a[i]>l)myset.insert(i);
}
if(!myset.empty())
{
    int tmp=*myset.begin();
    x++;
for(auto it=++myset.begin();it!=myset.end();it++)
{
    if(*it>tmp+1)
    {
        x++;
    }
    tmp=*it;
}

}int ti,pi,di;
for(int i=0;i<m;i++)
{
    cin>>ti;
    if(ti)
    {cin>>pi>>di;
        if(a[pi-1]<=l)
        {a[pi-1]+=di;
        if(a[pi-1]>l)
            {myset.insert(pi-1);
            auto it=myset.lower_bound(pi-1);
            if(it==--myset.end())
            {
                if(it==myset.begin())x++;
                else
                {
                    auto it2=it;
                    it2--;
                    if(*it2<(*it)-1)x++;
                }
            }
            else if(it==myset.begin())
            {
                auto it2=it;
                it2++;
                if(*it<(*it2)-1)x++;
            }
            else
            {
                auto it2=it;
                auto it3=it;
                it2--;it3++;
                if(*it<(*it3)-1&&*it2<(*it)-1)x++;
                else if((*it2)==(*it3)-2)x--;
            }}

        }

    }
    if(!ti)cout<<x<<endl;
}

return 0;
}