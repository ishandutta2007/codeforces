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


long long fact(int x)
{  long long cnt2=1;int cnt=1;
    while(cnt<=x)cnt2*=cnt,cnt++;
    return cnt2;
}


vector<int>nums[10];long long n,ans;
int a[10];
long long res()
{ long long cnt=0,cnt2=1;
    for(int i=1;i<10;i++)
        {cnt+=a[i];cnt2*=fact(a[i]);}
        long long ans1=fact(cnt)/cnt2;
        if(!a[0])return ans1;

        ans1=fact(cnt+a[0])/(cnt2*fact(a[0]))-(fact(cnt+a[0]-1)/(cnt2*fact(a[0]-1)));
return ans1;

}
void do_it(int i)
{    if(i==10){ans+=res();return;}
if(nums[i].empty())do_it(i+1);
    for(int j=0;j<nums[i].size();j++)
    {a[i]=nums[i][j];do_it(i+1);}
}



int main()
{
cin>>n;
while(n){int tmp=int(n%10);n/=10;a[tmp]++;}
//for(int i=0;i<10;i++)cout<<a[i]<<" ";cout<<endl;
for(int i=0;i<10;i++)
{
    for(int j=1;j<=a[i];j++)nums[i].push_back(j);
}

do_it(0);
cout<<ans;
return 0;
}