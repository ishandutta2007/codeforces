#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

string s;
int P = 0;
int A[100];

int f(int i, int X)
{
	if (i == s.size())
	{
		if (A[i-2] == 2 && A[i-1] == 5) return 1;
		if (A[i-2] == 5 && A[i-1] == 0) return 1;
		if (A[i-2] == 7 && A[i-1] == 5) return 1;
		if (A[i-2] == 0 && A[i-1] == 0) return 1;
		return 0;
	}
	int ret = 0;

	if (s[i] == '_')
	{
		if (i+2 < s.size())
		{
			A[P++] = 0;
			ret += f(i+1, X) * (10 - (i == 0)); // . leading zero  .
			P--;
		}
		else
		{
			for(int x=0; x<=9; x++)
			{
				if (i == 0 && x == 0) continue;

				A[P++] = x;
				ret += f(i+1, X);
				P--;
			}
		}
	}
	else if (s[i] == 'X')
	{
		if (X == -1)
		{
			for(int x=0; x<=9; x++)
			{
				if (i == 0 && x == 0) continue;

				A[P++] = x;
				ret += f(i+1, x);
				P--;
			}
		}
		else
		{
			A[P++] = X;
			ret += f(i+1, X);
			P--;
		}
	}
	else
	{
		if (i == 0 && s[i] == '0'); // leading zero
		else
		{
			A[P++] = s[i]-'0';
			ret += f(i+1, X);
			P--;
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> s;
	if (s.size() == 1 && s[0] == '0') cout << 1 << "\n"; //
	else if (s.size() == 1 && s[0] == '_') cout << 1 << "\n"; //
	else if (s.size() == 1 && s[0] == 'X') cout << 1 << "\n"; //
	else cout << f(0, -1) << "\n";
	return 0;
}