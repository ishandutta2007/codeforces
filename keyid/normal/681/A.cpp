#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	bool flag=false;
	int n;
	cin >> n;
	for (int a,b;n--;)
	{
		cin >> s >> a >> b;
		if (a>=2400&&b>a) flag=true;
	}
	if (flag) printf("YES");
	else printf("NO");
	return 0;
}