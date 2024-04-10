/*
So inevitable another lie another reason to justify
Tearing it down
Honesty such a novelty so we king ourselves with a plastic crown
Casualty of a daydream nation
Close acquaintance, no relation
Search & Destroy
Dignity we left laying along the way
To everyone's dismay
Predictable clich
Kindred enemies
The walking dead
Living a lie
Ever get the feeling you've been cheated?
So unavoidable another fight sell the ticket and crash the ride
Burn it down
A legacy of brutality
So caught up in the process of weeding out
The chopping block starving for a neck
Pointing fingers and stabbing backs
Never question, conformity
The big take over under way
Much to our dismay
A lucrative display
Perpetual decay
Left to destroy themselves
Yet somehow still alive
Battling for the best position, posturing for recognition
The best days thrown away
In an age of quarrel
Butcher the memories.
Ever get the feeling you've been cheated?
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

const int N = 300031;

int n;
map<int,int> cnt;
vector<int> order;
map<int,int> ::iterator it;
int ans;

int solver(int fi){
	int Q=fi;
	int ps=-1;
	int taken=0;
	while (true){
		int id=lower_bound(order.begin(),order.end(),fi)-order.begin();
		id=max(id,ps+1);
		if (id==order.size())
			break;
		taken+=fi;
		fi*=2;
		ps=id;
	}
	return taken;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		int val;
		cin>>val;
		cnt[val]++;
	}

	for (it=cnt.begin();it!=cnt.end();it++){
		int am=(*it).second;
		order.push_back(am);
	}

	sort(order.begin(),order.end());

	for (int start=1;start<=200000;start++){
		int here=solver(start);
		ans=max(ans,here);
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}