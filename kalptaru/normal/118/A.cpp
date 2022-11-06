#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	string str1, str2;
	cin >> str1;
	int size = str1.size();
	for (int i = 0; i < size; ++i)
	{
		int code = str1[i];

		if (code < 97)
			{
			str1[i] = str1[i] + 32;
			}
	if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' || str1[i] == 'y')
		{

		}
		else
		{
			cout << ".";
			cout << str1[i];
		}
	}
return 0;
}