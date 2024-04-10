/*
Cursed
Black magic night
We've been struck down
Down in this Hell
Spells surround me day and night
Stricken by the force of evil light
The force of evil light

Cast
Under his spell
Blinding my eyes
Twisting my mind
Fight to resist the evil inside
Captive of a force of Satan's might
A force of Satan's might

Fighting the curse
Break it I must
Laughing in sorrow
Crying in lust

My strength slips fast
Soon I must fall
Victim of fortune
My sources grow small
Life slips away
As demons come forth
Death takes my hand
And captures my soul
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

int n,l[N],r[N];
vector<pair<pair<int,int>,int> > order;
int ans1,ans2;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		order.push_back(make_pair(make_pair(l[i],-r[i]),i));
	}
	sort(order.begin(),order.end());
	int rmost=-1;
	int rmost_x=-1;
	ans1=ans2=-1;

	for (int i=0;i<order.size();i++){
		int id=order[i].second;
		if (r[id]<=rmost_x){
			ans2=rmost;
			ans1=id;
		}
		if (r[id]>rmost_x){
			rmost_x=r[id];
			rmost=id;
		}
	}

	cout<<ans1<<" "<<ans2<<endl;

//	cin.get(); cin.get();
	return 0;
}