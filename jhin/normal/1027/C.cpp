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

int n,m,x,y,z,l,t;string s;int a[10001];

int main()
{

     scanf("%d",&t);
     while(t--)
     {int ans=0,ans2=0,z=0;double mx=1e9;
         scanf("%d",&n);vector<int>b;
         memset(a,0,sizeof(a));
         for(int i=0;i<n;i++){scanf("%d",&x);a[x]++;if(a[x]==2)b.push_back(x),a[x]=0;}
         sort(b.begin(),b.end());
         if(!ans)
         for(int i=0;i<b.size();i++)
            {
                if(!z){z=b[i];continue;}
                if((b[i]*b[i]+z*z)/double(b[i]*z)<=mx)mx=(b[i]*b[i]+z*z)/double(b[i]*z),ans2=b[i],ans=z;z=b[i];
            }
         //for(int i=0;i<10001;i++)if(a[i]>3)ans=i,ans2=i;
         printf("%d %d %d %d\n",ans,ans,ans2,ans2);
     }

return 0;
}