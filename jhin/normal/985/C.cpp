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


ll n,m,b,cnt,x,y,mnus,l,ans,k,a[100003];


int main()
{
ios_base::sync_with_stdio(false);
cin>>n>>k>>l;m=n*k;
for(int i=0;i<m;i++)
    cin>>a[i];
sort(a,a+m);
int low=0;
while(a[low]-a[0]<=l&&low<m)low++;low--;
int high=m-low-1;
if(k==1)
    {if(high)cout<<"0";
else {for(int i=0;i<m;i++)ans+=a[i];cout<<ans;}}
else{
int test=high/(k-1);
mnus=high%(k-1);
//cout<<mnus<<" "<<test<<" "<<high<<endl;


if(test>low+1)return cout<<"0",0;
while(test--)
    ans+=a[low--];//1 2 2 2 3 3 4 4 4 9 10 11
low-=k-mnus-1;
while(low>=0)
ans+=a[low],low-=k;
cout<<ans;
}

return 0;
}