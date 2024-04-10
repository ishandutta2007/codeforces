/*
Rush faster on the one-way lane
the answers so silent

Rusty gods in their machine-minds armours
grind our souls in the millstone of time
the "deathbed harvest" is dead man's banquet
of mould ridden bread and black, poisoned wine

And we go..our steps so silent
And we go..our blooded trace;
The Jester Race

Calling our to the gathered masses;
their answers so silent

And we go..

Embracing the tools of the neo-wolf age
that speak of silence and silence alone

Offering the tokens, the reliced idols
to the heirs of the newly raped ground
inferior even to the transparent winds
lesser in motion and sound

And we go..

There is no trace of me
in their altered blueprints of life

Gaia impaled on their horns and lances
to fumes from her body give case
as the throng of blind mind savour the scent,
dream-dead from prosaic and hate

Sunwind strokes the electroheart,
ignition roars through the corridors,
stream launching the binary vessels

Vanities in extreme formations
ride into tomorrow's rigid great face
The Machinery outlives the futile scripts
of our dying jester race
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

long long ans,ar[N],temp[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	for (int i=0;i<14;i++){
		cin>>ar[i];
	}

	ans=-1;
	for (int i=0;i<14;i++){
		if (ar[i]==0)
			continue;
		for (int j=0;j<14;j++){
			temp[j]=ar[j];
		}
		int full=ar[i]/14;
		int rem=ar[i]%14;
		temp[i]=0;
		for (int j=0;j<14;j++){
			temp[j]+=full;
		}
		for (int j=1;j<=rem;j++){
			temp[(j+i)%14]++;
		}
/*		for (int j=0;j<14;j++){
			cout<<temp[j]<<" ";
		}
		cout<<endl;
*/
		long long cnt=0;
		for (int j=0;j<14;j++){
			if (temp[j]%2==0)
				cnt+=temp[j];
		}
		ans=max(ans,cnt);
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}