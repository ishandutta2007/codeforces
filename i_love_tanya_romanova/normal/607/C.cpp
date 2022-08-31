/*
Oo it must be magic
How inside your eyes
I see my destiny
Every time we kiss
I feel you breathe your love so deep inside of me
If the moon and stars should fall
They'd be easy to replace
I would lift you up to heaven
And you would take their place

Then I saw red
When I opened up the door
I saw red
My heart just spilled onto the floor
And I didn't need to see his face
I saw yours
I saw red when I closed the door

I don't think I'm gonna love you anymore

Everyday I wake up
I thank God that you are still a part of me
We've opened up the door to which
So many people never find the key
And if the sun should ever fail to send its light
We would burn a thousand candles
And make everything alright

Then I saw red
When I opened up the door
I saw red
My heart just spilled onto the floor
And I didn't need to see his face
I saw yours
I saw red when I closed the door
I don't think I'm gonna love you anymore

I've been hurt
And I've been blind
I'm not sure that I'll be fine
I never thought it would end this way
Oo it must be magic
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
//#define bs 1234567891
#define bsize 512

const int N = 1100000;

using namespace std;

int bs;
int matched[10000];
int n;
string st1, st2;
long long pw[N];

bool prime(int x)
{
	for (int i = 2; i*i <= x;i++)
	if (x%i == 0)
		return false;
	return true;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	bs = 1e9 + rand() % 1000;
	while (!prime(bs))
		++bs;

	matched['N'] = 'S';
	matched['S'] = 'N';
	matched['E'] = 'W';
	matched['W'] = 'E';

	cin >> n;
	cin >> st1 >> st2;
	for (int i = 0; i < st2.size(); i++)
		st2[i] = matched[st2[i]];

	pw[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		pw[i] = pw[i - 1] * 173 % bs;

	long long s1, s2;
	s1 = s2 = 0;

	int len = 0;

	for (int i = st2.size() - 1; i >= 0; --i)
	{
		s1 = s1 + st1[i] * pw[len];
		s1 %= bs;
		s2 = s2 * 173 + st2[i];
		s2 %= bs;
		len++;
		if (s1 == s2)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	cin.get(); cin.get();
	return 0;
}