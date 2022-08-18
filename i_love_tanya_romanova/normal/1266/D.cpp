/*
Blood sugar sucker fish
In my dish
How many pieces
Do you wish
Step into a heaven
Where I keep it on the soul side
Girl please me
Be my soul bride
Every women
Has a piece of aphrodite
Copulate to create
A state of sexual light
Kissing her virginity
My affinity
I mingle with the gods
I mingle with divinity
 
Blood sugar baby
She's magik
Sex magik sex magik
 
Glorious euphoria
Is my must
Erotic shock
Is a function of lust
Temporarily blind
Dimensions to discover
In time
Each into the other
Uncontrollable notes
From her snowwhite throat
Fill a space
In which two bodies float
Operatic by voice
A fanatic by choice
Aromatic is the flower
She must be moist
 
Blood sugar baby
She's magik
Sex magik sex magik
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
 
int n,m;
long long balance[N];
vector<pair<pair<int,int>,long long> > ans;
vector<pair<long long, long long> > positive,negative;
 
int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);
 
    cin>>n>>m;
    for (int i=1;i<=m;i++){
    	int a,b,am;
    	cin>>a>>b>>am;
    	balance[a]+=am;
    	balance[b]-=am;
    }
 
    for (int i=1;i<=n;i++){
    	if (balance[i]>0){
    		positive.push_back(make_pair(i,balance[i]));
    	}
    	else
    	{
    		negative.push_back(make_pair(i,-balance[i]));
    	}
    }
 
    while (positive.size()>0&&negative.size()>0){
    	long long am1=positive.back().second;
    	long long am2=negative.back().second;
    	long long am=min(am1,am2);
    	int id1=positive.back().first;
    	int id2=negative.back().first;
    	if (am)
    	 ans.push_back(make_pair(make_pair(id1,id2),am));
    	positive[positive.size()-1].second-=am;
    	negative[negative.size()-1].second-=am;
    	while (positive.back().second==0)
    		positive.pop_back();
    	while (negative.back().second==0)
    		negative.pop_back();
    }
 
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++){
    	cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<"\n";
    }
 
    //    cin.get(); cin.get();
    return 0;
}