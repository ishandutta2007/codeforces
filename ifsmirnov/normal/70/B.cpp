#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> a;
string s;

void scan();
int solve();

int main()
{
//	freopen("input.txt", "r", stdin);
	scan();
	int t = solve();
	if (t == -1)
		cout << "Impossible";
	else
		cout << t;	
	return 0;
};

void scan()
{
	scanf("%d", &n);
};	

int solve()
{
	string cur;
	char t = '\n';
	while (t == '\n')
		scanf("%c", &t);
	while (1)
	{
		cur.push_back(t);
		if (t == '?' || t == '.' || t == '!')
		{
			a.push_back(cur.length());
			cur = "";
			scanf("%c", &t);
		}
		if (scanf("%c", &t) != 1)
			break;
	}
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > n)
			return -1;
	}
	int sum = n+1, cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{	
		if (sum + a[i] + 1 > n)
		{
			cnt++;
			sum = a[i];
		}
		else
		{
			sum += a[i] + 1;
		}
	}
	return cnt;
};