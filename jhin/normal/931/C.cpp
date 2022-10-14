// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;

int x,y,cnt1,cnt2,k,n,m,t,d,sum,z,op;int ans=1e7;
/*int ho,mi;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
}*/
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
int a[100003],mx=-100000,mn=100000,nx,nm,mid;
int main()
{
ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];mx=max(mx,a[i]);mn=min(mn,a[i]);}
    for(int i=0;i<n;i++){if(a[i]==mx)nx++;if(a[i]==mn)nm++;}
    nx=min(nx,nm);nm=min(nm,nx);
    if(mx-mn>1)
    {   for(int i=0;i<n;i++)if(a[i]==mx-1)mid++;if(mid%2)mid--;
        if(mid<nx+nm)
        {   cout<<n-nm-nx<<endl;
            for(int i=0;i<n;i++)
            {
            if(a[i]==mx&&nx)cout<<a[i]-1<<" ",nx--;
            else if(a[i]==mn&&nm)cout<<a[i]+1<<" ",nm--;
            else cout<<a[i]<<" ";}
        }
        else
        {
            cout<<n-mid<<endl;
            for(int i=0;i<n;i++)
            {
                if(a[i]==mx-1&&mid)
                {
                    if(mid%2==0)cout<<a[i]+1<<" ";
                    else cout<<a[i]-1<<" ";mid--;
                }
                else cout<<a[i]<<" ";
            }
        }

    }
    else
        {cout<<n<<endl;
        for(int i=0;i<n;i++)cout<<a[i]<<" ";}



    return 0;
}