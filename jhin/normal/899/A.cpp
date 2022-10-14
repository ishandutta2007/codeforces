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
int n,k,m,x,y,l,l2,z,a[200001],b[100001],ans;map<int,int>nums;pair<int,int>p1,p2;


int main()
{
    ios_base::sync_with_stdio(false);
cin>>n;
for(int i=0;i<n;i++)cin>>x,a[x]++;
ans+=min(a[2],a[1]);
a[1]-=ans;
ans+=a[1]/3;
cout<<ans;
/*for(int i=0;i<3;i++)
{
    a[1+i*12]=31;a[2+i*12]=28;a[3+i*12]=31;a[4+i*12]=30;a[5+i*12]=31;a[6+i*12]=30;
    a[7+i*12]=31;a[8+i*12]=31;a[9+i*12]=30;a[10+i*12]=31;a[11+i*12]=30;a[12+i*12]=31;
}//31 28 31 30 31 30 31 31 30 31 30 31 31 29 31 30 31 30 31 31 30 31 30 31
cin>>n;
for(int i=0;i<n;i++)cin>>b[i];
for(int i=1;i<=12;i++)
{l=0;
    if(a[i]==b[0]||a[i]==28&&b[0]==29)
    for(int j=i;j<i+n;j++)
    {if(b[j-i]==29&&a[j]==28){if(!l)l=1;else break;}
     else if(a[j]!=b[j-i])break;
     if(j==i+n-1)return cout<<"Yes",0;}

}
cout<<"No";
*/
/*1 2 3 4 5 6 7 8 9 10

2 3 5 8 9 = 22
1 4 6 7 10 = 23
1 +3+5
2+4+6*/
return 0;
}