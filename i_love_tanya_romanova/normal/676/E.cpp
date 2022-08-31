/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 100000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n, k;
int done[N], val[N];
int moves_made;

long long P;

int parse(string st)
{
	int flag = 0;
	if (st[0] == '-')
	{
		flag = 1;
		st.erase(st.begin());
	}
	int res = 0;
	for (int i = 0; i < st.size(); i++)
	{
		res = res * 10 + st[i] - 48;
	}
	if (flag)res *= -1;
	//	cout << res << endl;
	return res;
}

bool prime(int P)
{
	for (int i = 2; i*i <= P; i++)
	{
		if (P%i == 0)
			return false;
	}
	return true;
}

bool check_div()
{
	for (int i = n; i > 0; --i)
	{
		long long TD = 1ll * val[i] * k%P;
		val[i - 1] += TD;
		val[i - 1] %= P;
		//cout << TD << endl;
		if (val[i - 1] < 0)
			val[i - 1] += P;
	}
	return (val[0] == 0);
}

bool solve()
{
	if (k == 0)//some shit
	{
		if (done[0] == 1)
		{
			return (val[0] == 0);
		}
		if (moves_made % 2 == 1)// our move
		{
			return 1;
		}
		return 0;
	}

	if (moves_made == n + 1)
	{
		return check_div();
	}
	if (n % 2 == 0)
	{
		return 0;
	}
	//if (moves_made < n)
	//	return 0;

	return 1;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	srand(13);
	P = 1001000000 + rand() % 5000;
	while (!prime(P))++P;

	cin >> n >> k;

	for (int i = 0; i <= n; i++)
	{
		string st;
		cin >> st;
		if (st == "?")
			continue;
		done[i] = 1;
		val[i] = parse(st);
		val[i] %= P;
		if (val[i] < 0)
			val[i] += P;
		++moves_made;
	}

	if (solve())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cin.get(); cin.get();
	return 0;
}