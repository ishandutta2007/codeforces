/*
Catholic's dictator
Swine without compasion
No respect for others life
Godsent corrupt saint

Rampant, organized crime of the cross
Rituals justified ways to express
The oldest lie in support of the

Heartless motherfucker
Sympathy there's none
You immoralize prevention
Abortion is not a sin
Heaven none of you'll ever be saved
Awareness drown in devotion
Follow the rules
Dig your own grave

Murder under the cross
Profit ways don't leave no
Room for the scum
Open your eyes the messiah
Will never come (your fuckin' messiah)
You're killing the poor

There is no justice
There is no law
There's no messiah
There is no saviour, there is no god

The truth you teach it ain't
No truth to me
the things you see are not
The thing that I see
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

const int N = 510000;

using namespace std;

int n;
int ar[N];
set<int> mset;
long long ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	int mn = 1e9;

	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		mn = min(mn, ar[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (ar[i] == mn)
		{
			mset.insert(i);
			mset.insert(i + n);
		}
	}

	ans = 0;

	for (int i = 1; i <= n; i++)
	{
		set<int>::iterator it = mset.lower_bound(i);
		int ohead = (*it) - i;
		ans = max(ans, 1ll * mn*n + ohead);
	}

	cout << ans << endl;

	cin.get(); cin.get();

	return 0;
}