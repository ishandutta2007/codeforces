#include<bits/stdc++.h>
using namespace std;
int ans[51];
int main()
{
	ios::sync_with_stdio(false);
	int n , numN = 0 , cou = 0;
	string s;
	cin >> n >> s;
	for(int i = 0 ; i < n ; i++)
		if(s[i] == 'B')	numN++;
		else
		{
			if(numN)	ans[cou++] = numN;
			numN = 0;
		}
	if(numN)	ans[cou++] = numN;
	cout << cou << endl;
	for(int i = 0 ; i < cou ; i++)	cout << ans[i] << " ";
	return 0;
}