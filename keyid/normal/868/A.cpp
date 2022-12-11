#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;

int main()
{
	int n;
	string pa,w[MAXN];
	cin >> pa >> n;
	for (int i=0;i<n;i++)
		cin >> w[i];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			string t=w[i]+w[j];
			if (t.find(pa)!=string::npos)
			{
				printf("YES");
				return 0;
			}
		}
	printf("NO");
	return 0;
}