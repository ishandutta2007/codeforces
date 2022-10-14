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
int my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=(num*i)%mod;
    return int(num);
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
int n,a[100001];set<int>myset;vector<int>myvec;string s;
bool is(char x)
{
    if(x=='o'||x=='e'||x=='i'||x=='u'||x=='a'||x=='n')return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
   /* cin>>s;n=s.size();
    for(int i=0;i<s.size()-1;i++)
    {
        if(!is(s[i]))if(!is(s[i+1]))return cout<<"NO",0;
    }
    if(!is(s[n-1]))cout<<"NO";
    else cout<<"YES";*/
int x,y;
bool ans=true;
    cin>>n;int cur=1e9;
    for(int i=0;i<n;i++)
    {cin>>x>>y;if(x>y)swap(x,y);
    if(cur>=y)cur=y;
    else if(cur>=x)cur=x;
    else ans=false;
    }

if(ans)cout<<"Yes";
else cout<<"No";

return 0;
}