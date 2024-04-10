// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;

int x,cnt1,cnt2,k,n,m,t,d,sum,op;int ans=1e7;ll z;
int ho,mi,se;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
}
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=((num%mod)*i)%mod;
    return num%mod;
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


string s[50];
bool check(int x,int y){for(int j=0;j<m;j++)if(s[x][j]!=s[y][j])return false; return true;}
int main()
{
ios_base::sync_with_stdio(false);

    cin>>n>>m;
    bool dot[n][m];
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
         for(int z=0;z<n;z++)
            if(s[i][j]=='#'&&s[z][j]=='#')if(!check(i,z))return cout<<"No",0;
        }
    }
    cout<<"Yes";
    return 0;
}