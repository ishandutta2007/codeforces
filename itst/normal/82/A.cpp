#include<bits/stdc++.h>
using namespace std;
string s[5] = {"Sheldon" , "Leonard" , "Penny" , "Rajesh" , "Howard"};
int main()
{
	std::ios::sync_with_stdio(false);
	int i = 1 , j , n , sum = 0;
	cin >> n;
	while(sum + 5 * i < n)
	{
		sum += 5 * i;
		i *= 2;
	}
	cout << s[(n - sum - 1) / i];
	return 0;
}