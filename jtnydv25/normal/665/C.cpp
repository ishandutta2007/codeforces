#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int cnt = 0,st = 0,i=0,len = s.length();
	char c1,c2,nw;
	while(i<len)
	{
		st = i;
		while(s[i] == s[st] && i<len)
			i++;
		cnt = i - st;
		if(cnt>1)
		{
			c1 = s[st];
			c2 = 'a';
			if(i!=len)
				c2 = s[i];
		}
		nw = 'a';
		if(nw == c1 || nw== c2)
			nw = 'b';
		if(nw==c1 || nw == c2)
			nw = 'c';
		if(nw==c1 || nw == c2)
			nw = 'd';
		for(int j = st+1;j<i;j+=2)
			s[j] = nw;
	}
	cout<<s;
}