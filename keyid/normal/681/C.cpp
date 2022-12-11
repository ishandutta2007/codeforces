#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000005;

priority_queue <int,vector<int>,greater<int> > q;
string s[MAXN];
int p[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	int n,cnt=0;
	string op;
	cin >> n;
	for (int x;n--;)
	{
		cin >> op;
		if (op[0]=='i')
		{
			cin >> x;
			s[cnt]=op;
			p[cnt++]=x;
			q.push(x);
		}
		else if (op[0]=='r')
		{
			if (q.empty())
			{
				s[cnt]="insert";
				p[cnt++]=1;
			}
			else q.pop();
			s[cnt++]=op;
		}
		else
		{
			cin >> x;
			while (!q.empty()&&q.top()<x)
			{
				s[cnt++]="removeMin";
				q.pop();
			}
			if (q.empty()||q.top()>x)
			{
				q.push(x);
				s[cnt]="insert";
				p[cnt++]=x;
			}
			s[cnt]=op;
			p[cnt++]=x;
		}
	}
	cout << cnt << '\n';
	for (int i=0;i<cnt;i++)
	{
		cout << s[i];
		if (s[i][0]!='r') cout << ' ' << p[i];
		cout << '\n';
	}
	return 0;
}