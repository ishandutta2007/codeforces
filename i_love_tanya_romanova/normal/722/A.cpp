/*
I've got a soul that can not sleep
At night when something just ain't right
Blood red, but without sight
Exploding egos in the night
Mix like sticks of dynamite
Red black or white, this is my fight
Come on courage, let's be heard
Turn feelings into words
American equality has always been sour
An attitude I would like to devour
My name is peace, this is my hour
Can I get just a little bit of power

The power of equality
Is not yet what it ought to be
It fills me up like a hollow tree
The power of equality

Right or wrong, my song is strong
You don't like it, get along
Say what I want, do what I can
Death to the message of the Ku Klux Klan
I don't buy supremacy
Media chief, you menance me
The people you say cause all the crime
Wake up motherfucker and smell the slime
Blackest anger, whitest fear
Can you hear me, am I clear
My name is peace, this is my hour
Can I get just a little bit of power

The power of equality
Is not yet what it ought to be
It fills me up like a hollow tree
The power of equality

I've got tapes
I've got c.d.'s
I've got my Public Enemy
My lilly white ass is tickled pink
When I listen to the music that makes me think
Not another motherfuckin' politician
Doin' nothin' but something for his own ambition
Never touch the sound we make
Soul sacred love, vows that we take
To create straight what is true
Yo he's with me and what I do
My name is peace, this my hour
Can I get just a little bit of power

The power of equality
Is not yet what it ought to be
It fills me up like a hollow tree
The power of equality

Madder than a motherfucker, lick my finger
Can't forget, cause the memory lingers
Count 'em off quick, little piccadilly sickness
Take me to the hick, eat my thickness
I've got a welt from the Bible belt
Dealing with the hand that I've been dealt
Sitting in the grip of a killing fist
Giving up blood just to exist
Rub me wrong and I get pissed
No I can not get to this
People in pain, I do not dig it
Change of brain for Mr. Bigot
Little brother do you hear me
Have a heart oh come get near me
Misery is not my friend
But I'll break before I bend
What I see is insanity
Whatever happened to humanity
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
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;

int tp;
string st;
vector<string> good;
int ans;
string ans_st;

int get_dist(string st1, string st2)
{
	int res = 0;
	for (int i = 0; i < st1.size(); i++)
	{
		if (st1[i] != st2[i])
			++res;
	}
	return res;
}

void generate_vals(int a, int b)
{
	string st;
	st += char(a / 10 + 48);
	a %= 10;
	st += char(a + 48);
	st += ":";
	st += char(b / 10 + 48);
	st += char(b % 10 + 48);
	good.push_back(st);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> tp;
	if (tp == 12)
	{
		for (int i = 1; i <= 12; i++)
		{
			for (int j = 0; j < 60; j++)
			{
				generate_vals(i, j);
			}
		}
	}
	else
	{
		for (int i = 0; i < 24; i++)
		{
			for (int j = 0; j < 60; j++)
			{
				generate_vals(i, j);
			}
		}
	}
	cin >> st;
	ans = 100;

//	cout << good[1] << endl;

	//cout << good.size() << endl;

	for (int i = 0; i < good.size(); i++)
	{
		if (get_dist(good[i], st) <= ans)
		{
			ans = get_dist(good[i], st);
			ans_st = good[i];
		}
	}

//	cout << ans << endl;
	cout << ans_st << endl;

	cin.get(); cin.get();
	return 0;
}