/*
You aren't what I love
You aren't what I need
You aren't what I love
You aren't what I need
What I need

No, don't let them take me down there
Don't let them take me down there
Don't let them take me down there
Don't let them take me down there

You aren't what I love
You aren't what I see
You hate from above
You become what I need
What I need

No, don't let them take me down there
Don't let them take me down there
Don't let them take me down there
Don't let them take me down
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

#define eps 1e-8
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 100050;

using namespace std;

int n, m;
int reach[N];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		for (; val; --val)
		{
			int q;
			cin >> q;
			reach[q] = 1;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		if (reach[i] == 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	cin.get(); cin.get();
	return 0;
}