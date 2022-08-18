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
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;

string st;
bool only_a(string st)
{
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] != 'a')
			return false;
	}
	return true;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> st;

	if (only_a(st))
	{
		st[st.size() - 1] = 'z';
		cout << st << endl;
		return 0;
	}

	int ptr = 0;
	while (st[ptr] == 'a')
		++ptr;
	for (int i = ptr; i < st.size(); i++)
	{
		if (st[i] == 'a')
			break;
		st[i]--;
	}
	cout << st << endl;

	cin.get(); cin.get();
	return 0;
}