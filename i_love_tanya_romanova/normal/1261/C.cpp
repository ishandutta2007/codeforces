/*
Like wild fire
Comes roaring
Mad whirlwind
Burning the road

Black thunder
White lightning
Speed demons cry
The Hell Patrol

Night riders
Death dealers
Storm bringers
Tear up the ground

Fist flying
Eyes blazing
They're glory bound
The Hell Patrol

Brutalize you
Neutralize you
Gonna go for your throat as you choke
Then they'll vaporapeize you

Terrorize you
Pulverize you
Gonna cut to the bone as you groan
And they'll paratamize you

Crome Masters
Steel Warriors
Soul Stealers
Ripping out hearts
They're Devil Dogs
The Hell Patrol
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
vector<vector<int> > board,sums,sums_taken;
string st;
vector<pair<int,int> > memo;

bool full_square(int a,int b,int side){
	if (a+side-1>n)
		return false;
	if (b+side-1>m)
		return false;
	int here=sums[a+side-1][b+side-1]-sums[a-1][b+side-1]-sums[a+side-1][b-1]+sums[a-1][b-1];
	return (here==side*side);
}

bool valid_solution(int len){
	memo.clear();

	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			sums_taken[i][j]=0;
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (full_square(i,j,len*2+1)){
				memo.push_back(make_pair(i+len,j+len));
				sums_taken[i+len][j+len]=1;
			}
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			sums_taken[i][j]=sums_taken[i-1][j]+sums_taken[i][j-1]-sums_taken[i-1][j-1]+sums_taken[i][j];
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int li=i-len;
			if (li<1)
				li=1;
			int lj=j-len;
			if (lj<1)
				lj=1;
			int ri=i+len;
			if (ri>n)
				ri=n;
			int rj=j+len;
			if (rj>m)
				rj=m;
			int H=sums_taken[ri][rj]-sums_taken[li-1][rj]-sums_taken[ri][lj-1]+sums_taken[li-1][lj-1];
			if (H==0&&board[i][j]>0)
				return false;
			if (H>0&&board[i][j]==0)
				return false;
		}
	}

	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>m;
    board.resize(n+1);
    for (int i=0;i<board.size();i++){
    	board[i].resize(m+1);
    }

    sums.resize(n+1);
    for (int i=0;i<sums.size();i++){
    	sums[i].resize(m+1);
    }

    sums_taken.resize(n+1);
    for (int i=0;i<sums_taken.size();i++){
    	sums_taken[i].resize(m+1);
    }

    for (int i=0;i<board.size();i++){
    	for (int j=0;j<board[i].size();j++){
    		board[i][j]=0;
    	}
    }

    getline(cin,st);

    for (int i=0;i<n;i++){
    	getline(cin,st);
    	for (int j=0;j<m;j++){
    		if (st[j]=='.')
    			board[i+1][j+1]=0;
    		else
    			board[i+1][j+1]=1;
    	}
    }

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+board[i][j];
    	}
    }

    int l,r;
    l=0;
    r=1000000;
    while (l<r){
    	int mid=l+r+1;
    	mid/=2;
    	if (valid_solution(mid))
    		l=mid;
    	else
    		r=mid-1;
    }

    valid_solution(l);

    cout<<l<<endl;

    for (int i=0;i<board.size();i++){
    	for (int j=0;j<board[i].size();j++){
    		board[i][j]=0;
    	}
    }

    for (int i=0;i<memo.size();i++){
    	int x=memo[i].first;
    	int y=memo[i].second;
    	board[x][y]=1;
    }

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		if (board[i][j])
    			printf("X");
    		else
    			printf(".");
    	}
    	printf("\n");
    }

//    cin.get(); cin.get();
    return 0;
}