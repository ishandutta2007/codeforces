#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char t;
	int a,u=0,l=0;
	string us,ls,s,t1;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		t=s[i];
		a=t;
		if(a<93)
		{
			u+=1;
			t1=t;
			us.append(t1);
			t+=32;
			t1=t;
			ls.append(t1);
		}
		else
		{
			l+=1;
			t1=t;
			ls.append(t1);
			t-=32;
			t1=t;
			us.append(t1);		
		}
	}
	if (u>l)
	cout<<us;
	else
	cout<<ls;
	return 0;
}