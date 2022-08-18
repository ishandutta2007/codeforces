/*
See the white light
The light within
Be your own disciple
Fan the sparks of will
For all of us waiting
Our kingdom will come
Rays of power shining
Rays of magic fall
On the golden voice that speaks within us all
For all of us waiting
Your kingdom will come
Kingdom Come

Feel the white light
The light within
Yea it burns a fire that drives a man to win
For all of us waiting
Your kingdom will come

Kingdom Come

Words of power
Calling to us all
Holding us together while other kingdoms fall
No longer waiting
Our kingdom has come

Kingdom Come

Kingdom coming
Another kingdom falls
The rightful are waiting
But all are not rightful
Wait and receive the weight of the fall

Kingdom Come
*/

#pragma GCC optimize("O3")
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
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 500031;

string st;
set<string> ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>st;
	for (int iter=1;iter<=1000;iter++)
	{
		char c=st[0];
		st.erase(st.begin());
		st+=c;
		ans.insert(st);
	}
	cout<<ans.size()<<endl;

	cin.get(); cin.get();
	return 0;
}