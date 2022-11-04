#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void find_max(int l, int r, int pos)
{
	//cout << l << ' ' << r << endl;
	if(l == r)
	{
		cout << "! " << l + 1 << endl;
		return;
	}
	if(l == r - 1 && (pos == l || pos == r))
	{
		int ans = l;
		if(pos == l)
		{
			ans = r;
		}
		cout << "! " << ans + 1 << endl;
		return;
	}
	int mid = (l + r) / 2;
	if(r - l == 2 && pos > mid)
	{
		--mid;
	}
	if(pos <= mid)
	{
		cout << "? " << min(pos, l) + 1 << ' ' << mid + 1 << endl;
		int res;
		cin >> res;
		--res;
		if(res == pos)
		{
			find_max(l, mid, pos);
		}
		else
		{
			find_max(mid + 1, r, pos);
		}
	}
	else
	{
		cout << "? " << mid + 2 << ' ' << max(r, pos) + 1 << endl;
		int res;
		cin >> res;
		--res;
		if(res == pos)
		{
			find_max(mid + 1, r, pos);
		}
		else
		{
			find_max(l, mid, pos);
		}	
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    if(n == 1)
    {
    	cout << "! 1" << endl;
    	return 0;
    }
    cout << "? 1 " << n << endl;
    int pos;
    cin >> pos;
    --pos;
    find_max(0, n - 1, pos);
}