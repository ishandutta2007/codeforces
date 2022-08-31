/*
I received a message from my brother across the water
He sat laughin' as he wrote the end's in sight
So I said goodbye to all my friends
And packed my hopes inside a matchbox
'Cause I know it's time to fly

Come on, meet me in the morning, Meet me in the middle of the night
The morning light is comin', don't it make you wanna go and feel alright

I just jumped a train that never stops,
So now somehow I'll know I never finished payin' for my ride
Just n' someone pushed a gun into my hand
Tell me I'm the type of man to fight the fight that I'll require

Come on, meet me in the morning, Meet me in the middle of the night
The morning light is comin', don't it make you wanna go and feel alright

Oh, mama, well I think it's time I'm leavin'
Nothin' here to make me stay
Whoa, mama, well it must be time I'm goin'
They're knockin' down them doors
They're tryin' to take me away

Please Mr. Brakeman, won't you ring your bell. And ring loud and clear
Please Mr. Fireman, won't you ring your bell
Tell the people they got to fly away from here

I once saw a picture of a lady with a baby
Southern lady, had a very, very special smile
We are in the middle of a change in destination
When the train stops, all together we will smile
Oh, meet me in the morning.
Won't you meet me in the middle of the night, night, night
Everybody know the mornin' time is comin'
Don't it make you wanna feel alright. Ah, ah, yeah
Make me feel alright. Fly now, baby
Get to fly, yeah. Fly now, baby
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

const int N = 120000;

using namespace std;

vector<int> sg;
int n, m, k;
string st;
vector<int> oc[1000];
int flag1, flag2;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> st;
		oc['R'].clear();
		oc['G'].clear();
		oc['-'].clear();

		for (int j = 0; j < st.size(); j++)
		{
			oc[st[j]].push_back(j);
		}
		if (oc['-'].size() == 0)
			continue;
		if (oc['G'].size() == 2)
		{
			flag1 = 1;
			continue;
		}
		if (oc['R'].size() == 2)
		{
			flag2 = 1;
			continue;
		}
		if (oc['G'].size() == 0 && oc['R'].size() == 1)
		{
			flag2 = 1;
			continue;
		}
		if (oc['G'].size() == 1 && oc['R'].size() == 0)
		{
			flag1 = 1;
			continue;
		}
		if (oc['R'].size() + oc['G'].size() == 0)
		{
			continue;
		}

		if (oc['R'].size()>0 && oc['G'].size() > 0)
		{
			int D = abs(oc['R'][0] - oc['G'][0]);
			sg.push_back(D - 1);
		}
	}

	if (flag1&&flag2)
	{
		cout << "Draw" << endl;
		return 0;
	}
	if (flag1)
	{
		cout << "First" << endl;
		return 0;
	}

	if (flag2)
	{
		cout << "Second" << endl;
		return 0;
	}

	int er = 0;

	for (int bit = 0; bit <= 30; bit++)
	{
		int cnt = 0;
		for (int i = 0; i < sg.size(); i++)
		if (sg[i] & (1 << bit))
			++cnt;
		if (cnt % (k + 1))
			er = 1;
	}

	if (er)
		cout << "First" << endl;
	else
		cout << "Second" << endl;

	cin.get(); cin.get();
	return 0;
}