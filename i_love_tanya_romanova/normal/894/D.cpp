/*
You don't fool me
You don't fool me...
Da, da da da dah
Da da da dah
Da da dah...

You don't fool me - those pretty eyes
That sexy smile - you don't fool me
You don't rule me - you're no surprize
You're telling lies - you don't fool me
Mmm, mama said be careful of that girl
Mama said you know that she's no good
Mama said be cool, don't you be no fool
Yup bup ba ba ba ba da da da dah!
You don't fool me
You don't fool me, you don't fool me
She'll take you
You don't fool me, and break you
You don't rule me, you don't fool me
You don't fool me, she'll take you
You don't fool me, and break you
Sooner or later you'll be playing by her rules

Baby you don't fool me, yeah
You don't fool me, you don't have to say 'don't mind'
You don't have to teach me things I know
Sooner or later you'll be playing by her rules
Oh, (fool you) oh, (rule you) she'll take you (take you)
And break you (break you)
Yeah

Mama said be cool
Mama said she'll take you for a fool
She'll take you, and break you
Ba ba ba ba bap bap ba baah
La la la la la lah
You don't fool me
You don't fool me...
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

const int N = 1100031;

int n,m;
vector<pair<int,int> > g[N];

vector<pair<int,int> > sons[N];
vector<long long> pref_sum[N];

int dep[N];

vector<pair<int,int> > SONS;

void dfs(int v,int d){
	SONS.push_back(make_pair(d,v));
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i].first;
		int new_dep=d+g[v][i].second;
		dfs(to,new_dep);
	}
}

int par_le[N];

int A,H;

long long make_query(int v,long long rem_h){
	int b_val=rem_h+dep[v];
	int ps=lower_bound(sons[v].begin(),sons[v].end(),make_pair(b_val,-1))-sons[v].begin();
	long long ts=pref_sum[v][ps];
	return 1ll*ps*b_val-ts;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<n;i++){
		int le;
//		cin>>le;
		scanf("%d",&le);
		g[(i+1)/2].push_back(make_pair(i+1,le));
		par_le[i+1]=le;
		dep[i+1]=dep[(i+1)/2]+le;
	}

	for (int i=1;i<=n;i++){
		SONS.clear();
		dfs(i,dep[i]);
		sort(SONS.begin(),SONS.end());
		sons[i]=SONS;
		pref_sum[i].push_back(0);
		long long s=0;
		for (int j=0;j<sons[i].size();j++){
			s+=sons[i][j].first;
			pref_sum[i].push_back(s);
		}
	}

	for (;m;--m){
//		cin>>A>>H;
		scanf("%d",&A);
		scanf("%d",&H);
		long long ans=make_query(A,H);
		while (A!=1&&H>0){
			H-=par_le[A];
			if (H<0)
				break;
			int memo=A;
			A/=2;
			ans+=H;
		//	cout<<ans<<"@"<<" "<<endl;
			if ((memo^1)<=n){
				int remains=H-par_le[memo^1];
				ans+=make_query(memo^1,remains);
			}
		}
		printf("%lld\n",ans);
//		cout<<ans<<"\n";
	}

//	cin.get(); cin.get();
	return 0;
}