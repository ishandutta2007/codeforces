/*
Yes, I understand that every life must end, uh-huh
As we sit alone, I know someday we must go, uh-huh
Oh I'm a lucky man, to count on both hands the ones I love
Some folks just have one, yeah, others, they've got none

Stay with me...
Let's just breathe...

Practiced are my sins, never gonna let me win, uh-huh
Under everything, just another human being, uh-huh
I don't wanna hurt, there's so much in this world to make me bleed

Stay with me
You're all I see...

Did I say that I need you?
Did I say that I want you?
Oh, if I didn't I'm a fool you see
No one knows this more than me

As I come clean...
I wonder everyday, as I look upon your face, uh-huh
Everything you gave
And nothing you would take, oh no

Nothing you would take
Everything you gave...

Did I say that I need you?
Oh, did I say that I want you?
Oh, if I didn't I'm a fool you see
No one knows this more than me
And I come clean, ah...

Nothing you would take
Everything you gave
Hold me 'til I die
Meet you on the other side...
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

const int N = 200031;

int n,m,color[N];
vector<int> g[N];
vector<int> gr[N];
int indeg[N];
vector<int> leaves[3];
int cnt_dead;
int ans;

void kill(int v){
	cnt_dead++;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		indeg[to]--;
		if (indeg[to]==0){
			leaves[color[to]].push_back(to);
		}
	}
}

void run_processor(){
	int v=leaves[0].back();
	leaves[0].pop_back();
	kill(v);
}

void run_coprocessor(){
	while (leaves[1].size()){
		int v=leaves[1].back();
		leaves[1].pop_back();
		kill(v);
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>color[i];
	}

	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		swap(a,b);
		g[a].push_back(b);
		gr[b].push_back(a);
		indeg[b]++;
	}

	for (int i=0;i<n;i++){
		if (indeg[i]==0)
			leaves[color[i]].push_back(i);
	}

	while (true){
		if (cnt_dead==n)
			break;
		if (leaves[0].size()>0){
			run_processor();
			continue;
		}
		run_coprocessor();
		++ans;
	}
	cout<<ans<<endl;


	cin.get(); cin.get();
	return 0;
}