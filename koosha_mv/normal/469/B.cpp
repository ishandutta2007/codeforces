#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
	int p,q,l,r; cin >> p >> q >> l >> r;
	int pl[p], pr[p], ql[q], qr[q];
	for(int i = 0; i < p; i++)
	{
		cin >> pl[i] >> pr[i];
	}
	for(int i = 0; i < q; i++)
	{
		cin >> ql[i] >> qr[i];
	}
	bool time[3001]; fill(time, time+3001, false);
	for(int i = 0; i < p; i++)
	{
		for(int j = pl[i]; j <= pr[i]; j++) time[j] = true;
	}
	int ret = 0;
	for(int i = l; i <= r; i++)
	{
		bool f = false;
		for(int j = 0; j < q; j++)
		{
			for(int k = ql[j]+i; k <= qr[j]+i; k++)
			{
				if(time[k]) f = true;
			}
		}
		if(f) ret++;
	}
 
 
	cout << ret << endl;
	return 0;
}