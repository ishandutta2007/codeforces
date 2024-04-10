/*
Trapped in purgatory
A lifeless object, alive
Awaiting reprisal
Death will be their acquisition

The sky is turning red
Return to power draws near
Fall into me, the sky's crimson tears
Abolish the rules made of stone

Pierced from below, souls of my treacherous past
Betrayed by many, now ornaments dripping above

Awaiting the hour of reprisal
Your time slips away

Raining blood
From a lacerated sky
Bleeding its horror
Creating my structure
Now I shall reign in blood!
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
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 500031;

int pr[N];
map<vector<pair<int,int> >,int> CNT;
int n,k;
vector<pair<int,int> > order,need;
long long ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    pr[1]=1;
    for (int i=2;i<=100000;i++){
    	if (pr[i]==0)
    		for (int j=i;j<=100000;j+=i){
    			pr[j]=i;
    		}
    }

    cin>>n>>k;

    for (int i=1;i<=n;i++){
    	int val;
    	cin>>val;
    	order.clear();
    	while (val>1){
    		int x=pr[val];
    		int cnt=0;
    		while (val%x==0){
    			cnt++;
    			val/=x;
    		}
    		//cout<<x<<" "<<cnt<<" "<<val<<endl;
    		if (cnt%k)
    			order.push_back(make_pair(x,cnt%k));
    	}
    	sort(order.begin(),order.end());
    	need=order;
    	for (int j=0;j<need.size();j++){
    		need[j].second=(k-need[j].second)%k;
    	}
    	ans+=CNT[need];
    	//cout<<CNT[need]<<endl;
    	CNT[order]++;
    }

    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}