#include<bits/stdc++.h>
using namespace std;
int pot[100001] , cou;
bool cmp(int a , int b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(false);
	int n , m;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;
		if(!pot[a])	cou++;
		pot[a] = i + 1;
	}
	sort(pot + 1 , pot + 100001 , cmp);
	sort(pot + 1 , pot + cou + 1);
	while(m)
	{
		int b , h = 0 , t = cou + 1;
		cin >> b;
		while(t - h > 1)
		{
			int mid = (h + t) / 2;
			if(pot[mid] < b)	h = mid;
			else	t = mid;
		}
		cout << cou - h << endl;
		m--;
	}
	return 0;
}