#include <bits\stdc++.h>
using namespace std;

string s;
vector<int> len;int n;

bool check(int x)
{
	int i,ss=0,len=0,cur=0,llen=0;
	char lst='-';
	
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='-'||s[i]==' '||s[i]==123)
		{
			if (s[i]!=123) cur++;
			if (len+cur<=x)
			{
				len+=cur;
			}
			else if (cur<=x)
			{
				ss++;
				len=cur;
			}
			else return 0;
			cur=0;
		}
		else cur++;
	}
	
	return ss<n;
}
int main()
{
	ios_base::sync_with_stdio(0);
	
	int m,i,j,l,r,mid,ans;
	
	cin>>n;
	getline(cin,s);
	getline(cin,s);
	s.push_back(123);
	
	l=0;ans=r=s.size();
	
	while (l<r)
	{
		mid=(l+r+1)/2;
		if (check(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else l=mid;
	}
	
	cout<<ans<<endl;
	return 0;
}