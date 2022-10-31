// Hydro submission #62591b7037de167dd82bc1bd@1650006897184
#include<bits/stdc++.h>
using namespace std;
int t,mx;
string s;
bool f[58];
int main()
{
	int i,n;
	cin>>n>>s;
	for(i=0;i<n;i++)
	{
		if(isupper(s[i]))
		mx=max(mx,t),t=0,
		memset(f,false,sizeof(f));
		else if(!f[s[i]-65])
		t++,f[s[i]-65]=true;
	}
	printf("%d\n",max(mx,t));
	return 0;
}