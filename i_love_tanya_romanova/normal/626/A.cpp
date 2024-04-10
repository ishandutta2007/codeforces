/*
My heart's a hieroglyph, it talks in tongues
Ten thousand voices fill my broken lungs
But through the white wave, I still hear it call

So take a deep breath, let's disappear
No-one will miss us, so why are we still here?
And in the black hole you will see it all

Cause this is not enough
And I won't wait for them to cut me up
So give me all you've got
They'll never stop until they see us fall
So let's run
So let's run

Your head's a hurricane; it moves in waves
A perfect storm that keeps you wide awake
But through the silence, you will feel it burn

So take my hand and let's fade away
You know there's nothing here to make us stay
And in the darkness you will see the sun

Cause this is not enough
And I won't wait for them to cut me up
So give me all you've got
They'll never stop until they see us fall
So let's run away cause everything's broken
And we're so much more than another brick in the grey
So give me your every, give me your everything
And let's get away,
Cause everything's broken
I know that we're more than another brick in the grey
So give me your every, give me your everything

It's not enough
It's not enough

Cause this is not enough
And I won't wait for them to cut me up
So give me all you've got
They'll never stop until they see us fall
So let's run

Cause this is not enough
And I won't wait for them to cut me up
So give me all you've got
They'll never stop until they see us fall
So let's run
So let's run
So let's run
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

const int N = 105000;

using namespace std;

int n;
string st;
int ans;
int dx[N], dy[N];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	cin >> st;
	for (int i = 0; i < st.size(); i++)
	{
		dx[i + 1] = dx[i];
		dy[i + 1] = dy[i];
		if (st[i] == 'U')
			++dx[i + 1];
		if (st[i] == 'D')
			--dx[i + 1];
		if (st[i] == 'L')
			++dy[i + 1];
		if (st[i] == 'R')
			--dy[i + 1];
	}

	for (int i = 1; i <= st.size(); i++)
	{
		for (int j = i; j <= st.size(); j++)
		{
			if (dx[i - 1] == dx[j] && dy[i - 1] == dy[j])
				++ans;
		}
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}