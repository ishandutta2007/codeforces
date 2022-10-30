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

long long find(string s,int l,int r)
{
	long long t=0;
	for (int i=l;i>=r;i--)
	{
		t=t*10ll+s[i]-'0';
	}
	return t;
}

bool bad(string s,int l,int r)
{
	for (int i=l;i>=r;i--)
	{
		if (s[i]!='9') return 1;
	}
	return 0;
}

string tostring(long long n)
{
	if (n==0) return 0;
	string t="";
	while (n>0)
	{
		t+='0'+n%10;
		n/=10;
	}
	return t;
}

int main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	long long r,l;
	cin>>r>>l;
	long long last=r;
	l=r-l;
	string R=tostring(r);
	string L=tostring(l);
	while (L.size()<R.size()) L+='0';
	for (int i=R.size()-1;i>=0;i--)
	{
		l=find(L,R.size()-1,i+1);
		r=find(R,R.size()-1,i+1);
		if (bad(R,i,0)) r--;
		if (r>=l)
		{
			if (r!=0) cout<<r;
			for (int j=i;j>=0;j--) cout<<9;
			cout<<endl;
			return 0;
		}
	}
	cout<<last<<endl;
	return 0;
}