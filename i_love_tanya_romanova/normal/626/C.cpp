/*
Starving out the many while I only feed the few
Maintain the wealth that keeps me in control of you
Clean on the surface so you won't see my deceit
Even though I'm slithering just beneath your feet
Extend my reign into foreign lands
Flexing my muscle anywhere I can
I keep the power and swallow you whole
Cutting off your life support, I follow through

From way up here my vision's distorted
Cannot maintain what I once supported
I keep you safe, secure and protected
Until my self-indulgence has been perfected

I am the state
I decide your fate
Deliver to all
I bring the downfall

Making up your mind is everything I do
Doing the right thing is never up to you
Get you on board only to betray your trust
I will cut you off when I say you've had enough
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

const int N = 250;

using namespace std;

int a, b, ans;
int cnt1, cnt2, cnt3;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> a >> b;

	for (int i = 1;; i++)
	{
		if (i % 2==0)
			cnt1++;
		if (i % 3 == 0)
			cnt2++;
		if (i % 2 == 0 || i % 3 == 0)
			cnt3++;
		if (cnt1 >= a&&cnt2 >= b&&cnt3 >= a + b)
		{
			ans = i;
			break;
		}
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}