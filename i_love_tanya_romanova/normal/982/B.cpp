/*
Like most babies smell like butter
His smell smelled like no other
He was born scentless and senseless
He was born a scentless apprentice

Go away! Go away! Go away!

Every wet nurse refused to feed him
Electrolytes smell like semen
I promise not to sell your perfumed secrets
There are countless formulas for pressing flowers

Go away! Go away! Go away!

I lie in the soil and fertilize mushrooms
Leaking out gas fumes are made into perfume
You can't fire me because I quit!
Throw me in the fire and I won't throw a fit

Go away! Go away! Go away! Go away! Go away! Go away! Go away! Go away!
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

set<pair<int,int> > intr,extr;
set<pair<int,int> > ::iterator it;
int n;
string st;
int w[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>w[i];
		intr.insert(make_pair(w[i],i));
	}

	cin>>st;
	for (int i=0;i<st.size();i++){
		if (st[i]=='0'){
			it=intr.begin();
			int id=(*it).second;
			intr.erase(it);
			extr.insert(make_pair(w[id],id));
			cout<<id<<"\n";
		}
		else{
			it=extr.end();
			--it;
			int id=(*it).second;
			extr.erase(it);
			cout<<(id)<<"\n";
		}
	}

//	cin.get(); cin.get();
	return 0;
}