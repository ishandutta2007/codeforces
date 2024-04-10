/*
Pesticide in torrents, how fast it flows
Total pollution the earth can't stand much longer
Chemical industry brings new diseases
The fear of self-destruction is growing stronger
Nuclear waste in an uncontrolled deluge
Reduces the earth to an airless planet
Reformation lies far away
Now is your only chance to save it

Contamination in every place
Condemn the human race
Everything will decay
Broken down by toxic trace

New plagues have come and soon there'll be more
Apocalypse not for the first time
Suppression is alive and that's for sure
Everyone will be annihilated
Enforcement of the last eclipse
Can't ignore predictions from the past
Ignore the warnings of ancient prophets
Every minute of your life could be your last

Contamination in every place
Condemn the human race
Everything will decay
Broken down by toxic trace

Metamorphoses of the earth to a lifeless desert
Voracity for richness, ruin of mankind
Craving more and more, to the world's requiem
This is the earth's last century

Now deprivation from things that count, to make an easier life for me
Total confusions for the non-believers who ignore the writings on the wall
Times of suffering for everyone, no-one can hide from reality
Social injustice will be no more, without exception, devastate all

Times have changed from the past to now
The earth is mankind's subject
Perfect creation stands over all
Experimenting with lethal objects
Domination, submission, demand for more
De-humanizes the brains of the rulers
What gives them the right to menace us all
This time will come but then it will be too late
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

#define bs 998244353

const int N = 200000;

long long n,k,l,r;

bool found;

int tries;

int query(long long l,long long r){
	cout<<l<<" "<<r<<endl;
	if (l==r)
		++tries;
	string temp;
	cin>>temp;
//	temp="No";
	if (l==r&&temp=="Yes")
		found=1;
	if (temp=="Yes")
		return 1;
	return 0;
}

long long normalize(long long x){
	if (x<1)
		return 1;
	if (x>n)
		return n;
	return x;
}

void random_guess(long long l,long long r){
	int span=r-l+1;
	int Q=rand()%span;
	query(l+Q,l+Q);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	srand(time(NULL));

	/*long long span=1e18;
	for (int iter=1;iter<=100;iter++){
		cout<<iter<<" "<<span<<endl;
		span=span/2+20;
	}
*/
	cin>>n>>k;

	l=1;
	r=n;

	int iter=0;

	while (iter<=4500){
		++iter;
		if (found)
			break;
		if (r-l<=70){
			random_guess(l,r);
			l=normalize(l-k);
			r=normalize(r+k);
		}
		else
		{
			long long mid=l+r;
			mid/=2;
			bool P=query(l,mid);
			if (P==1)
				r=mid;
			else
				l=mid+1;
			l=normalize(l-k);
			r=normalize(r+k);
		}
	}

	//cout<<tries<<endl;

//	cin.get(); cin.get();
	return 0;
}