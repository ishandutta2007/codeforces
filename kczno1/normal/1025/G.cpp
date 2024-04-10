#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=500+5,D=1e9+7;
int c[N],mi_2[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n;cin>>n;
	rep(i,1,n)
	{
		int x;cin>>x;
		++c[x==-1?i:x];
	}
	mi_2[0]=1;
	rep(i,1,n)mi_2[i]=mi_2[i-1]*2%D;
	int ans=mi_2[n-1]-1;
	rep(i,1,n)
	if(c[i])(ans-=mi_2[c[i]-1]-1)%=D;
	cout<<(ans+D)%D;
}