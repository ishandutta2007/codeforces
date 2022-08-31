/*
It's the same in every country
When you say you're leaving
Left behind the loved ones
Waiting silent in the hall
Where you're going lies adventure
others only dream of
Red and green light this is real
and so you go to war

For the passion, for the glory
For the memories, for the money
You're a soldier, for your country
What's the difference, all the same

Far away from the land of our birth
We fly a flag in some foreign earth
We sailed away like our fathers before
These colours don't run, from a cold bloody war

Here is no one that will save you
Going down in flames
No surrender certain death
You look it in the eye
On the shores of tyranny you

Crashed the human wave
Paying for my freedom with your
Lonely unmarked graves

For the passion, for the glory
For the memories, for the money
You're a soldier, for your country
What's the difference, all the same

Far away from the land of our birth
We fly a flag in some foreign earth
We sailed away like our fathers before
These colours don't run, from a cold bloody war
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

const int N = 600000;

int n;
int A[N],B[N],val[N];
int cnt[100][100];
vector<int> entries[100][100];

int ans;

vector<int> order;

int USED[20][20];

bool can_move(int a,int b){
	if (cnt[a][b]<=USED[a][b])
		return false;
	if (USED[a][b]==2)
		return false;
	if (a==b)
		return false;
	return true;
}

int used[100];
int used_edge[20][20];

int eval(vector<int> v,int how_much,int for_sure){
	int res=0;
	sort(v.begin(),v.end());
	while (for_sure){
		res+=v.back();
		v.pop_back();
		--for_sure;
	}
	reverse(v.begin(),v.end());
	for (int i=0;i<how_much;i++){
		res+=v[i];
	}
	return res;
}

void SOLVER(){
	for (int i=1;i<=4;i++){
		used[i]=0;
	}
	for (int i=0;i<order.size();i++){
		used[order[i]]=1;
	}

	int here=0;
	for (int i=1;i<=4;i++){
		if (used[i]==0)
			continue;
		for (int j=i;j<=4;j++){
			int thold=0;
			thold=entries[i][j].size()-USED[i][j];
			if (thold%2==1&&i!=j)
				--thold;
			//cout<<i<<"@@@"<<j<<" "<<entries[i][j].size()<<" "<<thold<<" "<<USED[i][j]<<endl;
			//if (entries[i][j].size())
			//	cout<<entries[i][j][0]<<" "<<eval(entries[i][j],thold,USED[i][j])<<endl;
			here+=eval(entries[i][j],thold,USED[i][j]);
			//cout<<"!!!"<<here<<endl;
		}
	}

	/*for (int i=0;i<order.size();i++){
		cout<<order[i]<<" ";
	}
	cout<<endl<<here<<endl;
	for (int i=1;i<=4;i++){
		for (int j=1;j<=4;j++){
			cout<<USED[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	ans=max(ans,here);
}

void dfs(int v){

	SOLVER();

	for (int i=1;i<=4;i++){
		if (can_move(v,i)==0)
			continue;
		USED[v][i]++;
		USED[i][v]++;
		order.push_back(i);
		dfs(i);
		order.pop_back();
		USED[v][i]--;
		USED[i][v]--;
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>A[i]>>val[i]>>B[i];
		cnt[A[i]][B[i]]++;
		if (A[i]!=B[i])cnt[B[i]][A[i]]++;
		entries[A[i]][B[i]].push_back(val[i]);
		if (A[i]!=B[i])entries[B[i]][A[i]].push_back(val[i]);
	}

	for (int i=1;i<=4;i++){
		for (int j=1;j<=4;j++){
			sort(entries[i][j].begin(),entries[i][j].end());
		}
	}

	ans=0;

	for (int i=1;i<=4;i++){
		order.push_back(i);
		dfs(i);
		order.pop_back();
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}