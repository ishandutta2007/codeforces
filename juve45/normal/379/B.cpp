#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	

	cin >> n;
	cin >> k;
	if(k!=0)
	cout << 'P';
	for(int i=1;i<k;i++)
		cout << "RLP";

	for(int i=1;i<n;i++)
	{
		cout << 'R';
		cin >> k;
		if(k!=0) 
		cout << 'P';
		for(int i=1;i<k;i++)
			cout << "LRP";

	}
	return 0;
}