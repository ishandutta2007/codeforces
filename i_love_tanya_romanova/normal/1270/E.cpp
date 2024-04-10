/*
We live for the magic in the sound, distorted guitars are breaking ground
The drum pounding faster than my heart, the vocals are screaming extreme art
The passion for metal drives us forth, the best heavy metal comes from north

The powerful tunes, spectacular shows, the audience screams in ecstasy

Metal, Metal
Back with the vengeance
Metal, Metal
All that I need is heavy metal
Metal
Screaming together
Metal, Metal
Metal is all that I need

While hell bends for leather we stand strong, a rocker can party all night long
the school couldn't teach us rock' n roll, the school couldn't help us reach our goal
We live for the magic in the sound, distorted guitars are breaking ground

The powerful tunes, spectacular shows, the audience screams in ecstasy
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

int n;
int x[N],y[N];
vector<int> get_odds(){
	vector<int> ret;
	for (int i=1;i<=n;i++){
		int s1=(x[i]%2==0);
		int s2=(y[i]%2==0);
		if (s1!=s2)
			ret.push_back(i);
	}
	return ret;
}

void show_answer(vector<int> v){
	cout<<v.size()<<endl;
	for (int i=0;i<v.size();i++){
		if (i)
			cout<<" ";
		cout<<v[i];
	}
	cout<<endl;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>x[i]>>y[i];
    }

    while (true){
/*    	for (int i=1;i<=n;i++){
    		cout<<x[i]<<" "<<y[i]<<endl;
    	}
    	cout<<endl;
    	cin.get();
*/
    	vector<int> V1=get_odds();
    	if (V1.size()>0&&V1.size()<n){
    		show_answer(V1);
    		return 0;
    	}

    	if (V1.size()==n){ // x%2!=y%2
    		for (int i=1;i<=n;i++){
    			x[i]+=1;
    		}
    	}

    	// now x%2==y%2 everywhere

    	for (int i=1;i<=n;i++){
    		long long t1=x[i]+y[i];
    		long long t2=x[i]-y[i];
    		x[i]=t1;
    		y[i]=t2;
    		x[i]/=2;
    		y[i]/=2;
    	}
    }


    //    cin.get(); cin.get();
    return 0;
}