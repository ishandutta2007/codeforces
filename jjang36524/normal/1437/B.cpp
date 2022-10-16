#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int T;
int a, b, c, d;
string s;
int arr[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N >> s;
		int i;
		for (i = 0; i < s.size(); i++)
		{
			arr[i]=(s[i]-'0')==(i%2);
		}
		int ans = 0;
		int ans2 = 0;
		int bef = -1;
		for (i = 0; i < s.size(); i++)
		{
			if (bef !=1 && arr[i] == 1)
				ans++;
			if (bef != 0 && arr[i] == 0)
				ans2++;
			bef = arr[i];
		}
		cout << min(ans,ans2) << '\n';
	}
}