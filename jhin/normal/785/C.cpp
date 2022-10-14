#include <bits/stdc++.h>

using namespace std;
#define F for(int i=0;i<n;i++)
const int N=1e5;
long long n,i,m,k,ans1,ans2,maxa,maxb,num,mina=1e9,minb=1e9,ans,sero,a[2][2*N];string s;int zero;
int main()
{
    ios_base::sync_with_stdio();
    cin>>n>>m;
    if(m>=n)cout<<n;
    else
    {   n-=m;num=sqrt(2*n);n-=((num*num)+num)/2;ans=m+num;i=num+1;
        while(n>0)
        {   ans++;
            n-=i;i++;
        }

        cout<<ans;
    }


    return 0;
}