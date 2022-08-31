/*
Flat on my back
In a lonely sprawl
I stare at the ceiling
Because i can not fall
Asleep tonight
No not at all
Head lights flash
Across my bedroom wall
Crying eyes open
Because i can not fall
In love with you
No not at all

Walk away and taste the pain
Come again some other day
Aren't you glad you weren't afraid
Funny how the price gets paid

Busted in two
Like a brittle stick
I can not drink
Because my throat constricts
Lovesick from you
That will never do
Open my mouth
I couldn't make a sound
I could not scream
I could not shout
It out to you
Nothing to do

Walk away and taste the pain
Come again some other day
Aren't you glad you weren't afraid
Funny how the price gets paid

This may come as a shocking surprise
I have to take a walk
I have to kiss it goodbye
Goodbye my love
Goodbye my love
I am not alive

Walk away and taste the pain
Come again some other day
Aren't you glad you weren't afraid
Funny how the price gets paid
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 70031;

int n;
string st[N];
vector<string> list_of_names[N];
int in_V[N*46];
int son[N*46][10];
string ans[N];

int C;

vector<string> get_subs(string st){
	vector<string> ret;
	for (int i=0;i<st.size();i++)
	{
		string temp="";
		for (int j=i;j<st.size();j++)
		{
			temp+=st[j];
			ret.push_back(temp);
		}
	}
	sort(ret.begin(),ret.end());
	vector<string> v2;
	for (int i=0;i<ret.size();i++)
	{
		if (i==0||ret[i]!=ret[i-1])
			v2.push_back(ret[i]);
	}
	return v2;
}

int add_vertex(){
	++C;
	return C;
}

int add_name(string st){
	int cur=0;
	for (int i=0;i<st.size();i++)
	{
		int here=st[i]-'0';
		if (son[cur][here]==0){
			son[cur][here]=add_vertex();
		}
		cur=son[cur][here];
	}
	return cur;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>st[i];
		list_of_names[i]=get_subs(st[i]);
		for (int j=0;j<list_of_names[i].size();j++)
		{
			int V=add_name(list_of_names[i][j]);
			in_V[V]++;
		}
	}

	for (int i=1;i<=n;i++){
		ans[i]=st[i];
		for (int j=0;j<list_of_names[i].size();j++)
		{
			if (list_of_names[i][j].size()>=ans[i].size())
				continue;
			int V=add_name(list_of_names[i][j]);
			if (in_V[V]==1)
				ans[i]=list_of_names[i][j];
		}
		cout<<ans[i]<<"\n";
	}

	cin.get(); cin.get();
	return 0;
}