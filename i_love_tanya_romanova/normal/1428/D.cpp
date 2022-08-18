/*
They are getting small, these shadows on the wall
Shadows that dwell, for your own private hell
I know you will not try to understand, I know you will not strive for change

Have you ever thought about why, have you ever given it a try
Have you faced the flames inside
Have you ever understood mankind

Both ends burning, inside the circles turning
Staring into the glass, making a mess
No one knows whats meant to break, no one knows whats meant to take

Have you ever thought about why, have you ever given it a try
Have you faced the flames inside
Have you ever understood mankind

Smash it, break this glass -do it, stop this mess - stop it,
Bleed it out, reach for the sane

Have you ever thought about why, have you ever given it a try
Have you faced the flames inside
Have you ever understood mankind

Have you ever thought about why, have you ever given it a try
Have you faced the flames inside
Have you ever understood mankind
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 200031;

int n,ar[N];

set<pair<int,int> > available;
set<pair<int,int> >::iterator it;
vector<pair<int,int> > ans;
vector<pair<int,int> > interesting;

bool solve(){
	for (int i=n;i>=1;--i){
		if (ar[i]==1){
			available.insert(make_pair(i,i));
			ans.push_back(make_pair(i,i));
		}
	}
	for (int i=n;i>=1;--i){
		if (ar[i]==2){
			it=available.lower_bound(make_pair(i+1,-1));
			if (it==available.end())
				return false;
			pair<int,int> P=(*it);
			available.erase(P);
			ans.push_back(make_pair(i,P.second));
			interesting.push_back(make_pair(i,P.second));
		}
	}

	for (int i=0;i<interesting.size();i++)
		available.insert(interesting[i]);

	for (int i=n;i>=1;--i){
		if (ar[i]==3){
			it=available.lower_bound(make_pair(i+1,-1));
			if (it==available.end())
				return false;
			pair<int,int> P=(*it);
			available.erase(it);
			ans.push_back(make_pair(i,i));
			ans.push_back(make_pair(P.first,i));
			available.insert(make_pair(i,i));
		}
	}

	return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    bool ok=solve();

    if (!ok){
    	cout<<-1<<endl;
    }
    else
    {
    	cout<<ans.size()<<endl;
    	for (int i=0;i<ans.size();i++){
    		cout<<ans[i].second<<" "<<ans[i].first<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}