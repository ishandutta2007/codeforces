/*
I don't mind just what you say.
I never heard you, baby, never heard you anyway.
I don't care what you do
just so long as it ain't me and you.
Sly, sly, sly like a demon's eye.

Everything's good, I said, everything's fine.
You don't know, don't know it's the end of your time.
How does it feel to be turned away?
I've known it, baby, almost every day.
Sly, sly, sly like a demon's eye.

I don't need you anymore,
I don't want you, baby, hanging round my door.
You slip and slide round my brain.
You think you're so clever, yeah, but you know you're insane.
Sly, sly, sly like a demon's eye.

I d-d-don't mind just what you say.
I never heard you, baby, I never heard you anyway, no I didn't.
Everything's good, everything's fine.
You don't know it's the end of your time.
Sly, sly, sly like the demon's eye,
like the demon's eye.
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

const int N = 600031;

int n,m,p[N];
int v1[N],v2[N];
int who_moves;
int taken[N];

int get_forced_move(){
	for (int i=1;i<=m;i++){
		if (taken[v1[i]]+taken[v2[i]]==1){
			if (taken[v1[i]]==0)
				return v1[i];
			return v2[i];
		}
	}
	return -1;
}

pair<int,int> best_forced(){
	pair<int,int> P=make_pair(-1,-1);
	for (int i=1;i<=m;i++){
		if (taken[v1[i]]+taken[v2[i]]==0){
			int dif=abs(p[v1[i]]-p[v2[i]]);
			if (dif>P.second){
				P.second=dif;
				if (p[v1[i]]>p[v2[i]])
					P.first=v1[i];
				else
					P.first=v2[i];
			}
		}
	}
	return P;
}

pair<int,int> best_overall(){
	pair<int,int> P=make_pair(-1,-1);
	for (int i=1;i<=n*2;i++){
		if (taken[i])
			continue;
		if (p[i]>P.second){
			P=make_pair(i,p[i]);
		}
	}
	return P;
}

void make_move(int id){
	cout<<id<<endl;
	taken[id]=1;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;

	for (int i=1;i<=n*2;i++){
		cin>>p[i];
	}

	for (int i=1;i<=m;i++){
		cin>>v1[i]>>v2[i];
	}

	cin>>who_moves;

	for (int i=1;i<=2*n;i++){
		// his move, nothing interesting
		if (i%2!=who_moves%2){
			int id;
			cin>>id;
			taken[id]=1;
			continue;
		}
		// our move
		// forced?
		int t=get_forced_move();
		if (t!=-1){
			make_move(t);
			continue;
		}
		// force opponent
		pair<int,int> P=best_forced();
		if (P.first!=-1){
			make_move(P.first);
			continue;
		}
		// pick best
		P=best_overall();
		make_move(P.first);
	}

//	cin.get(); cin.get();
	return 0;
}