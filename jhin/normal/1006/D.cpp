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
    for(long long i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=(num%mod*i%mod)%mod;
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
int n,k,m,x,x2,y,ans,z;string s,s2;

int main()
{
    ios_base::sync_with_stdio(false);

cin>>n>>s>>s2;
for(int i=0;i<n/2;i++)
{y=0;x=0;z=0;x2=0;
    if(s[i]==s[n-i-1])x++;
    if(s[i]==s2[n-i-1])z++;
    if(s2[i]==s2[n-i-1])x2++;
    if(s2[i]==s[n-i-1])z++;
    if(s[i]==s2[i])y++;
    if(s[n-i-1]==s2[n-i-1])y++;

    if(y==2||(x+x2==2)||z==2)continue;
    //cout<<y<<" "<<z<<" "<<x2<<endl;
    if(y==1)ans++;
    else if(z||x2) ans++;
    else ans+=2;

}
if(n%2)ans+=(s[n/2]!=s2[n/2]);
cout<<ans;

return 0;
}