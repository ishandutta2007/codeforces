// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;



#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
//vector<int> p;


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

long long n,a[100001],m,x,y,ans,z,l,t;string s;

int main()
{
    ios_base::sync_with_stdio(false);
     cin>>n>>t;
     while(t--)
     {
         cin>>x>>y;
         if((x+y)%2==0)
         {
             if(n%2==0)
                cout<<(x-1)*(n/2)+(y+1)/2<<endl;
             else
             {
                 cout<<(x-1)/2*(n/2)+x/2*(n/2+1)+(y+1)/2<<endl;
             }
         }
         else
         {
            if(n%2==0)
                cout<<(n*n)/2+(x-1)*(n/2)+(y+1)/2<<endl;
             else
             {
                 cout<<(n*n)/2+(x-1)/2*(n/2+1)+x/2*(n/2)+(y+1)/2+1<<endl;
             }
         }
     }


return 0;
}