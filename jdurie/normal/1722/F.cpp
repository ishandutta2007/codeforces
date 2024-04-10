#include<bits/stdc++.h>
using namespace std;
#define F(i,r)for(int i=0;i<r;++i)
string g[50],s;int t,n,m,p,q,c;int main(){cin>>t;F(u,t){cin>>n>>m;F(i,n)cin>>g[i];s="YES ";F(i,n)F(j,m)if(g[i][j]-46){p=q=c=1;F(k,n)F(l,m)if((abs(i-k)|abs(j-l))+g[k][l]==43)p*=k-i,q*=l-j,c++;if(c-3|(p|q)*(p+q-1))s="NO ";}cout<<s;}}