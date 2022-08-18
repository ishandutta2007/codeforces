/*
I could not breath against the wall
The clash of light against the floor
They held me up against the wall
Too young to be ignored

Standing by a building
Leaks out information
Passive death of freedom gets me
Where's my security
Behind my back it goes
Early morning's coming
The risk that I am taking
Recall a song that I heard as a child
No more false immunity
Inside the blistering cold

My youth unknown to me
I'm walking by a wire
What's left from me to breathe
Cold smell of fire
One day I will be free
I was born to be no one
My youth unknown to me
I walked behind the sun

Emptiness within me
Exit signs within me
The one you're looking for is not here
Had no security
He will not come back
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

const int N = 600031;

set<pair<int,int> >by_val,by_id;
set<pair<int,int> > ::iterator it;
int n;
int C;
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;
    for (;n;--n){
    	int tp;
    	cin>>tp;
    	if (tp==1){
    		++C;
    		int val;
    		cin>>val;
    		by_val.insert(make_pair(-val,C));
    		by_id.insert(make_pair(C,val));
    	}
    	if (tp==2){ // by id
    		it=by_id.begin();
    		int id=(*it).first;
    		int money=(*it).second;
    		by_id.erase(it);
    		by_val.erase(make_pair(-money,id));
    		ans.push_back(id);
    	}
    	if (tp==3){
    		it=by_val.begin();
    		int id=(*it).second;
    		int money=-(*it).first;
    		by_val.erase(it);
    		by_id.erase(make_pair(id,money));
    		ans.push_back(id);
    	}
    }

    for (int i=0;i<ans.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<ans[i];
    }


    //cin.get(); cin.get();
    return 0;
}