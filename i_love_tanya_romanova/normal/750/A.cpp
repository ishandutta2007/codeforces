/*
What I've got you've got to give it to your mama
What I've got you've got to give it to your pappa
What I've got you've got to give it to your daughter
You do a little dance and then you drink a little water

What I've got you've got to get it put it in you
What I've got you've got to get it put it in you
What I've got you've got to get it put it in you
Reeling with the feeling don't stop continue

Realize I don't want to be a miser
Confide with sly you'll be the wiser
Young blood is the lovin' upriser
How come everybody want to keep it like the kaiser

Give it away give it away give it away now
Give it away give it away give it away now
Give it away give it away give it away now

I can't tell if I'm a kingpin or a pauper
Greedy little people in a sea of distress
Keep your more to receive your less
Unimpressed by material excess
Love is free love me say hell yes

I'm a low brow but I rock a little know how
No time for the piggies or the hoosegow
Get smart get down with the pow wow
Never been a better time than right now

Bob Marley poet and a prophet
Bob Marley taught me how to off it
Bob Marley walkin' like he talk it
Goodness me can't you see I'm gonna cough it

Give it away give it away give it away now
Give it away give it away give it away now
Give it away give it away give it away now

Lucky me swimmin' in my ability
Dancin' down on life with agility
Come and drink it up from my fertility
Blessed with a bucket of lucky mobility

My mom I love her 'cause she love me
Long gone are the times when she scrub me
Feelin' good my brother gonna hug me
Drink my juice young love chug-a-lug me

There's a river born to be a giver
Keep you warm won't let you shiver
His heart is never gonna wither
Come on everybody time to deliver

Give it away give it away give it away now
Give it away give it away give it away now
Give it away give it away give it away now

What I've got you've got to give it to your mama
What I've got you've got to give it to your pappa
What I've got you've got to give it to your daughter
You do a little dance and then you drink a little water
*/

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
#define bs 1000000007
#define bsize 337

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n, k, ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int need = 0;
		for (int j = 1; j <= i; j++)
		{
			need += 5 * j;
		}
		if (need + k <= 240)
			ans = i;
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}