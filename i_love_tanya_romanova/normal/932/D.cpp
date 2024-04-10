/*
You tried to spit in the eye
Of a dead man's face
Attacked the ways of a man
Not yet in his grave
But your hate was over all too soon
Because nothing is over
And nothing's through,
Till we bury you

For the love of brother
I will sing this fucking song
Aesthetics of hate,
I hope you burn in hell

The words I read on the screen
Left me fucking sick
I felt the hatred rising
You son of a bitch
You branded us pathetic for our respect
But he made us Driven,
Such deep reverence,
Far beyond the rest

For the love of brother
I will sing these fucking words
Aesthetics of hate,
I hope you burn in hell

Yer!

Wow!
Long live memories
Live this freedom vicariously
Defend tenfold
His honor we'll always uphold

For the love of brother
I will say these fucking words
No silence against ignorance
Iconoclast, I hope you burn in hell

May the hand of god strike them down
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

long long up[N][21];
int tests;
long long total_w[N][21];
long long DEP_vertices[N];
long long DEP_weight[N];

// weight not including vertex
long long query_by_weight(long long w_id,long long min_allowed){
	for (int i=20;i>=0;--i){
		long long to=up[w_id][i];
		if (DEP_weight[to]-total_w[to][0]>=min_allowed&&to>0)
			w_id=to;
	}
	return w_id;
}

long long query_last_ligher(long long root,long long thold){
	for (int i=20;i>=0;--i){
		long long to=up[root][i];
		if (total_w[to][0]<thold&&to>0)
			root=to;
	}
	return root;
}

void link(long long v,long long to,long long own_w){
	DEP_vertices[v]=DEP_vertices[to]+1;
	DEP_weight[v]=DEP_weight[to]+own_w;
	total_w[v][0]=own_w;
	up[v][0]=to;
	for (int i=1;i<=20;i++){
		total_w[v][i]=total_w[v][i-1]+total_w[up[v][i-1]][i-1];
		up[v][i]=up[up[v][i-1]][i-1];
	}
}
int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	scanf("%d",&tests);

	long long cnt=1;
	long long last=0;

	link(1,0,0);

	for (;tests;--tests){
		long long tp;
		scanf("%lld",&tp);
		if (tp==1){ // add vertex
			long long root,w;
			scanf("%lld",&root);
			root^=last;
			scanf("%lld",&w);
			w^=last;
			//cout<<root<<"@"<<w<<" "<<cnt+1<<endl;

			long long Q=query_last_ligher(root,w);
			//cout<<root<<"@@@"<<w<<" "<<up[Q][0]<<" "<<Q<<endl;

			if (total_w[Q][0]<w)
				Q=up[Q][0];
			link(cnt+1,Q,w);
			++cnt;
		}
		else{
			long long root,X;
			scanf("%lld",&root);
			scanf("%lld",&X);
			root^=last;
			X^=last;
			//cout<<"@"<<root<<" "<<total_w[root][0]<<" "<<up[root][0]<<" "<<total_w[up[root][0]][0]<<endl;

			long long my_dep=DEP_vertices[root];
			//cout<<DEP_vertices[root]<<" "<<root<<"@"<<endl;
			long long my_weight=DEP_weight[root];
//			cout<<my_weight<<endl;
			long long weight_treshold=my_weight-X;
			long long last_in_path=query_by_weight(root,weight_treshold);
			long long ans=DEP_vertices[root]-DEP_vertices[last_in_path]+1;
			//cout<<"@"<<X<<" "<<total_w[root][0]<<" "<<root<<" "<<last_in_path<<endl;
			if (total_w[root][0]>X)
				ans=0;
			last=ans;
			//cout<<"@@@"<<endl;
			printf("%lld\n",ans);
		}
	}

//	cin.get(); cin.get();
	return 0;
}