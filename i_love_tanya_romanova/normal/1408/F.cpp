/*
He had an unfamiliar face
Complete life in disarray
A simple man, power drunk
No worries of living, no more anything

Deep inside I've seen it rise
Actions progress to no end
Mirror, mirror please look inside
Do you see the reasons that we sin

Not one to be forgot
Spoiled rotten, so they say
Once burned, forever marked
Hurt by just a few but so many have to pay

Pressure coming down
Down on me, gonna break
Broken fingernails
Digging in, scratch my face

Nervous, like a cat
Gonna jump through my skin
Shadows on the wall
Stretching out, grope for me

Reasons, deep in me
Let me be
Let me bleed
Set me free
The reasons that we sin
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 200031;

int n,ptr;

vector<pair<int,int> > ans;

vector<int> generate_block(int levels){
	vector<int> cur;
	for (int i=0;i<(1<<levels);i++){
		cur.push_back(ptr);
		++ptr;
	}
	for (int lev=0;lev<levels;lev++){
		for (int i=0;i<cur.size();i++){
			if (!(i&(1<<lev)))
				ans.push_back(make_pair(cur[i],cur[i+(1<<lev)]));
		}
	}
	return cur;
}

vector<vector<int> > blocks;

void doubling_strategy(){
	vector<int> tail;
	tail=blocks.back();
	blocks.pop_back();
	vector<int> othr;
	for (int i=0;i<tail.size();i++){
		othr.push_back(blocks[0].back());
		blocks[0].pop_back();
	}
	for (int i=0;i<tail.size();i++){
		ans.push_back(make_pair(tail[i],othr[i]));
	}
	for (int i=0;i<othr.size();i++){
		tail.push_back(othr[i]);
	}
	blocks.push_back(tail);
}

void merge_tail(){
	vector<int> v1=blocks[blocks.size()-1];
	vector<int> v2=blocks[blocks.size()-2];
	blocks.pop_back();
	blocks.pop_back();
	for (int i=0;i<v1.size();i++){
		ans.push_back(make_pair(v1[i],v2[i]));
	}
	for (int i=0;i<v2.size();i++){
		v1.push_back(v2[i]);
	}
	blocks.push_back(v1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;

    ptr=1;
    for (int i=15;i>=0;--i){
    	if (n&(1<<i))
    	{
    		vector<int> v=generate_block(i);
    		blocks.push_back(v);
    	}
    }
    //cout<<"@@"<<endl;

    while (blocks.size()>2){
    	while (blocks[blocks.size()-2].size()!=blocks[blocks.size()-1].size()){
    		doubling_strategy();
    	}
    	merge_tail();
    }

    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++){
    	printf("%d %d\n",ans[i].first,ans[i].second);
//    	cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }

    //cin.get(); cin.get();
    return 0;
}