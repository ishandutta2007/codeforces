/*
I'm a man and that's who I am
and I'll tell you that to your face
I'm from the clouds and I shine like the moon
and I'm here to fuck up the place

Make it last, make it count
make it one more round and I'll see you outside
heaven knows life can turn on a dime
so let's enjoy our time

They have got me hanging upside down again
once more 'round the sun we go again

What's the meaning of this life
that we leave when we're caught up on the race
my heart is spinning like a merry-go-round
and I want you to take a ride

I know it's nice and I know that you are weary
but it's nice once you step inside
roll me over and turn me around
and let's make up on time

They have got me hanging upside down again
I just want to melt into the sun
once more 'round the sun we go again

They have got me hanging upside down again
I just want to melt into the sun again
they have got me hanging upside down again
once more 'round the sun we go again
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200040;

string st;
vector<int> res;

int eval(char c)
{
	if (c >= '0'&&c <= '9')
		return c - '0' + 0;
	if (c >= 'A'&&c <= 'Z')
		return c - 'A' + 10;
	if (c >= 'a'&&c <= 'z')
		return c - 'a' + 36;
	if (c == '-')
		return 62;
	return 63;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> st;
	for (int i = 0; i < st.size(); i++)
	{
		int val = eval(st[i]);
		for (int i = 0; i < 6; i++)
		{
			res.push_back(val % 2);
			val /= 2;
		}
	}
	
	long long ans = 1;
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] == 0)
			ans = ans * 3 % bs;
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}