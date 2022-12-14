#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,c1,c2,c[2],ans=9e18,i;
char ch;
int cal(int x){return c1+c2*(x-1)*(x-1);}
main(){
	cin>>n>>c1>>c2;
	for(i=1;i<=n;++i)cin>>ch,++c[ch-'0'];
	for(i=1;i<=c[1];++i)ans=min(ans,n%i*cal(n/i+1)+(i-n%i)*cal(n/i));
	cout<<ans;
}