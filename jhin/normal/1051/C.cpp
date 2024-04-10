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

bool prime[2500001];
void sieve(){
    for(int i=2;i<=2250000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=1500;i+=2)
        if(prime[i])
            for(int j=i*i;j<=2250000;j+=2*i)
                prime[j]=false;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
long long gcd(long long a , long long b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,one,two,mx,mn=1e9,l,r,pos,t,a[300003],b[1003];string s,s2;vector<int>v,v2;long long ans;



int main()
{
ios_base::sync_with_stdio(false);

cin>>n;
for(int i=0;i<n;i++){cin>>a[i];b[a[i]]++;}
for(int i=1;i<=100;i++){if(b[i]==1)one++;if(b[i]>2)two=i;}
for(int i=0;i<n;i++)s+='A';
for(int i=0;i<n;i++){if(a[i]==two&&one%2){s[i]='B';break;}}
if(one%2&&!two)cout<<"NO";
else
{
    cout<<"YES"<<endl;
    char prev='B';
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')continue;
        if(prev=='A'&&b[a[i]]==1)s[i]='B',prev='B';
        else if(prev=='B'&&b[a[i]]==1)prev='A';


    }
    cout<<s;
}
return 0;
}