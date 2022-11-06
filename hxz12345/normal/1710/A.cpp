#include<bits/stdc++.h>
using namespace std;
long long i,T,n,m,k,a[1234567];
bool ccc(long long x,long long y){
long long xxx=0;
bool yyy=false;
for (int i=1;i<=k;i++) 
  if ((a[i]/x>=2)){
  	xxx=xxx+(a[i]/x);if (a[i]/x>=3) yyy=true;
}
if ((xxx>=y)&&(((y&1)&&yyy)||(y % 2==0))) return true;
return false;
}
int main()
{
	cin>>T;
	for (;T;T--){
		cin>>n>>m>>k;
		for (i=1;i<=k;i++) cin>>a[i];
		if (ccc(n,m)||ccc(m,n)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
return 0;
}