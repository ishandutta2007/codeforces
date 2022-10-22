#include<bits/stdc++.h>
using namespace std;
int pref[100010];
int suf[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,w,a,ile,g,i;
	string s;
	cin>>n;
	cin>>s;
	if(s[0]=='G')
		pref[0]=1;
	for(i=1;i<n;i++)
	{
		if(s[i]=='G')
			pref[i]=pref[i-1]+1;
	}
	w=0;
	for(i=n-1;i>=0;i--)
	{
		if(s[i]=='G')
			suf[i]=suf[i+1]+1;
		w=max(w,suf[i]);
	}
	ile=0;
	a=0;
	i=0;
	g=0;
	while((i<n)&&(s[i]!='G'))
		i++;
	for(;i<n;i++)
	{
		if(s[i]=='S')
			a++;
		else
		{
			ile+=a;
			a=0;
			g++;
		}
	}
	if(ile<=1)
	{
		cout<<g;
		return 0;
	}
	for(i=1;i<n;i++)
	{
		if(s[i]=='G')
			continue;
		w=max(w,pref[i-1]+suf[i+1]+1);
	}
	cout<<w;
	return 0;
}