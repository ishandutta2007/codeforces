#include <iostream>
#include<algorithm>

using namespace std;

const int MAXN=1100000;
int f[MAXN],k,n,m,a[MAXN],ans=1,MAX;
bool mark[MAXN];
string p;

void kmp()
{
    f[0]=0,f[1]=0;
    for(int i=2;i<=p.size();i++)
    {
        while(k>0 && p[i-1]!=p[k])
            k=f[k];
        if(p[i-1]==p[k])
            k++;
        f[i]=k;
       // cout<<i<<" "<<f[i]<<endl;
    }
}

int main()
{
    cin>>n>>m>>p;
    kmp();
    k=p.size();
    while(k>0)
    {

        k=f[k];
        mark[k]=true;
    }
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    k=0;
    for(int i=0;i<n;i++)
    {
       //     cout<<i<<" "<<k<<" "<<a[k]<<" "<<MAX<<endl;
        if(k<m && i==a[k])
        {
            if(!mark[MAX])
            {
              //  cout<<mark[MAX]<<endl;
                cout<<0<<endl;
                return 0;
            }
            MAX=p.size();
            k++;
        }
        if(MAX==0)
            ans=((long long)ans*26)%1000000007;
        if(MAX>0)
            MAX--;
    }
    cout<<ans<<endl;
}