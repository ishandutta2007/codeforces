#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N, M, T;
int ca[100100];
int v[100100];
int arr[100100];
int rev[100100];
int findp(int n)
{
	if (v[n] == n)
		return n;
	return v[n] = findp(v[n]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		multiset<int>x;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			ca[i] = 1;
			v[i] = i;
			rev[arr[i]] = i;
			x.insert(1);
		}
		v[N] = N;
		int s = 1;
		
		for (i = 1; i <= N; i++)
		{
			auto bl = x.end();
			bl--;
			if (ca[rev[i]] != ((*bl)))
				s = 0;
			v[rev[i]] = v[findp(rev[i]+1)];
			x.erase(x.lower_bound(ca[rev[i]]));
			if (v[rev[i]] < N)
			{
				x.erase(x.lower_bound(ca[v[rev[i]]]));
			}
			ca[v[rev[i]]] += ca[rev[i]];
			if (v[rev[i]] < N)
			{
				x.insert(ca[v[rev[i]]]);
			}
			ca[rev[i]] = 0;
			
			
				
			
		}
		cout << (s ? "YES" : "NO") << '\n';
	}
}