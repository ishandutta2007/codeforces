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
#define bs 1000000007
#define bsize 512

const int N = 210000;

using namespace std;

int n, k;
vector<pair<int, int> > events;
vector<pair<int, int> > ans;
int cnt;
int op;
int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
//		cin >> a >> b;
		scanf("%d", &a);
		scanf("%d", &b);
		events.push_back(make_pair(a, -1));
		events.push_back(make_pair(b, 1));
	}
	sort(events.begin(), events.end());

	for (int i = 0; i < events.size(); i++)
	{
		if (cnt == k - 1 && events[i].second == -1)//open
		{
			op = events[i].first;
		}
		if (cnt == k&&events[i].second == 1)//close
		{
			ans.push_back(make_pair(op, events[i].first));
		}
		cnt -= events[i].second;
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
//		cout << ans[i].first << " " << ans[i].second << "\n";
	}

	cin.get(); cin.get();
	return 0;
}