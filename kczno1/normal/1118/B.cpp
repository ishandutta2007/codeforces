#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5;
int a[N],s[N][2];

int main()
{
#ifdef kcz
//	freopen("1.in","r",stdin); 
#endif
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n)
	rep(j,0,1)s[i][j]=s[i-1][j]+(i%2==j)*a[i];
	int ans=0;
	rep(i,1,n)
	if(s[i-1][1]-s[i-1][0]-(s[n][1]-s[i][1]-s[n][0]+s[i][0])==0)++ans;
	cout<<ans;
}