#include<bits/stdc++.h>
using namespace std;
int tab[30];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,a,c,i;
	string s;
	cin>>n>>k;
	cin>>s;
	if(n==k)
		return 0;
	for(i=0;i<n;i++)
		tab[s[i]-'a']++;
	a=0;
	i=0;
	while(a+tab[i]<=k)
	{
		a+=tab[i];
		i++;
	}
	a=k-a;
	c=i;
	for(i=0;i<n;i++)
	{
		if(s[i]-'a'>c)
			cout<<s[i];
		else if(s[i]-'a'==c)
		{
			if(a>0)
				a--;
			else
				cout<<s[i];
		}
	}
	return 0;
}