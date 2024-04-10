

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
void pfact(long long x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(long long i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
int m,x,n,y=1e9,k,z,zero,l,r,pos,t,gd1,gd2,b[200003];string s,s2;vector<int>v;int a[1000001][10];bool vis[1000001];
//1 2 3 4 5 6 7
int ans(int x)
{int an=1;
    while(x){int tmp=x%10;if(tmp)an*=tmp;x/=10;}
    return an;
}
void solve(int x)
{   if(x<10){for(int i=0;i<v.size();i++)
             {a[v[i]][x]=1;vis[v[i]]=true;}v.clear();a[x][x]=1;return;}
    int tmp=ans(x);v.push_back(x);
    solve(tmp);
}
int main()
{
ios_base::sync_with_stdio(false);
for(int i=1000000;i>0;i--)
{
if(!vis[i])
    solve(i);
}for(int i=1;i<10;i++)
for(int j=1;j<1000001;j++)a[j][i]+=a[j-1][i];

cin>>n;
for(int i=0;i<n;i++)
{
    cin>>l>>r>>k;
cout<<a[r][k]-a[l][k]+(a[l][k]>a[l-1][k]?1:0)<<endl;
}


return 0;
}