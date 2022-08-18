/*
Torn from home, sent down death's railroad, are we
When we wake up tomorrow
Will we still be wearing this curse?
Will we wake up tomorrow?
Which punishment is worse?

Day one: no sun
Stripped of our names
Now we are merely numbers
Permanently inked in the flames

Our kind - our existence lights the fire
Igniting hell on earth
Archangels bending crosses, hooked

Innocent men, women, children
Sentenced before conviction
With golden stars to guide them
Their gavel is the end of a gun

Day two: lived through
More culprits arrive
Every cage so crowded
How will we survive through the night?

Our kind - our existence lights the fire
Igniting hell on earth
Archangels bending crosses, hooked

First day in hell

First day in hell
See the terror in abandoned gates...
Fear sunken eyes
Get the guards and walk a dozen paces, saturnine

Incarcerated without reason
Doomend by blood
Anti-venom for a poisoned nation
Our birth right

Week five: alive
Soon out of time
After all that I've, here, witnessed
There's no value in life

Our kind - our existence lights the fire
Igniting hell on earth
Archangels bending crosses, hooked

First day in hell
First week in hell
See the terror in abandoned gates
Fear sunken eyes
Get the guards and walk a dozen paces, saturnine

First month in hell
Incarcerated without reason
Doomend by blood
Anti-venom for a poisoned nation
Our birth right

Last day in hell
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

const int N = 510031;

int n,m;
vector<int> g[N];
int cut[N],R[N];

long long SR[N];
int tests;
vector<int> qu_list[N];
vector<int> updates[N];

pair<long long, long long> t[N*4];
int test_l[N],test_r[N];
long long ans[N];
long long SumProg[N];

pair<long long, long long> combine(pair<long long, long long> p1,pair<long long, long long> p2){
	p1.first+=p2.first;
	p1.second+=p2.second;
	return p1;
}

void add(int v,int tl,int tr,int ps,int val){
	if (tl==tr){
		t[v].first+=1;
		t[v].second+=val;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		add(v*2,tl,tm,ps,val);
	else
		add(v*2+1,tm+1,tr,ps,val);
	t[v]=combine(t[v*2],t[v*2+1]);
}

pair<long long, long long> get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return make_pair(0,0);
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return combine(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

int used[N];

vector<int> cycle;
int par[N];

void restore_cycle(int v,int start){
	cycle.clear();
	while (v!=start){
		cycle.push_back(v);
		v=par[v];
	//	cout<<v<<" "<<start<<" "<<par[v]<<endl;
	//	cin.get();
	}
	//cout<<"@"<<endl;
	cycle.push_back(start);
	sort(cycle.begin(),cycle.end());
	/*for (int j=0;j<cycle.size();j++){
		cout<<cycle[j]<<" ";
	}
	cout<<endl;
*/
	R[cycle[0]]=min(R[cycle[0]],cycle.back()-1);

}

void dfs(int v,int p=-1){
	used[v]=1;
//	cout<<v<<endl;
//	cout<<v<<"@"<<p<<endl;

	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		//cout<<v<<"@"<<to<<" "<<p<<endl;
		if (to==p||used[to]==2)
			continue;
		if (used[to]){
			restore_cycle(v,to);
			continue;
		}
		//cout<<"!!!"<<endl;
		par[to]=v;
		dfs(to,v);
	}
	used[v]=2;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		SumProg[i]=SumProg[i-1]+i-1;
	}

	for (int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i=1;i<=n;i++){
		R[i]=n;
	}

	for (int i=1;i<=n;i++){
		if (used[i])
			continue;
		dfs(i);
	}

	for (int i=n-1;i>=1;i--){
		R[i]=min(R[i],R[i+1]);
	}

	/*for (int i=1;i<=n;i++){
		cout<<R[i]<<" ";
	}
	cout<<endl;;
*/
	for (int i=1;i<=n;i++){
		updates[R[i]].push_back(i);
		SR[i]=SR[i-1]+R[i];
	}

	/*for (int i=1;i<=n;i++){
		cout<<i<<" "<<R[i]<<endl;
	}*/

	cin>>tests;
	for (int test=1;test<=tests;test++){
		cin>>test_l[test]>>test_r[test];
		qu_list[test_r[test]].push_back(test);
	}

	for (int i=n;i>=1;--i){
		// make updates
		for (int j=0;j<updates[i].size();j++){
			int ps=updates[i][j];
			add(1,1,n,ps,i);
			//cout<<ps<<"@"<<i<<endl;
		}
		for (int j=0;j<qu_list[i].size();j++){
			int test=qu_list[i][j];
			long long res=SR[test_r[test]]-SR[test_l[test]-1];
			res-=SumProg[test_r[test]]-SumProg[test_l[test]-1];
//			cout<<test<<"@"<<res<<endl;
			// subtract bad now
			pair<long long, long long> p=get(1,1,n,test_l[test],test_r[test]);
			res-=p.second;
			res+=p.first*test_r[test];
			ans[test]=res;
		}
	}

	for (int i=1;i<=tests;i++){
		cout<<ans[i]<<"\n";
	}

	cin.get(); cin.get();
	return 0;
}