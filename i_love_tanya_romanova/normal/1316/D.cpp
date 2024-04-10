/*
I took a little breather of my own
I might be too far-gone
Little fragments of my life are slowly dying
Trying not to be so far from home
But will I be there alone?
Fragile pieces of my mind
I'm feeling paralyzed
Compromised

So let it out, let it go
Just spit it out straight till I'm not breathing
Get it out, take it all
Just let it all find a way to be

So let it out, let it go
Just spit it out straight till I'm not breathing
Get it out, take it all
Just let it all find a way to be
Way to be

Critical decisions took too long
My promises are strong
Watching loyalties divide
So I'm taking back my life
Golden visions from now on
Can't carry you along
No more explanations why
I've erased the dramatized
Neutralized

So let it out, let it go
Just spit it out straight till I'm not breathing
Get it out, take it all
Just let it all find a way to be

So let it out, let it go
Just spit it out straight till I'm not breathing
Get it out, take it all
Just let it all find a way to be
Way to be

So let it all out, let it all go
Let it out, let it all out
So let it all out, let it all go
Let it out, let it all out
So let it all out, let it all go
Let it out, let it all out
(Let it all go now)
So let it all out, let it all go
Let it out, let it all out
(Let it all go now)
Let it out

So let it out, let it go
Just spit it out straight till I'm not breathing
Get it out, take it all
Just let it all find a way to be

So let it out, let it go
Just spit it out straight till I'm not breathing
Get it out, take it all
Just let it all find a way to be
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

const int N = 1031;

int n;
int fi[N][N];
int fj[N][N];
bool is_terminal[N][N];
char ans[N][N];
int used[N][N];
pair<int,int> par_dir[N][N];

bool outside(int i,int j){
	return (i<1||i>n||j<1||j>n);
}

void run_fill(int i,int j){
	used[i][j]=1;
	for (int dx=-1;dx<=1;dx++){
		for (int dy=-1;dy<=1;dy++){
			if (abs(dx)+abs(dy)!=1)
				continue;
			if (outside(i+dx,j+dy))
				continue;
			if (fi[i+dx][j+dy]!=fi[i][j]||fj[i+dx][j+dy]!=fj[i][j])
				continue;
			if (used[i+dx][j+dy])
				continue;
			par_dir[i+dx][j+dy]=make_pair(-dx,-dy);
			run_fill(i+dx,j+dy);
		}
	}
}

bool solve(){
	// all terminals point to themselves

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (is_terminal[i][j]){
				if (fi[i][j]!=i||fj[i][j]!=j)
					return false;
			}
		}
	}

	// all eventually-terminals should be connected to their corresponding endpoints.

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (is_terminal[i][j]==1){
				run_fill(i,j);
			}
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (fi[i][j]!=-1&&used[i][j]==0)
				return false;
		}
	}

	// all non-terminals should have neighbours for jump

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (used[i][j])
				continue;
			int found=0;
			for (int dx=-1;dx<=1;dx++){
				for (int dy=-1;dy<=1;dy++){
					if (abs(dx)+abs(dy)!=1)
						continue;
					if (outside(i+dx,j+dy))
						continue;
					if (used[i+dx][j+dy])
						continue;
					found=1;
					par_dir[i+dx][j+dy]=make_pair(-dx,-dy);
				}
			}
			if (!found)
				return false;
		}
	}
	return true;
}

void generate(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (is_terminal[i][j]){
				ans[i][j]='X';
				continue;
			}
			if (par_dir[i][j]==make_pair(-1,0))
				ans[i][j]='U';
			if (par_dir[i][j]==make_pair(1,0))
				ans[i][j]='D';
			if (par_dir[i][j]==make_pair(0,-1))
				ans[i][j]='L';
			if (par_dir[i][j]==make_pair(0,1))
				ans[i][j]='R';
		}
	}
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++){
    		cin>>fi[i][j]>>fj[i][j];
    	}
    }

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++){
    		if (fi[i][j]==-1&&fj[i][j]==-1){
    			continue;
    		}
    		is_terminal[fi[i][j]][fj[i][j]]=1;
    	}
    }

    int ok=solve();

    if (!ok){
    	cout<<"INVALID"<<endl;
    	return 0;
    }

    cout<<"VALID"<<endl;
    generate();

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++){
    		cout<<ans[i][j];
    	}
    	cout<<endl;

    }
    //    cin.get(); cin.get();
    return 0;
}