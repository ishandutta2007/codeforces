/*
Arena filled with screaming crowd
In ecstasy they cry
Paid money for a pleasant show
Want to see him die
The matador in shining dress
Intent to prove his courage
Drove by rejoicing mass
It boils his pulsing blood

Exhibition bouts under the star of law
Men make pleasure in hanging gore
Cruelty to animals crime that won't get punished
Creatures treated as rubbish

With direct stabs into living flesh
To agonise the bull
No way out the fronts are clear
Take offensive jab it though
On and on ride to the fall
In danger of his life
Wounded find no place to hide
Death will soon arrive

Exhibition bouts under the star of law
Men make pleasure in hanging gore
Cruelty to animals crime that won't get punished
Creatures treated as rubbish

Blood soaks and stains the parched ground
The slaughter to inaugurate
Duel between man and beast
Their eyes are filled with hate... hate... hate

He restrained fierce at the eleventh hour
Till death blows save his soul
No right to exist lamentation is law
His flesh served up a grub
Now finds piece in a better world
Where man and beast are one
Arena was filled with screaming crowd
He is dead and they are gone

Exhibition bouts under the star of law
Men make pleasure in hanging gore
Cruelty to animals crime that won't get punished
Creature treated as rubbish
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define BS 12345678891
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 500031;

int n,ar[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (i%2==0)
			continue;
		if (i>n-i+1)
			break;
		swap(ar[i],ar[n-i+1]);
	}

	for (int i=1;i<=n;i++)
	{
		if (i>1)
			cout<<" ";
		cout<<ar[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}