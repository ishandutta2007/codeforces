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
long long n,k,m,x,z;int y;
long long tos(int x)
{string tmp="";
    while(x)
    {int t=x%10;
        tmp+=char(48+t);
        x/=10;
    }
    long long t=0,si=tmp.size();
    for(int i=si-1,j=0;i>=0;i--,j++)
    {
        t+=my_pow(10,i)*int(tmp[j]-'0');
    }
     return t;
}
int main()
{
    ios_base::sync_with_stdio(false);
cin>>n>>m;y=1;//cout<<(tos(10)*my_pow(10,2)))
while(n--)
{int kh=log10(y)+1;
x=(x+y*my_pow(10,kh)+tos(y))%m;
    y++;
}

cout<<x;
return 0;
}