#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

int main()
{
    ll n,l,a[1000],b[1000],k,i,j,f,m,mm,q=0;
    cin>>n>>l;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n;++i)
        cin>>b[i];
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
            {
                f=1;q=0;
                m=a[i]-b[j];
                if(m<0) q=1;
                for(k=0;k<n;++k)
                {
                    mm=a[(i+k)%n]-b[(j+k)%n];
                    if(mm<0 && q==0) mm+=l;
                    else if(mm>0 && q==1) mm-=l;
                    if(mm!=m) {f=0;break;}
                }
                if(f==1) {cout<<"YES";exit(0);}
            }
        }
        cout<<"NO";
    return 0;
}