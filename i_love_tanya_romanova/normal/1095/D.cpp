/*
End of passion play, crumbling away
Im your source of self-destruction
Veins that pump with fear, sucking darkest clear
Leading on your deaths construction
Taste me you will see
More is all you need
Youre dedicated to
How Im killing you

Come crawling faster
Obey your master
Your life burns faster
Obey your master
Master

Master of puppets Im pulling your strings
Twisting your mind and smashing your dreams
Blinded by me, you cant see a thing
Just call my name, cause Ill hear you scream
Master
Master
Just call my name, cause Ill hear you scream
Master
Master

Needlework the way, never you betray
Life of death becoming clearer
Pain monopoly, ritual misery
Chop your breakfast on a mirror
Taste me you will see
More is all you need
Youre dedicated to
How Im killing you

Come crawling faster
Obey your master
Your life burns faster
Obey your master
Master

Master of puppets Im pulling your strings
Twisting your mind and smashing your dreams
Blinded by me, you cant see a thing
Just call my name, cause Ill hear you scream
Master
Master
Just call my name, cause Ill hear you scream
Master
Master

Master, master
Wheres the dreams that Ive been after?
Master, master
You promised only lies
Laughter, laughter
All I hear or see is laughter
Laughter, laughter
Laughing at my cries

Fix me

Hell is worth all that, natural habitat
Just a rhyme without a reason
Never-ending maze, drift on numbered days
Now your life is out of season
I will occupy
I will help you die
I will run through you
Now I rule you too

Come crawling faster
Obey your master
Your life burns faster
Obey your master
Master

Master of puppets Im pulling your strings
Twisting your mind and smashing your dreams
Blinded by me, you cant see a thing
Just call my name, cause Ill hear you scream
Master
Master
Just call my name, cause Ill hear you scream
Master
Master
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

int n;
vector<int> g[N];
vector<int> ans;

bool knows(int a,int b){
	for (int i=0;i<g[a].size();i++){
		if (g[a][i]==b)
			return true;
	}
	return false;
}

int get_next(int x){
	int v1=g[x][0];
	int v2=g[x][1];
	if (knows(v1,v2))
		return v1;
	return v2;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	for (int j=0;j<2;j++){
    		int val;
    		cin>>val;
    		g[i].push_back(val);
    	}
    }

    if (n==3){
    	cout<<"1 2 3"<<endl;
    	return 0;
    }

    ans.push_back(1);
    while (ans.size()<n){
    	int val=ans.back();
    	int nxt=get_next(val);
    	ans.push_back(nxt);
    }

    for (int i=0;i<ans.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<ans[i];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}