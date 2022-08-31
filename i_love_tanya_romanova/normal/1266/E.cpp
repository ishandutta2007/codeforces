/*
I am just a lousy bum
Searching for the unknown crumb
The crumb the crumb
Something or someone to come
Come along illuminate my lust
Combust
Confucius might have been confused
And Buddha might have blown a fuse
I ooze the muse

Meet me at the coffee shop
We can dance like Iggy Pop
Another go in the parking lot
Frewak the cheek on your hot spot

Back and forth my body's jerking
Will to thrill will not stop working
Work and work
I'll take you on a honeymoon
Jumping on a bed in a hotel room
The room the groom

Meet me at the coffee shop
We can dance
like Iggy Pop
Another go in the parking lot
Frewak the cheek on your hot spot
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
long long am[N];
long long ttl,total_saved;
int tests;

map<pair<int,int>,int> maps;
long long cur[N];

void rem(int id){
	total_saved-=min(am[id],cur[id]);
}

void add(int id){
	total_saved+=min(am[id],cur[id]);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>am[i];
    	ttl+=am[i];
    }

    cin>>tests;

    for (;tests;--tests){
    	int a,b,c;
    	cin>>a>>b>>c;
    	if (maps.find(make_pair(a,b))!=maps.end()){
    		int to=maps[make_pair(a,b)];
    		maps.erase(make_pair(a,b));
    		rem(to);
    		cur[to]--;
    		add(to);
    	}
    	if (c!=0){
    		int to=c;
    		rem(to);
    		cur[to]++;
    		add(to);
    		maps[make_pair(a,b)]=to;
    	}
    	cout<<ttl-total_saved<<"\n";
    }
    //    cin.get(); cin.get();
    return 0;
}