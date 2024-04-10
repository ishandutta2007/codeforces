#include<iostream>
using namespace std;

const int maxn = 100;
int n;
int a[maxn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		for (int j = 0; j < n; j++)
			if (i != j && a[i] % 2 == a[j] % 2)
			{
				flag = false;
			}
		if (flag) cout << i + 1 << endl;
	}
}