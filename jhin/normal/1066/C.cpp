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

void pfact(long long x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(long long i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,mx,one,gd,two,mn=1e9,l,r,pos,t,a[500003],b[500003];string s,s2;vector<int>v,v2;long long ans,num1,num,num2,num3;char ch;
vector<pair<int,int>>r1,r2;

int main()
{

ios_base::sync_with_stdio(false);

/*cin>>n>>m;
int prevs1,prevs2=0;
for(int i=1;i<=n;i++){cin>>a[i];if(a[i])v.push_back(i);}
if(!v.empty())for(int i=max(v[0]-m+1,1);i<min(v[0]+m,n+1);i++)b[i]=v[0];
if(v.size()>1)
{int khra=*(--v.end());
    for(int i=max(khra-m+1,1);i<min(khra+m,n+1);i++)
        if(!b[i])b[i]=khra;
}
for(int i=1;i<v.size()-1;i++)
{
    int tmp=max(v[i]-m+1,0);
    int tmp2=max(v[i]-1,0);
    if(b[tmp]==b[tmp2])
    {
        for(int i=tmp;i<tmp+m;i++)
    }


}
*/
cin>>n>>ch>>x;b[x]=200000;
int left=199999,right=200001;
for(int i=1;i<n;i++)
{cin>>ch>>y;
if(ch=='L')a[left]=y,b[y]=left,left--;
if(ch=='R')a[right]=y,b[y]=right,right++;
if(ch=='?')
{

    int tmp=b[y]-left-1;
    int tmp2=right-b[y]-1;
    cout<<min(tmp,tmp2)<<endl;

}
}
return 0;
}