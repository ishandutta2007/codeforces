/*
Hear them whisper,
Voices from the other side
Hear them calling
Former foes now friends are resting side by side

They will never leave our hearts or fade away
Live forever
They were far too young to die in such a way

How many wasted lives
How many dreams did fade away
Broken promises
They won't be coming home

Oh mothers wipe your tears
Your sons will rest a million years
Found their peace at last
As foe turned to friend
And forgive
And they knew they'd die

Gallipoli
Left their letters in the sand
Such waste of life
Gallipoli
Dreams of freedom turned to dust

Hell is waiting where the ocean meets the sand
Cliffs of burden
Where the soldiers rushed into a certain death

At the shoreline
Blood of heroes stains the land
Light a candle
One for each of them who fought and died in vain

There is no enemy
There is no victory
Only boys who lost their lives in the sand
Young men were sacrificed
Their names are carved in stone and kept alive
And forever we will honour the memory of them
And they knew they would die

Gallipoli
Left their letters in the sand
Such waste of life
Gallipoli
Dreams of freedom turned to dust

Oh mothers wipe your tears
Your sons will rest a million years
Found their peace at last
As foe turned to friend
And forgive
And they knew they would die

Gallipoli
Left their letters in the sand
Such waste of life
Gallipoli
Dreams of freedom turned to dust
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

const int N = 200031;

int n,k;
vector<int> initial_vector(){
	vector<int> ret;
	for (int i=1;i<=k;i++){
		ret.push_back(i);
	}
	return ret;
}

pair<int,int> make_query(vector<int> v){
	cout<<"?";
	for (int i=0;i<v.size();i++){
		cout<<" "<<v[i];
	}
	cout<<endl;
	pair<int,int> ret;
	cin>>ret.first>>ret.second;
	return ret;
}

vector<int> get_modified(vector<int> v,pair<int,int> p){
	for (int i=0;i<v.size();i++){
		if (v[i]==p.first)
			v[i]=k+1;
	}
	return v;
}

vector<int> get_for_solver(vector<int> v,int ps){
	v[ps]=k+1;
	return v;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
   // ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>k;

    vector<int> V=initial_vector();

    pair<int,int> P=make_query(V);

    vector<int> VV=get_modified(V,P);

    pair<int,int> new_P=make_query(VV);

    // now if new_P.second is larger, it means that k+1 is larger than pivot, otherwise it is smaller

    int count_below=0;

    bool flag=0;
    if (new_P.second>P.second)
    	flag=1;
    else
    	flag=0;

    for (int i=0;i<V.size();i++){
    	if (V[i]==P.first)
    		continue;
    	vector<int> V2=get_for_solver(V,i);
    	pair<int,int> temp=make_query(V2);
    	if (temp.second==P.second&&flag==1)// substituted larger with larger
    		continue;
    	if (temp.second!=P.second&&flag==0)// substituted larger with smaller
    		continue;
    	count_below++;
    }

    cout<<"! "<<count_below+1<<endl;

    //    cin.get(); cin.get();
    return 0;
}