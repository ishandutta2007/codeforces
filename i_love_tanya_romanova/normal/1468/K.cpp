/*
O my your fever's high
I lay my hands upon you
O my haven't you heard
The truth is untrue

Now I'm breathing
I could not breath until you did
I'm one second after you
Just a second after you

Someone inside your room
Who is it there behind you
What does he want from you

Sleeper what did you see
I close the window to the street
Paren't died and left their child
Unattented for a while

Sleeper's song will you listen to me sing
The bird is here I can see the edge of his wing
If you die now how can I then live on
Don't give up you must live on
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

const int N = 600031;

int tests;
string st;
int ax,ay;

pair<int,int> apply(int x,int y,char dir){
	if (dir=='L')
		--x;
	if (dir=='R')
		++x;
	if (dir=='U')
		++y;
	if (dir=='D')
		--y;
	return make_pair(x,y);
}

void try_it(pair<int,int> banned){
	int qx=0;
	int qy=0;
	for (int i=0;i<st.size();i++){
		pair<int,int> new_p=apply(qx,qy,st[i]);
		if (new_p==banned)
			continue;
		qx=new_p.first;
		qy=new_p.second;
	}
	if (qx==0&&qy==0){
		ax=banned.first;
		ay=banned.second;
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>st;
    	int qx=0;
    	int qy=0;
    	ax=ay=0;
    	for (int i=0;i<st.size();i++){
    		pair<int,int> P=apply(qx,qy,st[i]);
    		try_it(P);
    		qx=P.first;
    		qy=P.second;
    	}
    	cout<<ax<<" "<<ay<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}