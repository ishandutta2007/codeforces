/*
Oh hear Mary Jane Kelly
So sad and singing sadly
A violet plucked from mother's grave

Ex-soldier Thomas Bowyer found you in the gutter
The sound of you will be no more

Whatever you had said or ever done
Won't justify the pain that you went through
We all have different destinies in life
Your light was taken by the killing knife

She's been lonely and forgotten ever since
But her beauty in the night light will remain
She's been lonely and forgotten ever since
But her beauty in the night light will remain
Yeah will remain, dear Mary Jane

Please, Mary, wake up, let your spirit rise
Who was the gentleman you had that night
His letter from hell didn't say a thing
Still looking in the dark, but nothing's there

She's been lonely and forgotten ever since
But her beauty in the night light will remain
She's been lonely and forgotten ever since
But her beauty in the night light will remain
Yeah will remain, dear Mary Jane

The nemesis is neglect Running on the wolves' path
Try to get the bloody facts
Where do all the angels wait?
Let it be, yeah maybe just let it be

A violet plucked from mother's grave
Do the singing do the dance
Show me where's the evidence
Where do all the victims lay?
Or let it be, yeah maybe just let it be

She's been lonely and forgotten ever since
But her beauty in the night light will remain
She's been lonely and forgotten ever since
But her beauty in the night light will remain
Yeah will remain, dear Mary Jane
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
#define bs 1000000009
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200331;

int n, m;

int get_len(int x)
{
	long long can_show = 7;
	int res = 1;
	while (can_show < x)
	{
		res++;
		can_show *= 7;
	}
	return res;
}

int len_a, len_b;

int order[1000];
int ans;
int used[1000];

void backtrack(int ps)
{
	if (ps == len_a + len_b)
	{
		long long res1 = 0;
		long long res2 = 0;
		for (int i = 0; i < len_a; i++)
		{
			res1 = res1 * 7 + order[i];
		}
		for (int i = len_a; i < len_a + len_b; i++)
		{
			res2 = res2 * 7 + order[i];
		}
		if (res1 < n&&res2 < m)
		{
			/*cout << res1 << " " << res2 << endl;
			for (int i = 0; i < 7; i++)
			{
				cout << used[i] << " ";
			}
			cout << ps << endl;
			cout << endl;
			*/
			++ans;
		}
		return;
	}

	for (int i = 0; i < 7; i++)
	{
		if (used[i])
			continue;
		used[i] = 1;
		order[ps] = i;
		backtrack(ps+1);
		used[i] = 0;
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;

	len_a = get_len(n);
	len_b = get_len(m);
	//cout << len_a << "%" << len_b << endl;
	backtrack(0);

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}