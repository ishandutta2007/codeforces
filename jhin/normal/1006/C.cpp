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
int my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=(num%mod*i%mod)%mod;
    return int(num);
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
int n,k,m,x;string s;long long sum,a[200001],ans;vector<long long> tmp,b;
void cpy(int i)
{tmp.clear();
    for(int j=n-1;j>=i;j--)tmp.push_back(b[j]);

}
int main()
{
    ios_base::sync_with_stdio(false);
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];b.push_back(a[n-1]);
for(int i=n-2;i>=0;i--)b.push_back(*(--b.end())+a[i]);
for(int i=0;i<n-1;i++)
{
    sum+=a[i];//cpy(i+1);
    //for(int j=0;j<n-i-1;j++)cout<<tmp[j]<<" ";cout<<endl;
    auto it=lower_bound(b.begin(),b.begin()+n-i-2,sum);//cout<<*it<<" it"<<" "<<sum<<endl;
    if(*it==sum){ans=max(ans,sum);}
}

cout<<ans;

return 0;
}