// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;



#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;


int ho,mi,se;
void fix_time()
{   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
    if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
    //if(ho<0)ho+=24;if(ho>24)ho-=24;
}
long long my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=(num*i);
    return num;
}

bool prime[1000001];
void sieve(){
    for(int i=2;i<=1000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=1000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=1000000;j+=2*i)
                prime[j]=false;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
int n,k,m,x,y,l,l2,z,a[200001],ans,v1,v2,v3,vm;char q;bool check;string s;map<char,bool>letr,tst;


int main()
{
    ios_base::sync_with_stdio(false);
cin>>v1>>v2>>v3>>vm;
if(vm>2*v3||2*vm<v3||vm>=v2)return cout<<-1,0;
if(v3<vm)v3=2*v3;v2*=2;v1*=2;
cout<<v1<<endl<<v2<<endl<<v3;

/*        for(char i='a';i<='z';i++)letr[i]=true;
cin>>n;
for(int i=0;i<n;i++)
{   for(char z='a';z<='z';z++)tst[z]=false;
    cin>>q;
    cin>>s;
    if(q=='!'&&!check)
    {
        for(int j=0;j<s.size();j++)tst[s[j]]=true;
        for(char z='a';z<='z';z++)letr[z]&=tst[z];
    }
    if(q=='.'&&!check)
      for(int j=0;j<s.size();j++)letr[s[j]]=false;
    if((q=='!'||q=='?')&&check)
    ans++;
    if(!check)
    {x=0;for(char z='a';z<='z';z++)if(letr[z])x++;if(x==1)check=true;}
}//for(char z='a';z<='z';z++)if(letr[z])cout<<z<<" ";
if(check)ans--;
cout<<ans;*/
return 0;
}