// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


const int mod=1e9+7;
vector<long long> p;


int ho,mi,ho1,mi1;

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
bool chck(char d)
{
    if(d=='o'||d=='i'||d=='u'||d=='a'||d=='e')return true;
    return false;
}
int m,n,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[2003];string s3;vector<int>v;int sum,ans,num;
bool yes;int t;long long x,y;
multiset<pair<int,int> > df;

set<int>myset;//its not muuultiset
string s[1000003],s4;
vector<int>v1,v2;int fi,se,thi,fii,see,thii;
multiset<int>mulset;int mx;
bool nums[200001];

int main()
{

ios_base::sync_with_stdio(false);

cin>>t;
while(t--)
{
cin>>n;map<int,int>mp,mp1;int sset[n+1][2];y=0;z=0;memset(sset,0,sizeof(sset) );
for(int i=0;i<n;i++){cin>>x>>x1;mp[x]++;if(x1)mp1[x]++;}
for(auto it=mp.begin(),it2=mp1.begin();it!=mp.end();it++,it2++)
{   int tmp=it->second;int ind=it->first;int tmp2=mp1[ind];
    while(1)
    {
        if(sset[tmp][0]==0){sset[tmp][1]=tmp2;sset[tmp][0]=1;break;}
        else
        {
            mx=max(tmp2,sset[tmp][1]);//cout<<tmp2<<" "<<sset[tmp][1]<<"h"<<endl;
            mn=min(tmp2,sset[tmp][1]);
            sset[tmp][1]=mx;

            tmp2=mn;
            tmp--;
            if(tmp2>tmp)tmp2--;
            if(tmp==0)break;
        }
    }
    //cout<<tmp<<endl;
}
for(int i=1;i<=n;i++){if(sset[i][0])z+=sset[i][1],y+=i;}
cout<<y<<" "<<z<<'\n';



}



return 0;
}