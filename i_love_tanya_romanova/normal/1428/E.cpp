/*
Seek evil, you will find, speak evil, its on your mind
Build a bridge to anywhere to have a home to turn
To a brook flows from anywhere and you will find the evil
That you suffer unto having on your mind

Walk this way and you will find
Those burning bridges inside your mind
So you look back into nowhere
To see all these bridges are meant to stay

Aggression in large amounts, thats everything that counts
No hand waiting that must be paid, leave your encores all unplayed
Knocked down and out, you cry it out loud
Locked inside your self-made prison

Walk this way and you will find
Those burning bridges inside your mind
So you look back into nowhere
To see all these bridges are meant to stay

then one fine youre led astray, a witch flew on her broom
in sparkling skies she flew away and took with her your doom
then one fine youre led astray, a witch flew on her broom
in sparkling skies she flew away and took with her your doom

Seek evil, you will find, speak evil, its on your mind
Build a bridge to anywhere to have a home to turn
To a brook flows from anywhere and you will find the evil
That you suffer unto having on your mind

Walk this way and you will find
Those burning bridges inside your mind
So you look back into nowhere
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

int n,k,ar[N];
int deg[N];
set<pair<long long,long long> > S;
set<pair<long long,long long> > ::iterator it;
int S_deg;
long long ans;

long long squ(long long x){
	return x*x;
}

long long func(int id,int deg){
	int full=ar[id]/deg;
	int ohead=ar[id]%deg;
	long long ret=0;
	ret+=ohead*squ(full+1);
	ret+=(deg-ohead)*squ(full);
	return ret;
}

long long ev(int id){
	return func(id,deg[id])-func(id,deg[id]+1);
}

long long F(long long val){
	return val*val;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	deg[i]=1;
    	S_deg++;
    	S.insert(make_pair(ev(i),i));
    	//cout<<i<<" "<<ev(i)<<endl;
    }

    while (S_deg<k){
    	it=S.end();
    	--it;
    	int id=(*it).second;
    	S.erase(it);
    	++deg[id];
    	S.insert(make_pair(ev(id),id));
    	S_deg++;
    }

    for (int i=1;i<=n;i++){
    	ans+=func(i,deg[i]);
//    	cout<<i<<" "<<ar[i]<<" "<<deg[i]<<endl;
    }

    cout<<ans<<endl;


    //cin.get(); cin.get();
    return 0;
}