/*
Sadistic, killing of your mind
Pathetic, mutants in your brain

Damage, is already done
Failure, of the sacrifice
Confronting with your maker,
paranoid vision a dream
Flesh is dripping cold
Day of mourning

Death is on your back
Watching, the angels die.
Altaer, the virgin's blood.
Drips, on the floor.

Praise your holy maker
Awaiting the hour of your death,
Create your own vision,
What will come after life.
You feel no pain no more
Burn with me till your flesh drips away
Tortured bodies all around
Eternal hate inside your mind
Reborn to eternity, blessing your desire
Epidemic world outside, the change has begun.

Sadistic, killing of your mind.
pathetic, mutants in your brain.

Damage, is already done.
Failure, of the sacrifice.
Confronting with your maker,
paranoid vision a dream
Flesh dripping cold
Day of mourning.
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

int n,ar[N];
int x;
vector<vector<int> > ans;

vector<int> make_move(int a,int b,int c){
	vector<int> ret;
	ret.push_back(a);
	ret.push_back(b);
	ret.push_back(c);
	return ret;
}

void show_it(vector<int> v){
	for (int i=0;i<v.size();i++){
		if (i)
			cout<<" ";
		cout<<v[i];
	}
	cout<<endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	x^=ar[i];
    }

    if (n%2==0&&x!=0){
    	cout<<"NO"<<endl;
    	return 0;
    }

    for (int i=2;i+1<=n;i+=2){
    	ans.push_back(make_move(1,i,i+1));
    }

    for (int i=2;i+1<=n;i+=2){
    	ans.push_back(make_move(1,i,i+1));
    }
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++){
    	show_it(ans[i]);
    }

    //cin.get(); cin.get();
    return 0;
}