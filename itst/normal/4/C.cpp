#include<bits/stdc++.h>
using namespace std;
string name[100001];
int vis[100001];
int main()
{
	std::ios::sync_with_stdio(false);
	int n , dirN = 0;
	for(cin >> n ; n ; n--)
	{
		string s;
		cin >> s;
		int f = 1;
		for(int i = 0 ; f && i < dirN ; i++)
			if(name[i] == s)
			{
				cout << name[i] << vis[i]++ << endl;
				f = 0;
			}
		if(f)
		{
			cout << "OK" << endl;
			name[dirN] = s;
			vis[dirN++] = 1;
		}
	}
	return 0;
}