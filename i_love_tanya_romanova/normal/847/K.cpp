/*
(Jane, he's a freak)
(But so am I)
(And we'll always be freaks and we'll never be like other people)
(And you'll never be a freak 'cause you're just ... too perfect)

Late nights and bloodshot eyes,
Clock ticking half past five,
We're barely breathing but we're still alive. Go!

Our plans are all laid out,
Take all these unmarked roads,
We blaze the trails to places no one goes, yeah!

One last chance to go,
If I don't leave tonight I never will, let's go!
One last chance to go,
Let's take it now in for the kill

In time we find ourselves,
Back where we started from,
Too weak to fight and much too tired to run, yeah!

Before you swallow me
Into your perfect life,
I'm not going out without a fight

One last chance to go,
If I don't leave tonight I never will, let's go!
One last chance to go,
Let's take it now in for the kill

(If I had to leave tonight would you come with me?)
(What?)
(If I had to go to New York, and live, tonight, would you come with me?)

But this blueprint's faded grey
And here it seems like just yesterday
When we mapped out the details of our great escape,

But still these roads all beckon me
To uncover their mystery
But I fall like dead autumn leaves and let the jetstream carry me

One last chance to go,
If I don't leave tonight I never will, let's go!
One last chance to go
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

const int N = 100031;

int n,a,b,k,f;
string st1[N],st2[N];
int cost[N];

map<pair<string,string>,int> total_spending;
int total_money;

vector<int> order;
map<pair<string,string>,int>::iterator it;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>a>>b>>k>>f;
	for (int i=1;i<=n;i++)
	{
		cin>>st1[i]>>st2[i];
		if (st1[i]==st2[i-1])
			cost[i]=b;
		else
			cost[i]=a;
		pair<string,string> P=make_pair(st1[i],st2[i]);
		if(P.first>P.second)
			swap(P.first,P.second);
		total_spending[P]+=cost[i];
		total_money+=cost[i];
	}

	for (it=total_spending.begin();it!=total_spending.end();it++){
		int cost_here=(*it).second;
		order.push_back(cost_here);
	}
	sort(order.begin(),order.end());
	while (true){
		if (k==0||order.size()==0)
			break;
		if (order.back()<f)
			break;
		total_money+=f;
		total_money-=order.back();
		order.pop_back();
		--k;
	}
	cout<<total_money<<endl;

	cin.get(); cin.get();
	return 0;
}