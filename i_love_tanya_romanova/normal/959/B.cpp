/*
Waiting for the day to end
As silence came too late
I turn my eyes inside
Close the lids
Deny the world to enter

'Cause I'm turning the desires down
Again rose the monstrous of hours in between
I taint the thought
The trauma born inside
All the thoughts that you defined
Tread the light again
Take the pain away
It feels as though time as tears
Never seem to end

'Cause I'm turning the desires down
Again rose the monstrous of hours in between
I taint the thought
The trauma born inside
Oh, inside
Oh, inside
Oh, inside

As I hold you in I try to make sure
These treasures that I hide
These treasures that I hide

'Cause I'm turning the desires down
Again rose the monstrous of hours in between
I taint the thought
The trauma born inside

'Cause I'm turning the desires down
Again rose the monstrous of hours in between
Taint the thought
The trauma born inside
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

int n,k,m;
map<string,int> maps;
string word[N];
int cost[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>k>>m;

	for (int i=1;i<=n;i++)
	{
		cin>>word[i];
		maps[word[i]]=i;
	}
	for (int i=1;i<=n;i++){
		cin>>cost[i];
	}

	for (int i=1;i<=k;i++){
		int cnt;
		cin>>cnt;
		int lowest=1e9;
		vector<int> id_list;
		for (int j=1;j<=cnt;j++){
			int id;
			cin>>id;
			id_list.push_back(id);
			lowest=min(lowest,cost[id]);
		}
		for (int j=0;j<id_list.size();j++){
			int ps=id_list[j];
			cost[ps]=lowest;
		}
	}

	long long ans=0;
	for(int i=1;i<=m;i++){
		string temp;
		cin>>temp;
		ans+=cost[maps[temp]];
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}