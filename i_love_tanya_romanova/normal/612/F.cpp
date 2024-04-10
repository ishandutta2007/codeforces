/*
Bearing the mark of a demon from hell the dragon is cast onto the earth
Seeking revenge on the woman of man Satanus unleashes his wrath
Angels of death are the allies of hate the jackals destroying the cross

[Chorus:]
Fighting with fire the dragon attacks
Burning the cross and unleashing the powers of hell
Cursed are the mortals who dare to fight with the beast

Demons of hell bear the mark of the beast the sons of the dragon are born
Summoned to earth armageddon is here to slaughter the christian hordes
Destroying the temples Jehova has lost the nazarene will fester in hell

[Chorus]

A wrathful attack upon the christian faith the legions of Satan make war
Replacing the cross with the mark of the beast the kingdoms of Jesu have fell
Demons of hell armageddon is here preventing the coming of christ
relinquish your god now that satan is king the nazarene will never arise

Bearing the mark of a demon from hell the dragon is cast onto earth
Seeking revenge on the woman of man Satanus unleashes his wrath
Angels of death are the allies of hate the jackals destroying the cross

[Chorus]
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
#define prev asdfasdgasdg

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 2200;

using namespace std;

int n, s;
int ar[N];
vector<int> v;
int need_val, need_cnt;
vector<pair<int, int> > avec;
vector<int> entries[N];
int prev[N], nxt[N];
map<int, int> mapp;
int dp[N][2];
pair<int, int> par[N][2];
int cnt;

void remap()
{
	sort(v.begin(), v.end());
	cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (i>0 && v[i] == v[i - 1])
			continue;
		mapp[v[i]] = cnt;
		++cnt;
	}
}

int get_dist(int a, int b)
{
	a = abs(a - b);
	if (a > n - a)
		a = n - a;
	return a;
}

vector<pair<int, int> > qmoves,vec1,vec2;

int eval(int a, int b, int dir)
{
	int have = 0;
	int moves = 0;
	qmoves.clear();
	int moves2 = 0;

	while (true)
	{
		if (ar[a] == need_val||a==b)
		{
			if (ar[a]==need_val)
				++have;
			qmoves.push_back(make_pair(moves2, dir));
			moves2 = 0;
		}
		if (a == b)
			break;
		++moves;
		++moves2;
		a += dir;
		if (a < 0)
			a += n;
		if (a >= n)
			a -= n;
	}
	if (have < need_cnt)
		return 1e9;
	return moves;
}

void show(vector<pair<int, int> > v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << endl;
	cout << endl;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> s;

	--s;

	for (int i = 0; i <n; i++)
	{
		cin >> ar[i];
		v.push_back(ar[i]);
	}

	remap();

	for (int i = 0; i < n; i++)
	{
		ar[i] = mapp[ar[i]];
	}

	for (int i = 0; i < n; i++)
	{
		if (entries[ar[i]].size())
			prev[i] = entries[ar[i]].back(),
			nxt[entries[ar[i]].back()] = i,
			prev[entries[ar[i]][0]] = i,
			nxt[i] = entries[ar[i]][0];
		entries[ar[i]].push_back(i);
	}

	for (int i = 0; i < n; i++)
	{
		if (entries[ar[i]].size() == 1)
		{
			prev[i] = nxt[i] = i;
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << prev[i] << " " << nxt[i] << " " << ar[i] << " " << cnt << endl;
	}
	*/
	for (int i = 0; i < n; i++)
	{
		dp[i][0] = dp[i][1] = 1e9;
	}

	for (int i = 0; i < n; i++)
	{
		if (ar[i] == 0)
		{
			dp[i][0] = get_dist(s, i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < entries[i].size(); j++)// 0 moves
		{
			int ps = entries[i][j];
			int R = nxt[ps];
			int L = prev[ps];
			if (L == ps)
			{
				if (dp[ps][1]>dp[ps][0])
				{
					dp[ps][1] = dp[ps][0];
					par[ps][1] = make_pair(ps, 0);
				}
			}
			int dist_L;
			if (L < ps)
				dist_L = ps - L;
			else
				dist_L = ps + n - L;
			int dist_R;
			if (R>ps)
				dist_R = R - ps;
			else
				dist_R = R + n - ps;

			if (dp[L][1] > dp[ps][0] + (n - dist_L))
			{
				dp[L][1] = dp[ps][0] + (n - dist_L);
				par[L][1] = make_pair(ps, 0);
			}
			if (dp[R][1] > dp[ps][0] + (n - dist_R))
			{
				dp[R][1] = dp[ps][0] + (n - dist_R);
				par[R][1] = make_pair(ps, 0);
			}
		}
		
		for (int j = 0; j < entries[i].size(); j++)
		{
			int ps = entries[i][j];
			for (int q = 0; q < entries[i + 1].size(); q++)
			{
				int ps2 = entries[i + 1][q];
				int D = get_dist(ps2, ps);
				if (dp[ps2][0]>dp[ps][1] + D)
				{
					dp[ps2][0] = dp[ps][1] + D;
					par[ps2][0] = make_pair(ps, 1);
				}
			}
		}
	}

//	cout << dp[0][0] << endl;

	int qi, qj;

	int ans = 1e9;
	for (int i = 0; i < n; i++)
	{
		if (ar[i] == cnt - 1)
		{
			if (dp[i][1] < ans)
			{
				ans = dp[i][1];
				qi = i;
				qj = 1;
			}
		}
	}

	cout << ans << endl;

	//cout << ans << " "<<qi<<" "<<qj<<endl;

	while (ar[qi] != 0 || qj != 0)
	{
		pair<int, int> p2 = par[qi][qj];
		if (qj == 0 && p2.second == 1)
		{
			need_val = -1;
			need_cnt = 0;
		}
		else
		{
			need_val = ar[qi];
			need_cnt = entries[ar[qi]].size();
		}
		int cost1 = eval(p2.first, qi,1);
		vec1 = qmoves;
		int cost2 = eval(p2.first, qi, -1);
		vec2 = qmoves;

		reverse(vec1.begin(), vec1.end());
		reverse(vec2.begin(), vec2.end());
		/*
		show(vec1);
		show(vec2);
		cout << cost1 << "!" << cost2 << endl;
		*/
		if (cost1 < cost2)
		{
			for (int q = 0; q < vec1.size(); q++)
			{
				avec.push_back(vec1[q]);
			}
	//		avec.push_back(make_pair(cost1, 1));
		}
		else
		{
			for (int q = 0; q < vec2.size(); q++)
			{
				avec.push_back(vec2[q]);
			}
//			avec.push_back(make_pair(cost2, -1));
		}
		qi = p2.first;
		qj = p2.second;
	}
	
//	cout << qi << "%" << qj << " "<<dp[qi][qj]<<endl;

	// 1 move

	need_val = -1;
	need_cnt = 0;
	int cost1 = eval(s, qi, 1);
	vec1 = qmoves;
	int cost2 = eval(s, qi, -1);
	vec2 = qmoves;
	reverse(vec1.begin(), vec1.end());
	reverse(vec2.begin(), vec2.end());
	/*
	show(vec1);
	show(vec2);
	cout << "!" << cost1 << " " << cost2 << endl;
	*/
	if (cost1 < cost2)
	{

		for (int q = 0; q < vec1.size(); q++)
		{
			avec.push_back(vec1[q]);
		}
//		avec.push_back(make_pair(cost1, 1));
	}
	else
	{

		for (int q = 0; q < vec2.size(); q++)
		{
			avec.push_back(vec2[q]);
		}
//		avec.push_back(make_pair(cost2, -1));
	}
	reverse(avec.begin(), avec.end());

	for (int i = 0; i < avec.size(); i++)
	{
		if (i != 0 && avec[i].first == 0)
			continue;
		if (avec[i].second == 1)
			cout << "+";
		else
			cout << "-";
		cout << avec[i].first;
		cout << endl;
	}

	cin.get(); cin.get();
	return 0;
}