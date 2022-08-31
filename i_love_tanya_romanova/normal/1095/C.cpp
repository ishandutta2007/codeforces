/*
Life, it seems, will fade away
Drifting further every day
Getting lost within myself
Nothing matters, no one else

I have lost the will to live
Simply nothing more to give
There is nothing more for me
Need the end to set me free

Things not what they used to be
Missing one inside of me
Deathly lost, this can't be real
Cannot stand this hell I feel

Emptiness is filling me
To the point of agony
Growing darkness taking dawn
I was me, but now he's gone

No one but me can save myself, but it's too late
Now I can't think, think why I should even try

Yesterday seems as though it never existed
Death greets me warm, now I will just say goodbye
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
int ar[N];
multiset<int> S;
multiset<int>::iterator it;
int ans;
int k;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>k;
    for (int i=30;i>=0;--i){
    	if (n&(1<<i)){
    		S.insert(1<<i);
    	}
    }

    if (S.size()>k){
    	cout<<"NO"<<endl;
    	return 0;
    }

    while (S.size()<k){
    	it=S.end();
    	--it;
    	int val=(*it);
    	if (val==1){
    		cout<<"NO"<<endl;
    		return 0;
    	}
    	S.erase(S.find(val));
    	S.insert(val/2);
    	S.insert(val/2);
    }
    cout<<"YES"<<endl;
    for (it=S.begin();it!=S.end();it++){
    	cout<<(*it)<<" ";
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}