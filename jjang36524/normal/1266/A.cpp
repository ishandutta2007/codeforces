#include <iostream>
#include <string>
using namespace std;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		int i;
		int z = 0, e = 0, sx = 0;
		for (i = 0; i < s.length(); i++)
		{
		
			if (s[i] == '0')
				z++;
			if (s[i] % 2 == 0)
				e++;
			sx += s[i] - '0';
		}
		if ((sx % 3 || z == 0 || e <= 1)&&z<s.length())
			cout << "cyan" << '\n';
		else
			cout << "red" << '\n';
	}
}