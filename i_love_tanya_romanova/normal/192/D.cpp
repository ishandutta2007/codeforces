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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 210000;

using namespace std;

int n, k;
long long money;
int ar[N];
vector<pair<int, int> >v;
long long pref;
int ans;
long long topay;
int at[N];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	cin >> money;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		if (i<n)
			v.push_back(make_pair(ar[i], i));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		at[v[i].second] = i;
	}

	for (int i = 0; i < k; i++)
		pref += v[i].first;

//	cout << pref << endl;

	ans = n;

	for (int i = 1; i < n; i++)
	{
		if (at[i] <= k - 1)
			topay = pref - ar[i];
		else
			topay = pref - v[k - 1].first;
		if (topay + ar[i]>money)
			ans = min(ans, i);
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}