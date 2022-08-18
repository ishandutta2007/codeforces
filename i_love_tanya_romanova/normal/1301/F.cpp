/*
Cold
Lying in my bed
Staring into darkness

Lost
I hear footsteps overhead
And my thoughts return
Again

Like a child who's run away
And won't be coming back
Time keeps passing by
As night turns into day

I'm so far away
And so alone
I need to see your face
To keep me sane
To make me whole

Try to stay alive
Until I hear your voice
I'm gonna lose my mind
Someone tell me why
I chose this life
This superficial lie
Constant compromise
Endless sacrifice

Pain
It saddens me to know
The helplessness you feel
Your light
Shines on my soul
While a thousand candles
Burn

Outside this barren room
The rain is pouring down
The emptiness inside
Is growing deeper still

You're so far away
And so alone
You long for love's embrace
To keep you sane
To make you whole

Try to stay alive
Until I hear your voice
I'm gonna lose my mind

Someone tell me why
I chose this life
This superficial lie
Constant compromise
Endless sacrifice

Moments wasted
Isolated
Time escaping
Endless sacrifice

Moments wasted
Isolated
Time escaping
Endless sacrifice

Over the distance
We try to make sense
Of surviving together
While living apart

Striving for balance
We rise to the challenge
Of staying connected
In spite of circumstance

All you've forsaken
And all that you've done
So that I could live out
This undying dream

Won't be forgotten
Or taken for granted
I'll always remember
Your endless sacrifice

Moments wasted
Isolated
Time escaping
Endless sacrifice

Moments wasted
Isolated
Time escaping
Endless sacrifice
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

int n,m,k;
int ar[1031][1031];
vector<pair<int,int> > entries[51];
int used[1031][1031];
queue<pair<int,int> > qu;
int clr_done[151];
int memo[44][1031][1031];

bool outside(int x,int y){
	return (x<1||x>n||y<1||y>m);
}

void fill_color(int clr,int value){
	clr_done[clr]=1;
	for (int i=0;i<entries[clr].size();i++){
		pair<int,int> p=entries[clr][i];
		int x=p.first;
		int y=p.second;
		if (used[x][y])
			continue;
		used[x][y]=value;
		qu.push(make_pair(x,y));
	}
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m>>k;

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		cin>>ar[i][j];
    		entries[ar[i][j]].push_back(make_pair(i,j));
    	}
    }

    for (int clr=1;clr<=k;clr++){

    	for (int i=1;i<=n;i++){
    		for (int j=1;j<=m;j++){
    			used[i][j]=0;
    		}
    	}

    	for (int i=0;i<entries[clr].size();i++){
    		int x=entries[clr][i].first;
    		int y=entries[clr][i].second;
    		qu.push(make_pair(x,y));
    		used[x][y]=1;
    	}

    	for (int i=1;i<=k;i++){
    		clr_done[i]=0;
    	}

    	while (qu.size()){
    		pair<int,int> p=qu.front();
    		qu.pop();
    		int x=p.first;
    		int y=p.second;
    		if (clr_done[ar[x][y]]==0)
    			fill_color(ar[x][y],used[x][y]+1);
    		for (int dx=-1;dx<=1;dx++){
    			for (int dy=-1;dy<=1;dy++){
    				if (abs(dx)+abs(dy)!=1)
    					continue;
    				if (outside(x+dx,y+dy))
    					continue;
    				if (used[x+dx][y+dy])
    					continue;
    				used[x+dx][y+dy]=used[x][y]+1;
    				qu.push(make_pair(x+dx,y+dy));
    			}
    		}
    	}

    	for (int i=1;i<=n;i++){
    		for (int j=1;j<=m;j++){
    			memo[clr][i][j]=used[i][j]-1;
    		}
    	}
    }

    int tests;

    cin>>tests;
    for (;tests;--tests){
    	int x1,y1,x2,y2;
    	cin>>x1>>y1>>x2>>y2;
    	int ans=abs(x1-x2)+abs(y1-y2);

    	for (int mid=1;mid<=k;mid++){
    		int here=memo[mid][x1][y1]+memo[mid][x2][y2]+1;
    		ans=min(ans,here);
    	}
    	cout<<ans<<endl;
    }
    //    cin.get(); cin.get();
    return 0;
}