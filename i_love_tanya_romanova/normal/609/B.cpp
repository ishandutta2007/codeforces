/*
In thrall to the evil lord
A procession of the damned
Sweating blood to serve the beast
Desolation of their souls

They slave in fire
Whips of Hades at their backs
The Scourge of Iron
Hell's eternal pact

Lash them
Rip their skin
Scourge of Iron
Rending flesh

On earth they lived by force
Now the villains march in chains
Men of violence doomed in death
Their reward for a life of sin

They slave for eons
There will be no relief
Mere pawns of evil
Used and then enslaved

Lash them
Rip their skin
Scourge of Iron
Rending flesh

Lash
Rip their skin
Scourge of Iron
Rending flesh

Demonic sadists
Flay the damned with steel
The whip strips flesh

Torments beyond the material world
Skinless, bleeding
Robbed of pride and power

In the grip of the infernal
And the evil will not die
Iron whip will be relentless
And the pain will never end

Lash them
Rip their skin
Scourge of iron
Rending flesh

Lash
Rip their skin
Scourge of Iron
Rending flesh
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

const int N = 1100;

using namespace std;

long long ans;
int n, m;
long long cnt[N];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		cnt[val]++;
	}

	ans = 1ll * n*(n - 1) / 2;

	for (int i = 1; i <= m; i++)
	{
		long long val = cnt[i];
		ans -= val*(val - 1) / 2;
	}
	cout << ans << endl;

	cin.get();
	return 0;
}