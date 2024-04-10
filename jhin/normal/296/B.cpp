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
int n,x,a[100001],mx[1001],ms;long long cnt2=1,cnt=1;string s1,s2;bool gr,lo;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>s1>>s2;
    for(int i=0;i<n;i++)
    {
        if(s1[i]>s2[i]&&s1[i]!='?'&&s2[i]!='?')gr=true;
        if(s1[i]<s2[i]&&s1[i]!='?'&&s2[i]!='?')lo=true;
        if(s1[i]=='?')
        {
            if(s2[i]=='?')a[10]++;
            else a[int(s2[i]-'0')]++;
        }
        else
        if(s2[i]=='?')a[9-int(s1[i]-'0')]++;

    }
    long long ans=1;
    for(int i=0;i<10;i++)ans=(ans*my_pow(10,a[i]))%mod;
   ans=(ans*my_pow(100,a[10]))%mod;
   if(gr&&lo)
     return cout<<ans,0;
   
       for(int i=0;i<10;i++)
        cnt=(cnt*my_pow(10-i,a[i]))%mod;
        cnt=(cnt*my_pow(55,a[10]))%mod;

      for(int i=0;i<10;i++)
        cnt2=(cnt2*my_pow(i+1,a[i]))%mod;
        cnt2=(cnt2*my_pow(55,a[10]))%mod;
        if(gr&&!lo)
            ans-=cnt;
        else if(!gr&&lo)
            ans-=cnt2;

        else
            ans-=cnt+cnt2-my_pow(10,a[10]);
        if(ans<0)ans+=mod;if(ans<0)ans+=mod;
        cout<<ans;

return 0;
}