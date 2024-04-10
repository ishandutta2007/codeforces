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
int n,k,m,x,x2,y,z;vector<int>a[200001],ans;int b[200001],c[200001];
int dfs(int x)
{
    for(int i=0;i<a[x].size();i++)
       {ans.push_back(a[x][i]);c[a[x][i]]=ans.size()-1;b[x]+=dfs(a[x][i]);}
        b[x]++;
    return b[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
cin>>n>>k;
for(int i=2;i<=n;i++)
{cin>>y;a[y].push_back(i);}
ans.push_back(1);
dfs(1);
for(int i=0;i<k;i++)
    {cin>>x>>y;
    if(b[x]<y)cout<<-1<<endl;
    else      cout<<ans[c[x]+y-1]<<endl;}



return 0;
}