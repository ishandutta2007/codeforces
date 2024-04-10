/*
Critical moments pass,
As doctrines of fools will last.
I am just trying to cope,
Into my horrorscope.
Through eyes and ears they bleed,
Reciting their holy creed.
Heeding but one request,
The future is put to rest...

Bless me in darkened days,
Down to my knees I pray.
I am just trying to cope
Within this horrorscope.
In the wake of all frustration,
I begin to lose control.

Watched as the weapons fired,
Bombs bursting in the air...
Burned in the fields of fire!
Standing in the middle of nowhere.
Watched as the weapons fired,
Baptized in fields of fire!

Well,
The change is here,
And the future clear.
I can feel it coming.
So full of hate,
It's getting late!
Yeah, I know it's coming.
When all the choice
Turned to just one voice,
Yeah, the wind is turning.

This is your horrorscope...

Words laced with blasphemy,
Drip with sincerity.
Falling into the plan,
Like sacrificial lambs.
Hearing the words and said,
Rings like nail to the head.
Now I can see the stars,
I know we have gone too far.

Watched as the weapons fired,
Bombs bursting in the air...
Baptized in fields of fire!
Watched as the weapons fired,

Well,
The change is here,
And the future clear.
I can feel it coming.
So full of hate,
It's getting late!
Yeah, I know it's coming.
When all the choice
Turned to just one voice,
Yeah, the wind is turning.

Well,
The change is here,
And the future clear.
I can feel it coming.
So full of hate,
It's getting late!
Yeah, I know it's coming.
When all the choice
Turned to just one voice,
Yeah, the wind is turning.

This is your horrorscope.
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

const int N = 500031;

int n;
int val;
vector<int> v;
vector<pair<int,int> > order;

vector<pair<int,int> > compress(vector<int> v){
	sort(v.begin(),v.end());
	vector<pair<int,int> > ret;
	int cnt=0;
	for (int i=0;i<v.size();i++){
		if (i>0&&v[i]!=v[i-1]){
			ret.push_back(make_pair(v[i-1],cnt));
			cnt=0;
		}
		cnt++;
	}
	ret.push_back(make_pair(v.back(),cnt));
	return ret;
}

bool cmp_second(pair<int,int>p1,pair<int,int> p2){
	if (p1.second!=p2.second)
		return p1.second<p2.second;
	return p1.first<p2.first;
}

int pref_sum[N];
int max_cols;
vector<vector<int> > ans;
vector<int> taken;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>val;
    	v.push_back(val);
    }

    order=compress(v);

    sort(order.begin(),order.end(),cmp_second);

    for (int i=0;i<order.size();i++){
    	pref_sum[i]=order[i].second;
    	if (i)
    		pref_sum[i]+=pref_sum[i-1];
    }

    int ptr=0;

    int max_area=0;
    int max_rows=0;

    for (int i=1;i<=n;i++){
    	while (ptr<order.size()&&order[ptr].second<=i)
    		++ptr;
    	long long can_use_here=(order.size()-ptr)*i;
    	if (ptr)
    		can_use_here+=pref_sum[ptr-1];
    	int cols_here=can_use_here/i;
    	int area_here=cols_here*i;
    	if (cols_here>=i&&area_here>max_area){
    		max_area=area_here;
    		max_rows=i;
    		max_cols=cols_here;
//    		cout<<i<<"@@"<<cols_here<<" "<<order.size()<<" "<<ptr<<endl;
    	}
    }

//    cout<<max_area<<" "<<max_rows<<" "<<max_cols<<endl;

    ans.resize(max_rows);
    for (int i=0;i<ans.size();i++){
    	ans[i].resize(max_cols);
    }

    /*for (int i=0;i<order.size();i++){
    	 cout<<order[i].first<<"@@"<<order[i].second<<" "<<max_rows<<endl;
    }*/


    for (int i=0;i<order.size();i++){
    	for (int j=0;j<min(order[i].second,max_rows);j++){
    		int value=order[i].first;
    		taken.push_back(value);
    	}
    }

    reverse(taken.begin(),taken.end());
//    cout<<taken.size()<<endl;

    ptr=0;
    for (int di=1;di<=max_cols;di++){
    	int qi=1;
    	int qj=di;
    	for (int i=1;i<=max_rows;i++){
    		ans[qi-1][qj-1]=taken[ptr];
    		++ptr;
    		qi++;
    		qj++;
    		while (qi>max_rows)
    			qi-=max_rows;
    		while (qj>max_cols)
    			qj-=max_cols;
    	}
    }

    cout<<max_rows*max_cols<<endl;
    cout<<max_rows<<" "<<max_cols<<endl;
    for (int i=0;i<max_rows;i++){
    	for (int j=0;j<max_cols;j++){
    		if (j)
    			cout<<" ";
    		cout<<ans[i][j];
    	}
    	cout<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}