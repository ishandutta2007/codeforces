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
    if(ho<0)ho+=24;if(ho>24)ho-=24;
}
long long my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=(num*i);
    return num;
}

bool prime[16000003];
void sieve(){
    for(int i=2;i<=16000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=4000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=16000000;j+=2*i)
                prime[j]=false;
}


int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,mx,one,gd,two,mn=1e9,l,r,pos,t,a[300003];string s,s2;vector<int>v2;long long ans;char ch;



int main()
{
ios_base::sync_with_stdio(false);
cin>>n;y=n;
while(n--){cin>>ch;if(ch=='8')x++;}
cout<<min(x,y/11);

return 0;
}