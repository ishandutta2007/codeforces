// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
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
{    ll num=1;
    for(int i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=((num)*i);
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

int n,m;char a[1000][1000]={'.'};multiset<int> myset;bool ans=true;
bool checkdot(int i,int j)
{
    if(a[i+1][j]=='*')return false;
    if(a[i+1][j-1]=='*')return false;
    if(a[i+1][j+1]=='*')return false;
    if(a[i-1][j]=='*')return false;
    if(a[i-1][j+1]=='*')return false;
    if(a[i-1][j-1]=='*')return false;
    if(a[i][j-1]=='*')return false;
    if(a[i][j+1]=='*')return false;
    return true;
}
bool checknum(int i,int j,int num)
{int cnt=0;
    if(a[i+1][j]=='*')cnt++;
    if(a[i+1][j-1]=='*')cnt++;
    if(a[i+1][j+1]=='*')cnt++;
    if(a[i-1][j]=='*')cnt++;
    if(a[i-1][j+1]=='*')cnt++;
    if(a[i-1][j-1]=='*')cnt++;
    if(a[i][j-1]=='*')cnt++;
    if(a[i][j+1]=='*')cnt++;
    if(num==cnt)return true;
    else return false;
}
int main()
{
ios_base::sync_with_stdio(false);


cin>>n>>m;
for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {int tmp=int(a[i][j]);
        if(a[i][j]=='.')if(!checkdot(i,j))return cout<<"NO",0;
        if(a[i][j]=='*') continue;
        if(tmp>=49)if(!checknum(i,j,tmp-48))return cout<<"NO",0;
    }
}
cout<<"YES";




return 0;
}