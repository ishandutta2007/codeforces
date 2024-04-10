/*
No shape, no form, no brain, no mind
But the power to control all resistance
Its awesome might cannot be denied

By the world that ignores its existence

Older than time - stranger than life
Don't look for a sign without warning it will arrive

It can read your mind
See the world inside
Oversees your life
Decides the day you die
Silent lifetaker
Sentient creator
Worlds recoil in fear
Of the hidden dictator

Presence beyond our imagination
Horrible being of fate
Not one sign of its domination
God prays it never awakes

Older than time - stranger than life
Don't look for a sign without warning it will arrive

It can read your mind
See the void inside
Oversees your life
Decides the day you die
Silent lifetaker
Sentient creator
Worlds recoil in fear
Of the hidden dictator

Worlds have risen, lived and died under its obscene command
Kept the balance of galaxies in its omnipotent hands

Minds of greedy distortion
All are destroyed in its wake
It judges the worth of the low forms of life
Who cower and quiver and quake

Some may call it the savior
Fall to their bellies and pray
Some will try to resist in the hope they'll exist
To experience just one more day

And the lost shall pray for forgiveness
And the fearful and weak start to scream
As the terrible nightmare of a dying world
Becomes beauty beyond any dream

One world must end
New ones begin
A pure life form
From death is born
Silent lifemaker
Sentient creator
The new world is blessed by the hidden dictator
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

const int N = 1100031;

int n,m,tests;
char board[531][531];
int R_left[531][531],R_up[531][531],G_up[531][531],G_right[531][531];
int Y_left[531][531],Y_down[531][531],B_down[531][531],B_right[531][531];
int R_square[531][531],Y_square[531][531],B_square[531][531],G_square[531][531];
int ANS[531][531];

int sparse[10][10][531][531];

int LG[531];

int get(int r1,int c1,int r2,int c2){
	if (r1>=r2||c1>=c2)
		return 0;
	int l1=LG[r2-r1];
	int l2=LG[c2-c1];
	int ret=0;
	ret=max(ret,sparse[l1][l2][r1][c1]);
	ret=max(ret,sparse[l1][l2][r2-(1<<l1)][c1]);
	ret=max(ret,sparse[l1][l2][r1][c2-(1<<l2)]);
	ret=max(ret,sparse[l1][l2][r2-(1<<l1)][c2-(1<<l2)]);
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    for (int i=2;i<=500;i++){
    	LG[i]=LG[i/2]+1;
    }

    cin>>n>>m>>tests;
    for (int i=1;i<=n;i++){
    	string st;
    	cin>>st;
    	for (int j=1;j<=m;j++){
    		board[i][j]=st[j-1];
    	}
    }

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		R_left[i][j]=R_left[i][j-1]+1;
    		R_up[i][j]=R_up[i-1][j]+1;
    		if (board[i][j]!='R')
    			R_left[i][j]=R_up[i][j]=0;
    	}
    }

    for (int i=1;i<=n;i++){
    	for (int j=m;j>=1;--j){
    		G_right[i][j]=G_right[i][j+1]+1;
    		G_up[i][j]=G_up[i-1][j]+1;
    		if (board[i][j]!='G')
    			G_right[i][j]=G_up[i][j]=0;
    	}
    }

    for (int i=n;i>=1;--i){
    	for (int j=1;j<=m;j++){
    		Y_left[i][j]=Y_left[i][j-1]+1;
    		Y_down[i][j]=Y_down[i+1][j]+1;
    		if (board[i][j]!='Y')
    			Y_left[i][j]=Y_down[i][j]=0;
    	}
    }

    for (int i=n;i>=1;--i){
    	for (int j=m;j>=1;--j){
    		B_right[i][j]=B_right[i][j+1]+1;
    		B_down[i][j]=B_down[i+1][j]+1;
    		if (board[i][j]!='B')
    			B_down[i][j]=B_right[i][j]=0;
    	}
    }

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		R_square[i][j]=R_square[i-1][j-1]+1;
    		R_square[i][j]=min(R_square[i][j],min(R_left[i][j],R_up[i][j]));
    		G_square[i][j]=G_square[i-1][j+1]+1;
    		G_square[i][j]=min(G_square[i][j],min(G_right[i][j],G_up[i][j]));
    	}
    }

    for (int i=n;i>=1;--i){
    	for (int j=1;j<=m;j++){
    		Y_square[i][j]=Y_square[i+1][j-1]+1;
    		Y_square[i][j]=min(Y_square[i][j],min(Y_left[i][j],Y_down[i][j]));
    		B_square[i][j]=B_square[i+1][j+1]+1;
    		B_square[i][j]=min(B_square[i][j],min(B_down[i][j],B_right[i][j]));
    	}
    }

    for (int i=1;i<n;i++){
    	for (int j=1;j<m;j++){
    		ANS[i][j]=min(R_square[i][j],G_square[i][j+1]);
    		ANS[i][j]=min(ANS[i][j],min(Y_square[i+1][j],B_square[i+1][j+1]));
    	}
    }

  /*  for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		cout<<ANS[i][j];
    	}
    	cout<<endl;
    }
*/
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		sparse[0][0][i][j]=ANS[i][j];
    	}
    }

    for (int lev1=0;lev1<=10;lev1++){
    	for (int lev2=0;lev2<=10;lev2++){
    		for (int i=1;i<=n;i++){
    			for (int j=1;j<=m;j++){
    				if (lev1==0&&lev2==0)
    					continue;
    				if (i+(1<<lev1)-1>n||j+(1<<lev2)-1>m)
    					continue;
    				if (lev2!=0){
    					sparse[lev1][lev2][i][j]=max(sparse[lev1][lev2-1][i][j],sparse[lev1][lev2-1][i][j+(1<<lev2)/2]);
    				}
    				else{
    					sparse[lev1][lev2][i][j]=max(sparse[lev1-1][lev2][i][j],sparse[lev1-1][lev2][i+(1<<lev1)/2][j]);
    				}
    			}
    		}
    	}
    }

    for (;tests;--tests){
    	int r1,c1,r2,c2;
    	cin>>r1>>c1>>r2>>c2;

    	int l,r;
    	l=0;
    	r=max(n,m);
    	while (l<r){
    		int mid=l+r+1;
    		mid/=2;
    		int here=get(r1+mid-1,c1+mid-1,r2-mid+1,c2-mid+1);
    		if (here>=mid)
    			l=mid;
    		else
    			r=mid-1;
    	}
    	cout<<l*l*4<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}