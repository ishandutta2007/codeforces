/*
Feelings cold as ice, I never, never think twice
Hunting down my prey - they die
Cross my line of death and there's nothing else left
Any way you choose - you lose
Architect of pain, deadly is my middle name
And I'm living proof - crime pays
I'm a psychopath and I create the aftermath
That sets the sun forever - on you

Haven't you figured out it open season?
I'll track you down and kill you for no apparent reason
Running like a frightened little rabbit would run
I won't be satisfied
Until you're nullified
Before my eyes

Intoxicating
Invigorating
It's open season on you

Calling the police and I'm gonna pull my piece
Your heart's gonna cease - to beat
Just look in my eye, black as pitch to horrify
You can scream and cry - goodbye
It may never last and I blame it on the past
Being told to kill - at will
Shivers down my spine when the victim is all mine
You begin to beg - for help

Haven't you figured out it open season?
I'll track you down and kill you for no apparent reason
Running like a frightened little rabbit would run
I won't be satisfied
Until you're nullified before my eyes

Intoxicating, invigorating
It's open season on you

Go ahead and run, the chase is always fun
But the kill is the icing on the cake
A curtain of red from my hailstorms of lead
Will rain on you as you die
Your face will be spewing chunks of bloody ruin
Your baby face will be a gory mask
My personal crusade is to see that you are flayed
And my hunting knife will complete the task
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n,m,k,q;
vector<int> cells[N];
set<int> safe;
set<int>::iterator it;

long long dp[N][3];
vector<vector<int> > rows;

int get_nxt(int ps){
	it=safe.lower_bound(ps);
	if (it==safe.end())
		--it;
	return (*it);
}

int get_prv(int ps){
	it=safe.lower_bound(ps);
	if (it!=safe.begin())
		--it;
	return (*it);
}

long long solver(int very_start, int start,int a,int b){
	return abs(start-very_start)+abs(start-a)+abs(a-b);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>m>>k>>q;

    for (int i=1;i<=k;i++){
    	int r,c;
    	cin>>r>>c;
    	cells[r].push_back(c);
    }

    for (int i=1;i<=q;i++){
    	int val;
    	cin>>val;
    	safe.insert(val);
    }

    if (cells[1].size()==0)
    	cells[1].push_back(1);

    int mx=-1;

    for (int i=1;i<=n;i++)
    {
    	if (cells[i].size()==0){
    		continue;
    	}
    	sort(cells[i].begin(),cells[i].end());
    	mx=i;
    	rows.push_back(cells[i]);
    }

    for (int i=0;i<rows.size();i++){
    	dp[i][0]=dp[i][1]=1e18;
    }

    dp[0][1]=rows[0].back()-1;

    for (int i=0;i+1<rows.size();i++){
    	for (int j=0;j<=1;j++){
    		int cur_pos;
    		if (j==0)
    			cur_pos=rows[i][0];
    		else
    			cur_pos=rows[i].back();
    		int P1;
    		int P2;
    		P1=rows[i+1][0];
    		P2=rows[i+1].back();

    		//cout<<P1<<"@"<<P2<<endl;
    		//cout<<get_prv(cur_pos)<<" "<<get_nxt(cur_pos)<<endl;

    		//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    		dp[i+1][0]=min(dp[i+1][0],dp[i][j]+min(solver(cur_pos,get_nxt(cur_pos),P2,P1),solver(cur_pos,get_prv(cur_pos),P2,P1)));
    		dp[i+1][1]=min(dp[i+1][1],dp[i][j]+min(solver(cur_pos,get_nxt(cur_pos),P1,P2),solver(cur_pos,get_prv(cur_pos),P1,P2)));
    	}

		int P1;
		int P2;
		P1=rows[i+1][0];
		P2=rows[i+1].back();

    	dp[i+1][1]=min(dp[i+1][1],dp[i+1][0]+P2-P1);
		dp[i+1][0]=min(dp[i+1][0],dp[i+1][1]+P2-P1);
    }


    cout<<mx-1+min(dp[rows.size()-1][0],dp[rows.size()-1][1])<<endl;

//    cin.get(); cin.get();
    return 0;
}