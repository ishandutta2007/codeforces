/*
Don't touch that dial!

Television screams, your face turning green,
Don't listen to the news,
Don't know what you hear, they never make it clear,
They like to keep your state confused,
Propaganda time, the official line,
You're hungry, you get fed,
Everlasting smile, you must convey their style,
But they're just a Talking Head

Television voice don't give you any choice,
You only hear the man,
Don't take them in, you don't know where they been,
'Cos it's a complex plan,
They keep you nice and quiet, even control your diet,
You're hungry you get fed,
Teach you to be meek, 'til all you are is weak,
'Til you're just a Talking Head

Television screams, this ought to be a dream,
Remember what I say,
Don't be hypnotised by sugar coated lies,
Don't switch it on today,
It's the way things are, from that pickle jar,
You're hungry you get fed,
But if you play the game, you become the same,
Another Talking Head
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n,ar[N],can[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=0;i<n;i++){
		cin>>ar[i];
		ar[i+n]=ar[i];
	}

	for (int i=0;i<n;i++){
		int cur=0;
		for (int j=i;j<n*2;j++){
			cur+=ar[j];
			can[cur]=1;
		}
	}

	for (int i=0;;i++){
		if (can[180-i]||can[180+i]){
			cout<<2*i<<endl;
			return 0;
		}
	}

//	cin.get(); cin.get();
	return 0;
}