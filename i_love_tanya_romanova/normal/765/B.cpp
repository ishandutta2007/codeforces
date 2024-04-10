/*
Come and dance through my vanity's halls
Welcome to my exhibition

Ornaments fall
The fate of my art, condemned
And the creative seed
That grows to the tune of the harvest song
Embody my lifelong passion
Intertwine with the structures of my art
Those empty frames staring at me

One lonely portrait covers the lovestarved canvas
In honour of the birthless rebellion within me

Every picture holds a tale
Every shade tells of a thousand words

The artistry of living chaos
Is pictured in the poets tears
Because everything burns
The final concept
Is all but a thought away

Be gone, you foul enchantress of decay!
My thoughts and words will come to right
In my chamber where chaos conveys
Kneel down to my desire

Deep in the vaults of my carnal agony
Emptiness! Orchestration through colours

The gallery

To never return to my guidance
Burning my art
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
#define right asdashgasrhsdf

#define eps 1e-14
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

string st;
int cnt[N];
int fe[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	for (int i=0;i<N;i++)
		fe[i]=1e9;

	cin>>st;
	for (int i=0;i<st.size();i++)
	{
		cnt[st[i]]++;
		fe[st[i]]=min(fe[st[i]],i);
	}

	int ok=1;
	for (int i='b';i<='z';i++)
	{
		if (cnt[i]>0&&cnt[i-1]==0)
			ok=0;
		if (cnt[i]>0&&cnt[i-1]>0&&fe[i]<fe[i-1])
			ok=0;
	}
	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}