#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n,m;

int main()
{
	cin>>n>>m;
	int a = -10, b = 2000, x = 0, y = 0;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			if (x > y)
			{
				int sw;
				sw = x;
				x = y;
				y = sw;
			}
			if (x > a) a = x;
			if (y < b) b = y;
		}
		if (a<=b)
		{
			if ((m>=a)&&(m<=b)) cout<<0; else
			cout<<(min(abs(m-a),abs(m-b)));
		} else cout<<-1;
		



	return 0;
}