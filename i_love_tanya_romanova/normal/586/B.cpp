/*
Striking at speed on the wings of revenge
Creating at madness at will
Deceiving dictating pretenders beware
Unleashing the blitzkrieg to kill
Burning desire with blood as the fuel
Dying you feed the machine
Rising from blindness the lights scan the sky
Defying the darkness I see

Raise the flag of shame
Coward is your name
I have your life held in my hand
Feel the power rise
Lightning cracks the sky
Cut loose the fury take command

Die, die, die
By our Blitzkrieg
Die, die, die
It's a lightning war
Die, die, die
By our Blitzkrieg
Die, die, die

Riding the past as we march on through time
Inflicting destruction and pain
Deposing destroying exceptions are none
Send bleeding the weak and insane
Leading them on through the oceans of light
Black is the hatred we found
Awaiting the sign for the hammer to fall
Sent crushing by power and sound

Raise the flag of shame
Coward is your name
I have your life held in my hand
Feel the power rise
Lightning cracks the sky
Cut loose the fury take command

Die, die, die
By our Blitzkrieg
Die, die, die
It's a lightning war
Die, die, die
By our Blitzkrieg
Die, die, die

Tighten the grip on the never say die
Precision the way to succeed
Ascending defending in action again
Emotion is what we perceive
Show no remorse in a crushing defeat
Sweet is a vengeful attack
Life is for living right down to the last
The glory immortal in black

Raise the flag of shame
Coward is your name
I have your life held in my hand
Feel the power rise
Lightning cracks the sky
Cut loose the fury take command

Die, die, die
By our Blitzkrieg
Die, die, die
It's a lightning war
Die, die, die
By our Blitzkrieg
Die, die, die
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
#define prev asdfasdgasdg

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 2200;

using namespace std;

int n, a[N], b[N], C[N];
vector<int> v;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		cin >> C[i];

	for (int c = 1; c <= n; c++)
	{
		int s = 0;
		for (int i = 1; i < c; i++)
			s += a[i];
		for (int j = c; j < n; j++)
			s += b[j];
		s += C[c];
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v[0] + v[1] << endl;

	cin.get(); cin.get();
	return 0;
}