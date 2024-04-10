/*
When I close my eyes tonight
Down my dreams the velvet raven flu
So I hold on

Whither goes the way I ride
In ihe moonlit ravens eye
Staring past the purple sky tonight

I'm holding on and I
Find out the only way goes down
And the weary drowns

Better hold on tight

Where leads this way I go
Velvet one I only know
Every raven craves a crimson stone

I'm holding on and I
Find out the only way goes down
And the weary drowns

Better hold on tight
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

const int N = 300031;

const int MAG = 25;

set<string> S[300][MAG+2];
set<string>::iterator it;

int m;

string pref[N],suf[N],st[N];
int n;

string get_pref(string st){
	while (st.size()>MAG)
		st.erase(st.end()-1);
	return st;
}

string get_suf(string st){
	while (st.size()>MAG)
		st.erase(st.begin());
	return st;
}

void run_merge(int a,int b,int to){
	for (int i=1;i<MAG;i++){
		for (it=S[a][i].begin();it!=S[a][i].end();it++){
			string here=(*it);
			S[to][i].insert(here);
		}
		for (it=S[b][i].begin();it!=S[b][i].end();it++){
			string here=(*it);
			S[to][i].insert(here);
		}
	}
}

void process_string(string st,int id){
	for (int i=0;i<st.size();i++)
	{
		string temp="";
		for (int j=i;j<st.size();j++){
			temp+=st[j];
			if (temp.size()>=MAG)
				break;
			S[id][temp.size()].insert(temp);
		}
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>st[i];
		pref[i]=get_pref(st[i]);
		suf[i]=get_suf(st[i]);
		process_string(st[i],i);
	}

	cin>>m;
	for (int i=n+1;i<=n+m;i++){
		int a,b;
		cin>>a>>b;
		run_merge(a,b,i);
		string here=suf[a]+pref[b];
		st[i]=here;
		process_string(st[i],i);

		pref[i]=pref[a]+pref[b];
		suf[i]=suf[a]+suf[b];
		pref[i]=get_pref(pref[i]);
		suf[i]=get_suf(suf[i]);
		int ans=1;
		//cout<<pref[i]<<" "<<suf[i]<<" "<<S[i][0].size()<<endl;

		while (S[i][ans].size()==(1ll<<ans))
			++ans;
		cout<<ans-1<<endl;
	}

	cin.get(); cin.get();
	return 0;
}