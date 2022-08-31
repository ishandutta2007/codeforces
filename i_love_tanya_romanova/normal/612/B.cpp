/*
Sent to the islands to secure what is ours
Marching ashore in the cover of night
Hide until dawn and attack in the twilight
Shake them awake with the thunder of guns

Orders from the iron maiden, get the islands back
Failure will not be accepted, call for artillery strike, launch attack

We are Back in control, force them to surrender
Take what is ours, restore law and order
Back in control, push them further out to sea
Falklands in our hands, back under British reign

Push them back further and out from the islands
Into our fleet that will stop their retreat
Mark their positions and call in the airforce
Harriers and Vulcans strikes at our command
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

long long ans;
int ps[N];
int n;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		ps[val] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		ans += abs(ps[i] - ps[i - 1]);
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}