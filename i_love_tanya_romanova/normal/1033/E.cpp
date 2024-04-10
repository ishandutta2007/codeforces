/*
My conviction is stronger today
As I fight to uncover your sacred lie
And the fear isn't going away
As the soldiers still die
Let your followers know their lives have been sold
For the good of your sacred lie
For the truth to be told
And the plan to unfold
We must start asking why

Don't you know the war is far from over now
What a stumbling block we've fallen over now
As our brothers die defending no one
The war is far from over now

Liberation, a moral charade
For the cause is a part of your sacred lie
Damnation a moment away in all the world's eyes
It's the doom of us all
We give in to control for the sake of your sacred lie
Complications abound
You'll get used to the sound of alarms in your life

Don't you know the war is far from over now
What a stumbling block we've fallen over now
As our brothers die defending no one
The war is far from over now

Give us a moment of peace in our lifetime [x7]
Give us a moment of peace right now

[x2]
Don't you know the war is far from over now
What a stumbling block we've fallen over now
As our brothers die defending no one
The war is far from over now
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

string S="adskfhasgdiqwietoqwetiqwoiehtslkgaklsghasdjglhasdjgahlsdjghalsdkjgnaskjlbnskjghaskjldghajskldghaskljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewoqiuewthtakljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewkljdghalksdjghakljsdghajlksdghalkjsdghaljksdghasldjkgadslajsdghlaewgadslajsdghlaewsdkjlghalsdkg"
;
const int N = 600031;

vector<int> g[N];
int used[N];
int n;
vector<int> cmp[5];

vector<int> get_unused(){
	vector<int> ret;
	for (int i=1;i<=n;i++){
		if (used[i])
			continue;
		ret.push_back(i);
	}
	return ret;
}

int GENERATED=1;

int AR[50][50];

void ADD(int a,int b){
	AR[a][b]=AR[b][a]=1;
}

int COUNT(vector<int> v){
	int ret=0;
	for (int i=0;i<v.size();i++){
		for (int j=i+1;j<v.size();j++){
			if (AR[v[i]][v[j]])
				++ret;
		}
	}
	return ret;
}

int CALLS=0;

int query_for_vector(vector<int> v){
	++CALLS;

	if (v.size()==0)
		return 0;

	if (CALLS==19995)
		while (true);

	cout<<"? "<<v.size()<<endl;
	for (int i=0;i<v.size();i++){
		if (i)
			cout<<" ";
		cout<<v[i];
	}
	cout<<endl;
	int ret;
	if (GENERATED){
		ret=COUNT(v);
	}
	else
		cin>>ret;
	return ret;
}

int count_adjacent(int v,vector<int> to){
	int without=query_for_vector(to);
	to.push_back(v);
	int with=query_for_vector(to);
	return (with-without);
}

int get_adjacent(int v,vector<int> to){
	if (to.size()==1)
		return to[0];
	vector<int> v1,v2;
	for (int i=0;i<to.size();i++){
		if (i%2==0)
			v1.push_back(to[i]);
		else
			v2.push_back(to[i]);
	}
	if (count_adjacent(v,v1)>0)
		return get_adjacent(v,v1);
	else
		return get_adjacent(v,v2);
}

void dfs(int v,int clr){
	used[v]=clr;
	while (true){
	vector<int> unused=get_unused();
		if (unused.size()==0)
			return;
		int cnt_edges=count_adjacent(v,unused);
		if (cnt_edges==0)
			return;
		int to=get_adjacent(v,unused);
		g[v].push_back(to);
		g[to].push_back(v);
		dfs(to,3-clr);
	}
}

pair<int,int> find_edge(vector<int> v){
	if (v.size()==2)
		return make_pair(v[0],v[1]);
	while (true){
		random_shuffle(v.begin(),v.end());
		int to_take=max((int)v.size()/2,2);
		vector<int> temp;
		for (int i=0;i<to_take;i++){
			temp.push_back(v[i]);
		}
		if (query_for_vector(temp)>0)
			return find_edge(temp);
	}
	return make_pair(-1,-1);
}

int p[N];
int cycle_start,cycle_end;

bool trace(int v,int par){
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (to==par)
			continue;
		if (used[to]==0){
			p[to]=v;
			if (trace(to,v))
				return true;
		}
		else if (used[to]==1){
			cycle_start=to;
			cycle_end=v;
			return true;
		}
	}
	used[v]=2;
	return false;
}

vector<int> find_cycle(){
	vector<int> cycle;
	for (int i=1;i<=n;i++){
		used[i]=0;
	}
	for (int i=1;i<=n;i++){
		if (trace(i,i))
			break;
	}

	if (cycle_start==0)
		throw 1;

	cycle.push_back(cycle_start);
	for (int v=cycle_end;v!=cycle_start;v=p[v]){
		cycle.push_back(v);
	}
	return cycle;
}

int get_hash(string st){
	long long res=0;
	for (int i=0;i<st.size();i++){
		res=res*173+st[i];
		res%=bs;
	}
	return res;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	srand(get_hash(S));

	/*ADD(1,2);
	ADD(1,4);
	ADD(2,3);
	//ADD(3,4);
	ADD(4,6);
	ADD(3,6);
	n=6;
*/
	GENERATED=0;

	if (GENERATED==0)
		cin>>n;

	for (int i=1;i<=n;i++){
		if (used[i])
			continue;
		dfs(i,1);
	}

	for (int i=1;i<=n;i++){
		cmp[used[i]].push_back(i);
	}

	int A=query_for_vector(cmp[1]);
	int B=query_for_vector(cmp[2]);

	if (A==0&&B==0){
		cout<<"Y"<<" "<<cmp[1].size()<<endl;
		for (int j=0;j<cmp[1].size();j++){
			if (j)
				cout<<" ";
			cout<<cmp[1][j];
		}
		cout<<endl;
		return 0;
	}

	pair<int,int> p;

	if (A!=0){
		p=find_edge(cmp[1]);
	}
	else
	{
		p=find_edge(cmp[2]);
	}

	g[p.first].push_back(p.second);
	g[p.second].push_back(p.first);

	vector<int> V=find_cycle();

	cout<<"N "<<V.size()<<endl;
	for (int i=0;i<V.size();i++){
		if (i)
			cout<<" ";
		cout<<V[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}