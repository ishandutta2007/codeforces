/*
Grand canyons of space and time universal
My mind is subjected to all

Stab! Bawl! Punch! Crawl!
Hooks to my brain are well in
Stab! Bawl! Punch! Crawl!
I know what I am, I'm Berlin

Through cracked, blackened memories of unit dispersal
I face the impregnable wall

Stab! Bawl! Punch! Crawl!
Hooks to my brain are well in
Stab! Bawl! Punch! Crawl!
I know what I am, I'm Berlin

Exploding, reloading, this quest never ending
Until I give out my last breath

I'm stabbing and bawling, I'm punching and crawling
Hooks to my brain are well in
I'm stabbing and bawling, I'm punching and crawling
I know what I am, I'm Berlin
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

const int N = 500031;

int n,m;
string st;
int board[2031][2031],right_cnt[2031][2031],down_cnt[2031][2031];
int up[2031][2031],left[2031][2031];
int pref_row[2031][2031];
int pref_col[2031][2031];
int dp_up[2031][2031],dp_left[2031][2031];

void normalize(int&x){
	if (x<0)
		x+=bs;
	while (x>=bs)
		x-=bs;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>m;
    if (n==1&&m==1){
    	cout<<1<<endl;
    	return 0;
    }

    getline(cin,st);
    for (int i=1;i<=n;i++){
    	getline(cin,st);
    	for (int j=1;j<=m;j++){
    		if (st[j-1]=='R')
    			board[i][j]=1;
    		else
    			board[i][j]=0;
    	}
    }

    for (int i=n;i>=1;--i){
    	for (int j=m;j>=1;--j){
    		right_cnt[i][j]=right_cnt[i][j+1]+board[i][j];
    		down_cnt[i][j]=down_cnt[i+1][j]+board[i][j];
    	}
    }

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){

    		if (i==1)
    			up[i][j]=1;
    		else
    		{
    			up[i][j]=up[i-1][j];
    			while (down_cnt[up[i][j]+1][j]>n-i)
    				++up[i][j];
    		}

    		if (j==1){
    			left[i][j]=1;
    		}
    		else
    		{
    			left[i][j]=left[i][j-1];
    			while (right_cnt[i][left[i][j]+1]>m-j)
    				++left[i][j];
    		}
    	}
    }

  /*  for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		cout<<left[i][j]<<" ";
    	}
    	cout<<endl;
    }*/


    dp_up[1][1]=1;
    dp_left[1][1]=1;
    pref_row[1][1]=1;
    pref_col[1][1]=1;

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		if (i==1&&j==1)
    			continue;
    		if (left[i][j]<j){
    			dp_left[i][j]=(dp_left[i][j]+pref_row[i][j-1]-pref_row[i][left[i][j]-1]);
    			normalize(dp_left[i][j]);
    		}
    		if (up[i][j]<i){
    			dp_up[i][j]=(dp_up[i][j]+pref_col[i-1][j]-pref_col[up[i][j]-1][j]);
    			normalize(dp_up[i][j]);
    		}
    		pref_row[i][j]=pref_row[i][j-1]+dp_up[i][j];
    		pref_col[i][j]=pref_col[i-1][j]+dp_left[i][j];
    		normalize(pref_row[i][j]);
    		normalize(pref_col[i][j]);
    	}
    }

    cout<<(dp_up[n][m]+dp_left[n][m])%bs<<endl;

//    cin.get(); cin.get();
    return 0;
}