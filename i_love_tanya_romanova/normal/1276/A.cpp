/*
From the islands to the cities, from the ports into the sea.
We are strong, we will always be...
Blazing through the wreckage, burning all we see...
The life we lead, committed to be free...
Our union is a fortress!
Together we are bound.
A common bound in freedom, and in sound!!!
So raise your voices high!
For miles around to hear.
Let them know, we are drawing near...

In union we stand,
As they! blaze across the land!!!
In union, we make a final stand...

A peaceful co-existance, is droping out of sight.
So band together, together we will fight.
Blasting the resistance, marching to the top.
They started this, we say when it stops.
Strike fear within their hearts!
Strike down those in your way.
Let them know, that we live, today!!!
They throw us into flames,
Did not hear our cries.
But now, from the ashes we arise...
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

const int N = 200031;

string pref[10000];
int mov[20][500];
int dp[N][7];
pair<int,int> par[N][7];
int tests;
string st;
int n;
vector<int> ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    pref[0]="";
    pref[1]="o";
    pref[2]="on";
    pref[3]="t";
    pref[4]="tw";
    pref[5]="one";
    pref[6]="two";

    for (int i=0;i<5;i++){
    	for (int ad='a';ad<='z';ad++){
    		string temp=pref[i]+char(ad);
    		int new_t=-1;
    		while (new_t==-1){
    			for (int j=0;j<=6;j++){
    				if (temp==pref[j])
    					new_t=j;
    			}
    			if (new_t==-1)
    				temp.erase(temp.begin());
    		}
    		mov[i][ad]=new_t;
    	}
    }

    cin>>tests;
    for (;tests;--tests){
    	cin>>st;
    	n=st.size();
    	for (int i=0;i<=n;i++){
    		for (int j=0;j<=6;j++){
    			dp[i][j]=-1e9;
    		}
    	}
    	dp[0][0]=0;
    	for (int i=0;i<n;i++){
    		for (int cur_v=0;cur_v<=4;cur_v++){
    			// skip
    			if (dp[i+1][cur_v]<dp[i][cur_v]){
    				dp[i+1][cur_v]=dp[i][cur_v];
    				par[i+1][cur_v]=make_pair(cur_v,1);
    			}
    			// take
    			int new_v=mov[cur_v][st[i]];
    			if (dp[i+1][new_v]<=dp[i][cur_v]){
    				dp[i+1][new_v]=dp[i][cur_v]+1;
    				par[i+1][new_v]=make_pair(cur_v,0);
    			}
    		}
    	}

    	int best_v=0;
    	for (int i=0;i<5;i++){
    		if (dp[n][i]>dp[n][best_v])
    			best_v=i;
    	}

//    	cout<<best_v<<" "<<dp[n][best_v]<<endl;

    	ans.clear();
    	for (int i=n;i>=1;--i){
    		if (par[i][best_v].second==1)
    			ans.push_back(i);
    		best_v=par[i][best_v].first;
    	}
    	cout<<ans.size()<<endl;
    	for (int i=0;i<ans.size();i++){
    		if (i)
    			cout<<" ";
    		cout<<ans[i];
    	}
    	cout<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}