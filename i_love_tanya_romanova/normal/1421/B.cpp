/*
Living and dying laughing and crying
Once you have seen it you will never be the same
Life in the fast lane is just how it seems
Hard and it's heavy, it's dirty and mean

Motorbreath
It's how I live my life
I can't take it any other way
Motorbreath
The sign of living fast
It is going to take
Your breath away

Don't stop for nothing it's full speed or nothing
I am taking down you know whatever is in my way
Getting your kicks as you are shooting the line
Sending the shivers up and down your spine

Motorbreath
It's how I live my life
I can't take it any other way
Motorbreath
The sign of living fast
It is going to take
Your breath away

Those people who tell you not to take chances
They are all missing on what life is about
You only live once so take hold of the chance
Don't end up like others the same song and dance

Motorbreath
It's how I live my life
I can't take it any other way
Motorbreath
The sign of living fast
It is going to take
Your breath away
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

int tests,n;
string st;
int board[331][331];
vector<pair<int,int> > ans;

int eval(int a,int b){
	ans.clear();
	if (board[1][2]!=a)
		ans.push_back(make_pair(1,2));
	if (board[2][1]!=a)
		ans.push_back(make_pair(2,1));
	if (board[n][n-1]!=b)
		ans.push_back(make_pair(n,n-1));
	if (board[n-1][n]!=b)
		ans.push_back(make_pair(n-1,n));
	return ans.size();
}


void show_ans(){
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>st;
    		for (int j=1;j<=n;j++){
    			board[i][j]=st[j-1]-'0';
    		}
    	}
    	int cost=eval(0,1);
    	if (cost<=2){
    		show_ans();
    		continue;
    	}
    	cost=eval(1,0);
    	show_ans();
    }

    //cin.get(); cin.get();
    return 0;
}