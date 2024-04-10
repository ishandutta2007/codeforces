#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int A[200005];
void solve(int a,int b,int k,int x,int y)
{
    if(k==0)
    {
        int cur=x+1;
        for(int i=a;i<b;++i)
        A[i]=cur++;
        return ;
    }
    if(k==2*(b-a)-2)
    {
        int cur=y;
        for(int i=a;i<b;++i)
        A[i]=cur--;
        return;
    }
    int m=(a+b)/2,t1,t2,i,mm=(x+y+1)/2;
    t1=m-a;
    t2=b-m;
    k-=2;
    solve(a,m,min(k,2*t1-2),mm,y);
    solve(m,b,k-min(k,2*t1-2),x,mm);
}
int main()
{
    io
    int n,k,i;
    cin>>n>>k;
    if(k>2*n-1 || k%2==0) {cout<<-1;return 0;}
    solve(0,n,k-1,0,n);
    for(i=0;i<n;++i)
    cout<<A[i]<<" ";
    return 0;
}