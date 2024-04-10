// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;


int ho,mi,se;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
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

int n,x,y,m,cnt1,k,cnt2,a[100001];string s;
int main()
{
ios_base::sync_with_stdio(false);

   cin>>n>>k;
   cout<<"YES"<<endl;
   for(int i=0;i<n;i++)s+='.';
   cout<<s<<endl;string s2=s;
   if(k%2==0)
   {int tmp=k/2;
       for(int i=1;i<n-1&&tmp>0;i++)s2[i]='#',tmp--;
       cout<<s2<<endl<<s2<<endl<<s;return 0;
   }
   int i,j;s2[n/2]='#';cnt1=k-1;
   for(i=n/2-1,j=n/2+1;i>0&&cnt1>0;i--,j++,cnt1-=2)
       s2[i]='#',s2[j]='#';

   cout<<s2<<endl;s2=s;i++,j--;

   for(;i<n/2&&cnt1>0;i++,j--,cnt1-=2)
       s2[i]='#',s2[j]='#';
   cout<<s2<<endl<<s;





    return 0;
}