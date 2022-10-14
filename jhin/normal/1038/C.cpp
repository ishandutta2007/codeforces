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
int m,x,n,y,k,z,zero,l,r,pos,t,gd1,gd2,a[200003],ans=1e9;string s,s2;vector<int>v1,v2;char ch;long long ans1,ans2;



int main()
{
ios_base::sync_with_stdio(false);

cin>>n;
for(int i=0;i<n;i++){cin>>x;v1.push_back(x);}
for(int i=0;i<n;i++){cin>>x;v2.push_back(x);}
sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
while(!v1.empty()||!v2.empty())
{
    if(v1.empty())v2.pop_back();
    else{
            if(v2.empty()){ans1+=*--v1.end();v1.pop_back();}
            else{if(*--v1.end()>=*--v2.end()){ans1+=*--v1.end();v1.pop_back();}
    else v2.pop_back();}}
    if(v2.empty())v1.pop_back();
    else{
            if(v1.empty()){ans2+=*--v2.end();v2.pop_back();}
            else{if(*--v2.end()>=*--v1.end()){ans2+=*--v2.end();v2.pop_back();}
    else v1.pop_back();}}
}
cout<<ans1-ans2;
return 0;
}