#include <bits/stdc++.h>
using namespace std;

list<int> l;
int n;

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		l.push_back(x);
	}
	l.sort();
	while (!l.empty())
	{
		printf("%d ", l.front()); l.pop_front();
		if (l.empty()) break;
		printf("%d ", l.back()); l.pop_back();
	}
	printf("\n");
	return 0;
}