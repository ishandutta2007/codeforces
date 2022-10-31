// Hydro submission #6253d3b548f783013279296e@1649660854498
#include<bits/stdc++.h>
using namespace std;
int m[1000],s[2];
int main()
{
	int n,i,l,r,t;
	cin>>n;
	for(i=1;i<=n;++i)
	cin>>m[i];
	l=1,r=n,t=1;
	while(l<=r)
	{
		if(m[l]<m[r])
		s[t]+=m[r--];
		else
		s[t]+=m[l++];
		t=1-t;
	}
	printf("%d %d",s[1],s[0]);
	return 0;
}