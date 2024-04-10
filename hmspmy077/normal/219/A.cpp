#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int f[10005];

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int k;
	cin>>k;
	string s;
	cin>>s;
	int n=s.size();
	for (int i=0;i<n;i++) f[s[i]]++;
	int ok=1;
	string ans="";
	for (char c='a';c<='z';c++)
	{
		if (f[c]%k!=0) ok=0;
		for (int i=0;i<f[c]/k;i++) ans+=c;
	}
	if (ok==0) cout<<-1<<endl;
	else
	{
		for (int i=0;i<k;i++) cout<<ans;
		cout<<endl;
	}
	return 0;
}