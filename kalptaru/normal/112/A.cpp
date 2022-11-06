#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int size = str1.size();
	for (int i = 0; i < size; ++i)
	{
		int code = str1[i];
		int code_2 = str2[i];


		if (code >= 97)
			{
			str1[i] = str1[i] - 32;
			}



		if (code_2 >= 97)
			{
			str2[i] = str2[i] - 32;
			}
	}

	if(str1 > str2)
		{
			cout << "1";
		}
	else if(str1 < str2)
		{
			cout << "-1";
		}
	else if(str1 == str2)
		{
			cout << "0";
		}
		
}