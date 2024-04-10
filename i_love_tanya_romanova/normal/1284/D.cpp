/*
Ain't got no job
Ain't got no smoke
Ain't got a car
His life's a joke

Living on the skids
Thinks the world's just fine
Forgot what he did
Dancing on the breadline

No one there to bind him
Nothing to remind him
Nowhere left to find him

About to lose his lifeline
He's dancing on the breadline

Forgot who he is
Forgot who he was
Used to call the shots
Now he can't connect the dots

A mover and shaker
Getting closer to his maker
Lower than a hemline
Dancing on the breadline

No one there to bind him
Nothing to remind him
Nowhere left to find him

About to lose his lifeline
He's looking for a headline
Sniffing up the white lines
He's dancing on the breadline

Watch him dance

About to lose his lifeline
He's looking for a headline
Sniffing up the white lines
He's dancing on the breadline
About to lose his lifeline
He's dancing on the breadline

No one, nothing, nowhere
Dancing on the breadline

He forgot and he ain't got nothing
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 510031;

int n;
int l1[N],r1[N],l2[N],r2[N];

multiset<int> right_ends;
multiset<int> left_ends;
multiset<int>::iterator it;

vector<pair<int,pair<int,int> > > events;

bool solver(){
	right_ends.clear();
	left_ends.clear();
	events.clear();

	for (int i=1;i<=n;i++){
		events.push_back(make_pair(l1[i],make_pair(-1,i)));
		events.push_back(make_pair(r1[i],make_pair(1,i)));
	}
	sort(events.begin(),events.end());

	for (int i=0;i<events.size();i++){
		int id=events[i].second.second;
		if (events[i].second.first==-1) // start
		{
			right_ends.insert(r2[id]);
			left_ends.insert(l2[id]);
		}
		else // end
		{
			right_ends.erase(right_ends.find(r2[id]));
			left_ends.erase(left_ends.find(l2[id]));
		}
		if (left_ends.size()>0){
			it=left_ends.end();
			--it;
			int rmost_start=(*it);
			it=right_ends.begin();
			int lmost_end=(*it);
			if (lmost_end<rmost_start)
				return 1;
		}
	}
	return 0;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++)
    {
    	cin>>l1[i]>>r1[i]>>l2[i]>>r2[i];
    }

    int ans=solver();

    for (int i=1;i<=n;i++){
    	swap(l1[i],l2[i]);
    	swap(r1[i],r2[i]);
    }
    ans=(ans|solver());

    if (ans)
    	cout<<"NO"<<endl;
    else
    	cout<<"YES"<<endl;

    //    cin.get(); cin.get();
    return 0;
}