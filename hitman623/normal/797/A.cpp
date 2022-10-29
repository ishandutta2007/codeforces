#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,i,f[100005]={0},c=0,k,m,d[100005];
    cin>>n>>k;
    if(k==1) {cout<<n;exit(0);}
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            n/=i;
            d[c]=i;
            c++;
            if(c==k-1) break;
            i--;
        }
    }
    if(c==k-1)
    {
	for(i=0;i<c;++i)
	cout<<d[i]<<" ";
	cout<<n;
    }
    else cout<<-1;
    return 0;
}