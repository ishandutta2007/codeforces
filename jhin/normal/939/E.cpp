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
vector<double> sets;double avrg,mx,y;
int main()
{
ios_base::sync_with_stdio(false);

    cin>>n;cin>>x>>y;n--;
    sets.push_back(y);avrg=y;
    while(n){cin>>x;n--;if(x==2)cout<<'0'<<endl;
             if(x==1){cin>>y;sets.push_back(y);mx=y;avrg=(sets[0]+sets[1]);break;}}
    int j=2,jm=1;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x==1)
        {cin>>y;sets.push_back(y);
         mx=y;jm++;
         if(y>sets[jm-1]){avrg+=sets[jm]-sets[jm-1];
         while(sets[j-1]<avrg/j){avrg+=sets[j-1];j++;}
        }}
        else cout<<setprecision(14)<<mx-(avrg/double(j))<<endl;
    }


    return 0;
}