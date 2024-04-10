/*
They are the ghosts of innocence
That have awoken from my dreams
Welcome to your nightmare
Say good-bye to everything
All your past obscenities
They have determined where I stand
Echoing cries, in the time that it began

Hear me now
Feel my plea
There is no more time for apologies
Never let emotions
Take hold of me
Are you ready to begin your trip to the other side
Death is an old friend of mine

You can't escape your judgment
I hear them calling out your name
Do not beg for mercy now
You never showed any to them
Embrace your final punishment
There's not a soul to hear you scream
I have to thankyou for letting out the animal in me

Hear me now
Feel my plea
There is no more time for apologies
Never let emotions
Take hold of me
Are you ready to begin your trip to the other side
Death is an old friend of mine

The blood became alive
When I was trapped inside
And I can feel the dark passenger coming
My mother's blood and mine
Uniquely intertwined
Help me father pull your memory from my mind
My hunger to destroy
When I was just a boy
It pulled me deeper into something that I now enjoy
The ritual begins
Evil will meet it's end
In your destruction I will finally feel whole again

There is no more time for apologies
Never let emotions
Take hold of me
Are you ready to begin your trip to the other side
Death is an old friend of mine

I have become your nightmare
Say good-bye to every thing
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 200000;

using namespace std;

int n;
vector<int> res;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;

	for (int i = 0; i <= 30; i++)
	{
		if (n&(1 << i))
			res.push_back(i);
	}

	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
	{
		if (i)
			cout << " ";
		cout << res[i]+1;
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}