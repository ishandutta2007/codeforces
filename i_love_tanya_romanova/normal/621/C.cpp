/*
Forgive me father
Forgive me God
I know I've sinned
With no remorse
Apocalyptic visions
Went through my head Here today

Gone tomorrow
It's all insane
I'm feeling sick
I'm feeling numb
The storm will come
In the name of God I'm the chosen one

Terror raids the land
To ashes we'll be sent
In the name of God Lives cast away

Martyrdom of myself
Armageddon comes
In the name of God Not one more dead

Fire blasting, cutting edge
Children burn in flames
In the name of God We're going insane

Let us die
You don't realize
This is the time
God's sacrifice

Leaving behind
Lesson in hate
In the name of God We're all dead
Burn!
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 201000;

using namespace std;

int n;
int p;
int l[N], r[N];
double ans;

int cgood(int x)
{
	return x / p;
}

double eval(int id)
{
	double good = cgood(r[id]) - cgood(l[id] - 1);
	return good / (r[id] - l[id] + 1);
}
int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i];
	}

	for (int i = 0; i < n; i++)
	{
		double prob1 = eval(i);
		double prob2 = eval((i + 1) % n);
		ans += 2000 * (prob1 + prob2 - prob1*prob2);
	}
	cout.precision(10);
	cout << fixed << ans << endl;

	cin.get(); cin.get();
	return 0;
}