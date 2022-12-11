#include <bits/stdc++.h>
using namespace std;

const int MAXN=1005;

int n,cho[MAXN];
string a[MAXN],b[MAXN];
map <string,int> ms;
set <string> s;

bool solve()
{
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> a[i] >> b[i];
		ms[a[i].substr(0,3)]++;
	}
	for (int i=0;i<n;i++)
		if (ms[a[i].substr(0,3)]>1)
		{
			cho[i]=2;
			string now=a[i].substr(0,2)+b[i][0];
			if (s.find(now)!=s.end())
				return false;
			s.insert(now);
		}
	for (;;)
	{
		bool flag=false;
		for (int i=0;i<n;i++)
			if (!cho[i])
			{
				string t=a[i].substr(0,3);
				if (s.find(t)!=s.end())
				{
					string now=a[i].substr(0,2)+b[i][0];
					if (s.find(now)!=s.end())
						return false;
					s.insert(now);
					cho[i]=2;
					flag=true;
				}
			}
		if (!flag) break;
	}
	for (int i=0;i<n;i++)
		if (!cho[i])
			cho[i]=1;
	return true;
}

int main()
{
	//freopen("read.txt","r",stdin);
	if (solve())
	{
		cout << "YES" << endl;
		for (int i=0;i<n;i++)
		{
			if (cho[i]==1)
				cout << a[i].substr(0,3);
			else
				cout << a[i].substr(0,2)+b[i][0];
			cout << endl;
		}
	}
	else
		cout << "NO" ;
	return 0;
}