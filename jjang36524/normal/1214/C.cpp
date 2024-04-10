#include <iostream>
#include <algorithm>
using namespace std;
int N;
int brcount;
int wrongs;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		char a;
		cin >> a;
		if (a == '(')
			brcount++;
		else
			brcount--;
		if (brcount < -1)
			wrongs++;
	}
	if (wrongs || brcount)
		cout << "No";
	else
		cout << "Yes";
}