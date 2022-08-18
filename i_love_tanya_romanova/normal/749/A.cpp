/*
I am the ever-forsaken.
Bastard child of your disease.
Your dead and abandoned.
Strung up for all of you to see.
Naked and screaming.
So beautiful, profane.
The essence of bleeding.
The scars that bear my name.
I am the hatred incarnate.
I am the choked and dying screams.
I am the sickness inside you longing for...
This is the hate that surrounds you.
Pray for the endless touch of death.
Now burning inside you.
I am the scars of your disease.
I am eternal damnation.
The bastard child of your disease.
The slow suffocation.
Strung up for everyone to see.
Sever the feeling.
The mirror of your shame.
The darkest temptation.
Your scars that bear my name.
I am the endless procession.
I am the poison for the weak.
I am your loveless desire.
Longing for...
This is the hate that surrounds you.
Pray for the endless touch of death now burning inside you.
I am the scars of your disease.
I am the ever-forsaken.
Bastard child of your disease.
Your dead and abandoned.
Strung up for all of you to see.
This is the hate that surrounds you.
Pray for the endless touch of death now burning inside you.
I am the scars of your disease.
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
const int N = 2031;

int n;
vector<int> ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n / 2; i++)
	{
		ans.push_back(2);
	}
	if (n % 2 == 0)
		ans.push_back(2);
	else
		ans.push_back(3);

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}