/*
White man came across the sea
He brought us pain and misery
He killed our tribes, he killed our creed
He took our game for his own need

We fought him hard we fought him well
Out on the plains we gave him hell
But many came too much for Cree
Oh will we ever be set free?

Riding through dust clouds and barren wastes
Galloping hard on the plains
Chasing the redskins back to their holes
Fighting them at their own game
Murder for freedom's a stab in the back
Women and children the cowards attack

Run to the hills, run for your lives
Run to the hills, run for your lives

Soldier blue in the barren wastes
Hunting and killing's a game
Raping the women and wasting the men
The only good Indians are tame
Selling them whiskey and taking their gold
Enslaving the young and destroying the old

Run to the hills,
run for your lives.
Run to the hills,
run for your lives.

Yeah oh ah!

Run to the hills,
run for your lives.
Run to the hills,
run for your lives.

Run to the hills,
run for your lives.
Run to the hills,
run for your lives.
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
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 700031;

int n,m,w[N],sz[N];
vector<int> ve;

int get(int x){
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b){
	a=get(a);
	b=get(b);
	if(a==b)
		return ;
	sz[a]+=sz[b];
	w[b]=a;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	w[i]=i;
    	sz[i]=1;
    }

    for (int i=1;i<=m;i++){
    	int cnt;
    	ve.clear();
    	cin>>cnt;
    	for (int j=0;j<cnt;j++){
    		int val;
    		cin>>val;
    		ve.push_back(val);
    	}
    	for (int j=1;j<ve.size();j++){
    		merge(ve[j],ve[0]);
    	}
    }

    for (int i=1;i<=n;i++){
    	if (i>1)
    		cout<<" ";
    	cout<<sz[get(i)];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}