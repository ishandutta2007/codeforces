#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int solve()
{
	string s;
	cin>>s;
	int l,r;
	for(l=0;l<s.size() && s[l]=='1';l++);
	for(r=s.size()-1;r>=0 && s[r]=='1';r--);
	if(l==s.size())
		return 0;
	for(int i=l;i<=r;i++)
	{
		if(s[i]=='1')
			return 2;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		cout<<solve()<<"\n";
	return 0;
}