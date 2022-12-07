#include <bits/stdc++.h>
using namespace std;

#define fill(a,val) memset(a, (val), sizeof a)
#define pb push_back
#define lli long long int
#define scantype int
#define endl "\n"
#define unique(x) x.erase(unique(x.begin(),x.end()), x.end())
#define sort_f(x)  sort(x.begin(),x.end());
#define sort_r(x)  sort(x.rbegin(),x.rend());

lli MOD  =1000007.;
lli inf = 1e15;

void scan(scantype &x);
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli string_to_number(string s){lli x=0; stringstream convert(s); convert>>x; return x;}
lli add(lli a,lli b){lli x = (a+b)%MOD; return x; }
lli mul(lli a,lli b){lli x = (a*b)%MOD; return x; }
lli sub(lli a,lli b){lli x = (a-b+MOD)%MOD; return x; }
lli divi(lli a,lli b){lli x = a;lli y = powermod(b,MOD-2,MOD);lli res = (x*y)%MOD;return res;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    int arr[n+1];
    fill(arr,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int frq[n+1][m+1];
    fill(frq,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i]==j)
            {
                frq[i][j]=1;
            }
            else
            {
                frq[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            frq[i][j]+=frq[i-1][j];
        }
    }
    int temp[m+1];
    for(int i=1;i<=m;i++)
    {
        cin>>temp[i];
    }
    int flag;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            flag=1;
            for(int k=1;k<=m;k++)
            {
                if((frq[j][k]-frq[i][k])!=temp[k])
                {
                   flag=0; 
                }
            }
            if(flag==1)
            {
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    if(flag)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}