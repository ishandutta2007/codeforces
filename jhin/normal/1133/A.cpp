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
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,x1,k,mx,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500000];string s2;vector<int>v,v2[100003];long long sum,ans,num;char ch;
//vector<pair<int,char>>r1,r2;
map<string,int> mp1;
set<int>myset;//its not muuultiset
string s1;bool yes,lft,rt;
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

cin>>s1>>s2;
ho=int (s1[1]-'0')+10*int(s1[0]-'0');
mi=int (s1[4]-'0')+10*int(s1[3]-'0');
ho1=int (s2[1]-'0')+10*int(s2[0]-'0');
mi1=int (s2[4]-'0')+10*int(s2[3]-'0');
//cin>>ho>>mi>>ho1>>mi1;

int hot=ho,mit=mi;
while(ho<=ho1)
{
    cnt++;
    mi++;
    fix_time();
    if(ho==ho1&&mi==mi1)break;
}
cnt/=2;ho=hot;mi=mit;
while(cnt--){mi++;fix_time();}
if(ho<10)cout<<0;
cout<<ho<<":";if(mi<10)cout<<0;cout<<mi;
return 0;
}