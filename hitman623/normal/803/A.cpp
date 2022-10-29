#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,k,i,a[103][103]={0},j,m;
    cin>>n>>k;
    if(k>n*n) {cout<<-1;exit(0);}
    for(i=0;i<n;++i)
    {
        if(k>0) {a[i][i]=1;k--;}
        for(j=i+1;j<n;++j)
        {
            if(k<2) break;
            a[i][j]=1;
            a[j][i]=1;
            k-=2;
        }
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}