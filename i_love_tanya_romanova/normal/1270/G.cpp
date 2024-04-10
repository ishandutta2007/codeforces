/*
When the winged hussars arrive

A cry for help in time of need, await relief from holy league
60 days of siege, outnumbered and weak
Sent a message to the sky, wounded soldiers left to die
Will they hold the wall or will the city fall

Dedication
Dedication
They're outnumbered 15 to one
And the battle's begun

Then the winged hussars arrive
Coming down the mountainside
Then the winged hussars arrive
Coming down they turn the tide

As the days are passing by and as the dead are piling high
No escape and no salvation
Trenches to explosive halls are buried deep beneath the walls
Plant the charges there and watch the city fear

Desperation
Desperation
It's a desperate race against the mine
And a race against time

Cannonballs are coming down from the sky
Janissaries are you ready to die?
We will seek our vengeance eye for an eye

You'll be stopped upon the steps of our gate
On this field you're only facing our hate
But back home the sultan's sealing your fate

We remember
In September
That's the night Vienna was freed
We made the enemy bleed!

Storm clouds, fire and steel
Death from above make their enemy kneel

Fighting, power and grace
Death from above it's an army of wings

We remember, in September,
When the winged hussars arrive
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int n,ar[N];
int tests;
vector<pair<int,int> > order;
vector<pair<long long, long long> > prefixes;
long long ps;
vector<pair<int,int> > pos_map,neg_map;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0);
 //   cin.tie(0);

	srand(time(NULL));

    cin>>tests;
    for (;tests;--tests){
//    	cin>>n;
    	scanf("%d",&n);
    	for (int i=1;i<=n;i++){
//    		cin>>ar[i];
    		scanf("%d",&ar[i]);
    	}

    	if (n<=5){
    		int ans_mask=-1;
    		for (int mask=1;mask<(1<<n);mask++){
    			int S=0;
    			for (int i=0;i<n;i++){
    				if (mask&(1<<i))
    					S+=ar[i+1];
    			}
    			if (S==0)
    				ans_mask=mask;
    		}
    		vector<int> ans;
    		for (int i=0;i<n;i++){
    			if (ans_mask&(1<<i))
    				ans.push_back(i+1);
    		}
    		printf("%d\n",ans.size());
    		for (int i=0;i<ans.size();i++){
    			if (i)
    				printf(" ");
    			printf("%d",ans[i]);
    		}
    		printf("\n");
    		continue;
    	}

    	pair<int,int> pair_solution=make_pair(-1,-1);

    	neg_map.clear();
    	pos_map.clear();
    	for (int i=1;i<=n;i++){
    		if (ar[i]<0){
    			neg_map.push_back(make_pair(ar[i],i));
    		}
    		if (ar[i]>0)
    		{
    			pos_map.push_back(make_pair(ar[i],i));
    		}
    	}
    	sort(neg_map.begin(),neg_map.end());
    	sort(pos_map.begin(),pos_map.end());


    	for (int i=1;i<=n;i++){
    		if (ar[i]>0){
    			int id=lower_bound(neg_map.begin(),neg_map.end(),make_pair(-ar[i],-1))-neg_map.begin();
    			if (id<neg_map.size()&&neg_map[id].first==-ar[i]){
    				pair_solution=make_pair(i,neg_map[id].second);
    				break;
    			}
    		}
    	}

    	if (pair_solution.first!=-1){
    		printf("2\n");
    		printf("%d %d\n",pair_solution.first,pair_solution.second);
    		continue;
    	}

    	order.clear();
    	for (int i=1;i<=n;i++){
    		order.push_back(make_pair(ar[i],i));
    	}

    	while (true){
    		int al,ar;
    		al=ar=-1;
    		random_shuffle(order.begin(),order.end());
    		prefixes.clear();
    		ps=0;
    		prefixes.push_back(make_pair(0,0));
    		for (int i=0;i<n;i++){
    			ps+=order[i].first;
    			prefixes.push_back(make_pair(ps,i+1));
    		}
    		sort(prefixes.begin(),prefixes.end());
    		for (int i=1;i<prefixes.size();i++){
    			if (prefixes[i].first==prefixes[i-1].first){
    				al=prefixes[i].second;
    				ar=prefixes[i-1].second;
    				if (al>ar)
    					swap(al,ar);
    				break;
    			}
    		}
    		if (al==-1)
    			continue;

    		printf("%d\n",ar-al);
    		for (int i=al;i<ar;i++){
    			if (i>al)
    				printf(" ");
    			printf("%d",order[i].second);
    		}
    		printf("\n");
    		break;
    	}
    }

    //    cin.get(); cin.get();
    return 0;
}