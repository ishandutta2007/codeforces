#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) ans += "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;
string s;
int c[256];
char R='R', G='G', B='B', c1, c2;
int nrc;
string ans;

int solve()
{if(nrc == 3)
	{
		ans += "RBG";
		return 0;
	}
	if(nrc == 1)
	{
		if(c[B]>0) cout <<B;
		if(c[G]>0) cout <<G;
		if(c[R]>0) cout <<R;
		return 0;
	}
	if(c[R] == 0)
	{
		ans += R;
		c1 = B;
		c2 = G;
	}
	if(c[B] == 0)
	{
		ans += B;
		c1 = G;
		c2 = R;
	}
	if(c[G] == 0)
	{
		ans += G;
		c1 = R;
		c2 = B;
	}
	if(c[c1] > 1 && c[c2] > 1)
	{
		ans += c1;
		ans += c2;
		return 0;
	}
	if(c[c1] > c[c2])
		swap(c1, c2);

	if(c[c2] == 1)
		return 0;

	ans += c1;
	return 0;

}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> s;


	for(int i=0;i<s.size();i++)
	{
		c[s[i]]++;
		if(c[s[i]] == 1) nrc++;
	}

	solve();

	//cout << ans << '\n';
	sort(ans.begin(), ans.end());
	cout << ans;

	return 0;
}