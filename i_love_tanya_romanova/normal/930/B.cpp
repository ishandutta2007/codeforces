/*
Towards the rich archaic heavens; towards the lack diorama
you are the artist and the texture
that plays with the mantle of the Earth

When the bleakest of powders
lie rooted to the starched stones
and roots that feed the peaking trees
embrace the sleeping shores

Archaic pearls of sleep and death
the voice of December losing its breath
and the floweryard of whit and grey is haunted

White as the down of flaking snow,
the heroic emblems of life

Green is the color of my death
as the winter-guise I swoop towards teh ground
Green is the landscape of my sorrowfilled passing

We are In Flames,
towards the dead archaic heavens
We are the mantle and the texture
the alters the mantle of the Earth
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

const int N = 400031;

string st;
vector<int> entries[N];
int good_guesses[N];
int cnt[N];
int ans;
int n;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;
	n=st.size();

	for (int i=0;i<st.size();i++){
		int here=st[i]-'a';
		entries[here].push_back(i);
	}

	for (int fi=0;fi<26;fi++){
		for (int i=0;i<=st.size();i++){
			good_guesses[i]=0;
		}

		for (int my_guess=0;my_guess<st.size();my_guess++){
			for (int j=0;j<26;j++){
				cnt[j]=0;
			}
			for (int j=0;j<entries[fi].size();j++){
				int id=entries[fi][j];
				int ps=id+my_guess;
				ps%=st.size();
				int at_ps=st[ps]-'a';
				cnt[at_ps]++;
			}
			for (int j=0;j<26;j++){
				if (cnt[j]==1)
					good_guesses[my_guess]++;
			}
		}
		int best=0;
		for (int i=0;i<=st.size();i++){
			best=max(best,good_guesses[i]);
		}
		ans+=best;
	}
	cout.precision(15);
	cout<<fixed<<1.0*ans/n<<endl;

//	cin.get(); cin.get();
	return 0;
}