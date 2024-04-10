#include <bits/stdc++.h>
using namespace std;

string arr[50005];
int n;

bool cmp(const string& a, const string& b)
{
	return a+b < b+a;
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++) cin >> arr[i];
	sort(arr, arr+n, cmp);
	for (int i = 0;i < n;i++) cout << arr[i]; cout << endl;
	return 0;
}