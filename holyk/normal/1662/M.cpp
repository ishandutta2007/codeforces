#include <bits/stdc++.h>
using namespace std;
int main()
{
  //cin.tie(nullptr)->sync.with.stdio(false);
  int T;cin>>T;
  while(T--)
    {
      int n,m;cin>>n>>m;
      int ma=0,mb=0;
      for(int i=1;i<=m;i++){
	int a,b;cin>>a>>b;
	ma=max(ma,a),mb=max(mb,b);
      }
      if(ma+mb>n)cout<<"IMPOSSIBLE"<<endl;
      else{
	for(int i=1;i<=ma;i++)cout<<"R";
	for(int i=1;i<=n-ma;i++)cout<<"W";
	cout<<endl;
      }
    }
  return 0;
}