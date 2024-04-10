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


long long n,a[600003],b,cnt;set<int>bac;string s[300005];int m,k;

int tr=300000;
int main()
{
ios_base::sync_with_stdio(false);
cin>>n;
for(int i=0;i<n;i++)
{
   cin>>s[i];int j=0;m=0;k=0;
   for(;j<s[i].size();j++) {if(m<0)break;if(s[i][j]=='(')m++;else m--;}

   if(m<0)
   {for(int z=s[i].size()-1;z>=j;z--)
   {
       if(s[i][z]=='(')k--;
       else k++;
       if(k<0)break;

   }

   m=-m;
   if(k>=0){m+=k;a[m+tr]++;}
}

else a[m]++;
}
cnt+=a[0]*a[0];
for(int i=1;i<=tr;i++)
{
    cnt+=a[i]*a[i+tr];
}
cout<<cnt;
return 0;
}