#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,a[505],b[505];vector<pair<int,int> >op;
#define F(X,Y) op.push_back({X,Y});reverse(a+X,a+Y+1);return 1;
bool fuck(int x){int i,j,k,xy=0;for(i=x;i<=n;i++){if(a[i-1]==b[x-1]&&a[i]==b[x]&&!xy){xy=i;}if(a[i-1]==b[x]&&a[i]==b[x-1]){x--;F(x,i);}}if(xy)for(i=xy-1;i>=x;i--)for(j=xy;j<=n;j++)if(a[i]==a[j]){F(i,j);}
return 0;}main(){cin>>t;while(t--){int cnt=0;cin>>n;op.clear();for(i=1;i<=n;i++){cin>>a[i];}for(i=1;i<=n;i++){cin>>b[i];}if(a[1]!=b[1]||a[n]!=b[n]){cout<<"NO\n";continue;}aa:;cnt++;
if(cnt>n*n){cout<<"NO\n";continue;}for(i=2;i<n;i++)if(a[i]!=b[i]){if(fuck(i)){goto aa;}else{cout<<"NO\n";goto aaa;}}cout<<"YES\n"<<op.size()<<'\n';for(auto [x,y]:op){cout<<x<<' '<<y<<'\n';}aaa:;}}