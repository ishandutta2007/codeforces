/*
I was never the kind
To be taking my time
Any place that's worth a damn
And today's another day
That I've gone and thrown away
And I don't care where it lands

'Cause I'm just thinking about us
I've been living in a dream about you
And now I know you were all I ever wanted on my mind
And if I never see
My own reality
Well, I'm okay to leave it all behind

I'll be gone for a time
Tuning out for a while
It's gonna look like I'm not all there
I've decided that today
Seems alright to piss away
Ignore my empty stare

'Cause I'm just thinking about us
I've been living in a dream about you
And now I know you were all I ever wanted on my mind
And if I never see
My own reality
Well, I'm okay to leave it all behind

When I come down
And look around
I can't believe
The fantasy is gone like a memory
Out of my reach
Fading out from me
You're fading out from me

I've been living in a dream about you
And now I know you were all I ever wanted on my mind
And if I never see
My own reality
Well, I'm okay to leave it all behind
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

int last;

int root[N],value[N],comp_size[N];
int tests;
int n;
vector<int> comp[N];

void answer(int val){
	cout<<val<<"\n";
	if (val==-1)
		last=1;
	else
		last=val;
}

int C;

map<int,int> existing;

int create_if_needed(int v){
	if (existing.find(v)!=existing.end())
		return existing[v];
	++C;
	existing[v]=C;
	root[C]=C;
	value[C]=0;
	comp[C].push_back(C);
	return C;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	last=0;

	cin>>tests;
	for (;tests;--tests){
		int tp;
		cin>>tp;
		if (tp==1) // merge
		{
			int l,r,val;
			cin>>l>>r>>val;
			l^=last;
			r^=last;
			if (l>r)
				swap(l,r);
			--l;
			l=create_if_needed(l);
			r=create_if_needed(r);

			val^=last;
			if (root[l]==root[r]) // nothing new
				continue;
			if (comp[root[l]].size()>comp[root[r]].size())
				swap(l,r);
			// now merge l to r; l is smaller;
			val^=value[l];
			l=root[l];
			val^=value[r];
			r=root[r];
			for (int i=0;i<comp[l].size();i++){
				int v=comp[l][i];
				root[v]=r;
				comp[r].push_back(v);
				value[v]^=val;
			}
		}
		else // get
		{
			int l,r;
			cin>>l>>r;
			l^=last;
			r^=last;
			if (l>r)
				swap(l,r);
			--l;
//			cout<<l<<"@"<<r<<endl;
			l=create_if_needed(l);
			r=create_if_needed(r);
		//	cout<<l<<"@"<<r<<" "<<root[l]<<" "<<root[r]<<endl;
			if (root[l]!=root[r]){
				answer(-1);
			}
			else
			{
				answer(value[l]^value[r]);
			}
		}
	}

//	cin.get(); cin.get();
	return 0;
}