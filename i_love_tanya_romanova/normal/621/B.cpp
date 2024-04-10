/*
I lay my eyes in the past
From the first day to the last
Several things we had to learn
Countless mistakes from times of yore

Now we restart, we recreate
Your present is your fate

Don't turn your backs on mankind!
Only yourselves you wanna save
Ignorance burns just like a fire
Consuming people on its flame

Fellow creatures, so wonderful!
So different and so grand

Sprouts of time
The roots evolving
The seeds for the future were scattered yesterday
Tomorrow's harvest field we plant today
Your crown will ever last
The tall trees of life

(Life experience)
Break your shell reach the light!
(Mind and sould)
Find your path to the skies
(Will come around on a thunder sound)
Raging with power and fury the new born world

Sprouts of time
The roots evolving
The seeds from the past branching out
Growing forever

Hands on heart
Embrace each other
The dances, the faces, the smiles behind the past

New seasons bring the chance to start again
Tall trees will ever last

The circles of life
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

const int N = 200000;

using namespace std;

int n;
int a, b;
long long cnt1[N], cnt2[N];
long long ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		cnt1[a + b]++;
		cnt2[a - b + 1000]++;
	}

	for (int i = 0; i <= 5000; i++)
	{
		ans += 1ll * cnt1[i] * (cnt1[i] - 1) / 2;
		ans += 1ll * cnt2[i] * (cnt2[i] - 1) / 2;
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}