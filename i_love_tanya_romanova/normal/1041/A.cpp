/*
You walk this earth without a heart
You tear the innocent's souls apart
You shovel your conscience into the grave
You walk this earth without a heart
Your uniform couldn't be taken off
A tattoo burned into your flesh
Your mind, your voice
These are your instruments of death
How could you dare to be so bold
You only did as you were told
Marionettes dancing in time
To the apologetic lines
For all the monsters of our time

Who is evil, who is blind?
In the name of who you'll find,
A city of souls dying for peace
Welcome to the belly of the beast
One mind, one voice
Welcome to the belly of the beast
Who hears, your voice?

Millions, never, never again
Madness, never, never again
Martyrs, dead that can't die
Monsters

Insanity, the normal state
The left hand a hammer, the right the stake
Driven so deep into the heart
It's killing love, it's killing faith
It's killing 'cause it's from the heart
What better way to demoralize
When your own children are your spies
The things you trust are not the same
Trust in grief, trust in death
Trust in hope is trust in pain

Who is evil, who is blind?
In the name of who you'll find,
You're not supposed to question faith
But how do you accept this fate?

Millions, you walk this earth without a heart
Madness, tear the innocent's souls apart
Martyrs, shovel your conscience into the grave
Monsters
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
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600000;

int n;
vector<int> v;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=0;i<n;i++){
		int val;
		cin>>val;
		v.push_back(val);
	}
	sort(v.begin(),v.end());
	cout<<(v[v.size()-1]-v[0]+1)-v.size()<<endl;

//	cin.get(); cin.get();
	return 0;
}