// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;

int x,cnt1,cnt2,k,n,m,t,d,sum,op;int ans=1e7;ll z;
int ho,mi,se;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
}
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=((num%mod)*i)%mod;
    return num%mod;
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
int a,b,cnt3;char st[200000];vector<int> gr;
int main()
{
ios_base::sync_with_stdio(false);

       cin>>n>>a>>b;int nn=n;
       for(int i=0;i<n;i++)
       {
           cin>>st[i];
           if(st[i]!='*')cnt1++;
           else if(cnt1!=0) gr.push_back(cnt1),cnt1=0;if(cnt1!=0&&i==n-1)gr.push_back(cnt1);
           //cout<<cnt1<<endl;
       }
       sort(gr.begin(),gr.end());int siz=gr.size();
       //for(int j=siz-1;j>=0;j--)cout<<gr[j]<<endl;
       for(int j=siz-1;j>=0;j--)
       {
           if(b>a)swap(a,b);

           if(gr[j]>=b*2){cnt2+=b*2;gr[j]-=b*2;a-=b;b=0;}

           else {cnt3=(gr[j]/2)*2;gr[j]-=cnt3;b-=cnt3/2;a-=cnt3/2;cnt2+=cnt3;}

           if(gr[j]&&a)
           {    cnt3=(gr[j]+1)/2;
               if(cnt3>=a){cnt2+=a;a=0;}
               else {a-=cnt3;cnt2+=cnt3;}
           }

if(a==0&&b==0)break;

       }
cout<<cnt2;

    return 0;
}