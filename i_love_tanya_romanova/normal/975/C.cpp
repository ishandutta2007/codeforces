/*
To slit the grinning wounds
from childhood's seven moons
the palette stained with the ejaculated passions
(of forbidden, hedonistic colors...)

Strike from omnipotence; all-seer, all-deemer
and haunt my severed country with your
dripping, secret games

You pick the unripe lilies
deflored and peeled the bleeding petals
made known to me
the grainy stains, the crimson lotus
of the Black-Ash Inheritance,
the semen feed of gods and masters
The worms still in me,
still a part of me,
racing out from leaking rooms,
swoop from broken lungs to block the transmission
to put an end to the nomad years

Father
you are the
dead god in me
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

int n,q;
long long hp[N],S[N];
vector<long long> V;
long long cur_cnt;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>hp[i];
		S[i]=S[i-1]+hp[i];
	}

	S[n+1]=1e18;

	V.clear();
	for (int i=0;i<=n+1;i++){
		V.push_back(S[i]);
	}

	cur_cnt=0;

	for (;q;--q){
		long long val;
		cin>>val;
		cur_cnt+=val;
		if (cur_cnt>=V[n]){
			cout<<n<<"\n";
			cur_cnt=0;
			continue;
		}
		int id=upper_bound(V.begin(),V.end(),cur_cnt)-V.begin();
		cout<<n-(id-1)<<"\n";
	}

//	cin.get(); cin.get();
	return 0;
}