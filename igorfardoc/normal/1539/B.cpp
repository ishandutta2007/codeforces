#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    pref[0] = 0;
    for(int i = 1; i <= n; i++)
    {
    	pref[i] = pref[i - 1] + (s[i - 1] - 'a' + 1);
    }
    for(int i = 0; i < q; i++)
    {
    	int l, r;
    	cin >> l >> r;
    	--l;
    	--r;
    	cout << pref[r + 1] - pref[l] << '\n';
    }
}