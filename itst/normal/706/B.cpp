#include<bits/stdc++.h>
using namespace std;
int num[100001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0 ; i - n ; i++)	cin >> num[i];
	sort(num , num + n);
	int m;
	for(cin >> m ; m ; m--)
	{
		int a , h = -1 , t = n;
		cin >> a;
		while(t - h > 1)
		{
			int mid = (h + t) / 2;
			if(num[mid] <= a)	h = mid;
			else	t = mid;
		}
		cout << h + 1 << endl;
	}
	return 0;
}