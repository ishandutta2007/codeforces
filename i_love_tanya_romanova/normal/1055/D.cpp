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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

string st;
int n;
string a[N],b[N];

string FROM,TO;

string make_change(string old,int ps,string pat){
	for (int i=ps;i<ps+pat.size();i++){
		old[i]=pat[i-ps];
	}
	return old;
}

pair<int,int> P[N];

pair<int,int> get_worst(string a,string b){
	int fi=-1;
	int la=-1;
	for (int i=0;i<a.size();i++){
		if (a[i]!=b[i]){
			if (fi<0)
				fi=i;
			la=i;
		}
	}
	return make_pair(fi,la);
}

int get_prv(int id){
	if (P[id].first>0)
		return a[id][P[id].first-1];
	return N+id;
}

int get_nxt(int id){
	if (P[id].second+1<a[id].size())
		return a[id][P[id].second+1];
	return N+id;
}

int pi[N];

void prefix_function (const string& s) {
	int n = (int) s.length();
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
}

// b in a
int fnd(string a,string b){
	string Z=b+"#"+a;
	prefix_function(Z);
	/*for (int i=0;i<pi.size();i++){
		cout<<pi[i]<<" ";
	}
	cout<<endl;
*/
	for (int i=b.size()+1;i<Z.size();i++){
		if (pi[i]==b.size())
			return i-b.size()*2;
	}
	return -1;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	getline(cin,st);
	for (int i=1;i<=n;i++){
		getline(cin,a[i]);
	}
	for (int i=1;i<=n;i++){
		getline(cin,b[i]);
	}

	for (int i=1;i<=n;i++){
		P[i]=get_worst(a[i],b[i]);
	//	cout<<P[i].first<<"@"<<P[i].second<<endl;
	}

	for (int iter=1;iter<=3000;iter++){
		int c=-1;
		int all_same=1;
		for (int i=1;i<=n&&all_same==1;i++){
			if (P[i].first>=0){
				int prv=get_prv(i);
				if (prv>=N)
					all_same=0;
				if (c!=-1&&prv!=c)
					all_same=0;
				c=prv;
			}
		}
		if (all_same){
			for (int i=1;i<=n;i++){
				if (P[i].first>=0)
					--P[i].first;
			}
		}
	}

	for (int iter=1;iter<=3000;iter++){
		int c=-1;
		int all_same=1;
		for (int i=1;i<=n&&all_same==1;i++){
			if (P[i].second<a[i].size()&&P[i].second>=0)
			{
				int nxt=get_nxt(i);
				if (nxt>=N)
					all_same=0;
				if (c!=-1&&c!=nxt)
					all_same=0;
				c=nxt;
			}
		}
		if (all_same){
			for (int i=1;i<=n;i++){
				if (P[i].second>=0)
					++P[i].second;
			}
		}
	}

	int ok=1;

	int id=1;
	while (P[id].first<0)
		++id;

	for (int i=P[id].first;i<=P[id].second;i++){
		FROM+=a[id][i],
		TO+=b[id][i];
	}

	//cout<<FROM<<" "<<TO<<endl;

	for (int i=1;i<=n;i++){
		int ps=fnd(a[i],FROM);
		//cout<<ps<<"@"<<endl;
		if (ps!=-1){
			a[i]=make_change(a[i],ps,TO);
		}
		if (a[i]!=b[i])
			ok=0;
	}

	if (ok){
		cout<<"YES"<<endl;
		cout<<FROM<<endl;
		cout<<TO<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}