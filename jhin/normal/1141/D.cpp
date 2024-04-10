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
int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,pos,a[500003],b[500003],c[500000],c2[500000];string s2;vector<int>v,v2[100003];long long sum,ans,num;char ch;
//vector<pair<int,char>>r1,r2;
map<string,int> mp1;
set<int>myset;//its not muuultiset
string s1;bool yes,lft,rt;
multiset<string>lfts[100001],rts[100001];
vector<pair<int,int> >v1,tmpv;
string s;
char movx,movy;
vector<int>vx[100001];
int post[10000000][2];
int t,sum2,y3,z3,mx2,mx;bool used;//))(())))
bool hast[200001];
int prevx,prevy;
map<char,vector<int> >mymp,mymp2;
vector<int>l,r,l2,r2;
int main()
{

ios_base::sync_with_stdio(false);

cin>>n;
cin>>s>>s2;
for(int i=0;i<n;i++){mymp[s[i]].push_back(i+1);mymp2[s2[i]].push_back(i+1);}
for(char ch='a';ch<='z';ch++)
{       int tmp=mymp2[ch].size();
        int tmp2=mymp[ch].size();
    if(mymp[ch].size()>mymp2[ch].size())
        {
        for(int i=tmp;i<tmp2;i++)l.push_back(mymp[ch][i]);
        }
    if(mymp[ch].size()<mymp2[ch].size())
    {
        for(int i=tmp2;i<tmp;i++)r.push_back(mymp2[ch][i]);
    }
    for(int i=0;i<min(tmp,tmp2);i++)
    {
        v1.push_back({mymp[ch][i],mymp2[ch][i]});
    }

}
int tmp=mymp['?'].size();int tmp2=mymp2['?'].size();
int tmpp=r.size(),tmpp2=l.size();
for(int i=0;i<min(tmp,tmpp);i++)v1.push_back({mymp['?'][i],r[i]});
if(mymp['?'].size()>r.size())
{int tmpk=r.size();
        int tmpk2=mymp['?'].size();
    for(int i=tmpk;i<tmpk2;i++)l2.push_back(mymp['?'][i]);
}
if(mymp2['?'].size()>l.size())
{int tmpk=l.size();
        int tmpk2=mymp2['?'].size();
    for(int i=tmpk;i<tmpk2;i++)r2.push_back(mymp2['?'][i]);
}
for(int i=0;i<min(tmp2,tmpp2);i++)v1.push_back({l[i],mymp2['?'][i]});
int tmpr=l2.size(),tmpr2=r2.size();
    for(int i=0;i<min(tmpr,tmpr2);i++)
    {
        v1.push_back({l2[i],r2[i]});
    }
cout<<v1.size()<<endl;
for(int i=0;i<v1.size();i++)cout<<v1[i].first<<" "<<v1[i].second<<endl;

return 0;
}