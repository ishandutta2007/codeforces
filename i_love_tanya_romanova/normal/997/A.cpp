/*
A place afar in distant dreams
Mystic winds blow
Men mount birds of prey to war
And raid each others shore
Wizards and Warlocks battle by night
One survives by cunning and might
Take what you can by sword and sabre
Just reward for perilous labour

Stands among them a natural King
A man of barbaric breed
In a blade of steel he lays his trust
Killing and taking his needs
Upon him the scars of battles gone by
From many who have gazed in his murderous eye
Astride his mount he cursed and then
Assembled his men in thousands and ten
Onward lads we'll kill them all
Victory is ours
We'll have their heads and female slaves
Soon to loot their towers
Riding hard they rushed the gates
And scaled the granite walls
Through boiling oil and falling stone
His men endured it all

In bloody streets the battle raged
Brave men died and women were caged
Amidst the hoard, a barbaric roar
He gut the guard and kicked down the door
Sword in one hand, torch in the other
Alert every step of the way
If legends be true this place is cursed
Demons stand guard night and day

Living hell cloaked in black
Three ungodly hosts
Upon the dais a ball of light
Which binds them to their post
Faster than a striking cobra
Hit the altar and knocked it over
Shattered in a silver shower
The priests of hell have lost their power

Up the stairs a golden door
The queen awaits within
Her naked body close to his
The prize is won again
And has she yields to his force
His mind drifts off to Future Wars
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int n,x,y;
long long ans;
string st;
int cnt;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>x>>y;

	cin>>st;
	for (int i=1;i<st.size();i++){
		if (st[i]!=st[i-1])
			++cnt;
	}
	if (st[0]=='0')
		++cnt;
	int times=cnt/2+cnt%2;

	if (times==0){
		cout<<0<<endl;
		return 0;
	}

	if (x>y){
		cout<<times*1ll*y<<endl;
	}
	else
	{
		cout<<(times-1)*1ll*x+y<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}