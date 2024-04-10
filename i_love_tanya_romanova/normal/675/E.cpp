/*
Deaf, dumb and blind boy
He's in a quiet vibration land
Strange as it seems
His musical dreams
Ain't quite so bad

Ten years old
With thoughts as bold
As thought can be
Loving life and becoming wise
In simplicity

Sickness can surely take the mind
Where minds can't usually go
Come on the amazing journey
And learn all you should know

A vague haze of delirium
Creeps up on me
All at once a tall stranger
I suddenly see
He's dressed in a silver-sparked
Glittering gown
And his golden beard flows
Nearly down to the ground

Nothing to say, and nothing to hear
And nothing to see
Each sensation makes a note
In my symphony

Sickness can surely take the mind
Where minds can't usually go
Come on the amazing journey
And learn all you should know

His eyes are the eyes
That transmit all they know
Sparkle warm crystalline glances to show
That he is your leader
And he is your guide
On the amazing journey together you'll ride
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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n;
int ar[N];
pair<int,int> t[N*4];
long long dp[N];

pair<int, int> better(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first != p2.first)
		return p1.first > p2.first?p1:p2;
	return p1.second > p2.second ? p1 : p2;
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = make_pair(ar[tl],tl);
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = better(t[v * 2], t[v * 2 + 1]);
}

pair<int,int> get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return make_pair(-1, -1);
	if (tl == l&&tr == r)
		return t[v];
	int tm = tl + tr;
	tm /= 2;
	return better(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> ar[i];
	}
	ar[n] = n;

	build(1, 1, n);

	dp[n] = 0;
	for (int i = n - 1; i >= 1; --i)
	{
		int l = i + 1;
		int r = ar[i];
		pair<int,int> best_move = get(1, 1, n, l, r);
		//cout <<"!"<< best_move.first<<" "<<best_move.second << endl;
		dp[i] = dp[best_move.second];
		dp[i] += n - i;// +1 move
		dp[i] -= ar[i] - best_move.second;// 1 anyway
		//cout << i << " " << dp[i] << endl;
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += dp[i];
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}