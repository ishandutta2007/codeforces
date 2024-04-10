#include <bits/stdc++.h>
using namespace std;
map < long long , vector < long long > > a;
long long visi[100]={0},l[100]={0},d[100]={0};
void dfs(long long node,long long r,char c)
{
    visi[node]=1;
    long long f=0;
   for(long long i=0;i<a[node].size();i++)
   {
     if(visi[a[node][i]]) continue;
     if(c!='r' && f==0) {l[a[node][i]]=l[node]+r/2;f=1;d[a[node][i]]=d[node];dfs(a[node][i],r/2,'l');}
     else if(c!='u' && f<=1) {d[a[node][i]]=d[node]+r/2;f=2;l[a[node][i]]=l[node];dfs(a[node][i],r/2,'d');}
     else if(c!='l' && f<=2) {l[a[node][i]]=l[node]-r/2;f=3;d[a[node][i]]=d[node];dfs(a[node][i],r/2,'r');}
     else if(c!='d' && f<=3) {d[a[node][i]]=d[node]-r/2;f=2;l[a[node][i]]=l[node];dfs(a[node][i],r/2,'u');}
   }
}
int main()
{
    long long n,m,x,y,i,f=1;
    cin>>n;
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        if(a[x].size()>4 || a[y].size()>4) f=0;
    }
    if(f==0) {cout<<"NO";exit(0);}
    cout<<"YES"<<endl;
    for(i=1;i<=n;++i)
    {
        if(a[i].size()!=4) {x=i;break;}
    }
    l[1]=0;d[1]=0;
    dfs(x,2147483648,'d');
    for(i=1;i<=n;++i)
    cout<<d[i]<<" "<<l[i]<<endl;
    return 0;
}