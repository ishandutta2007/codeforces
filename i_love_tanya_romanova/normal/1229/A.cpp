/*
I don't wanna die alone
I don't wanna live forsaken
I refuse to let this go
Because my soul is breaking

I don't wanna let you know
That my heart is just so jaded
I refuse to let it show
I refuse to let it go

Wake me up when this is over
I'm tired of living life like it's a dream
Please wake me up when it's all over
I'm tired of living right here in between
I refuse

I've always walked alone
I chose the path less taken
I refuse to let you win
Life's a bitch and I've been shaken

It's not a joke at all
Inside my spirit's fading
I refuse to take the fall
'Cause no one cares at all

Wake me up when this is over
I'm tired of living life like it's a dream
Please wake me up when it's all over
I'm tired of living right here in between
I refuse

'Cause at the end of the day I'm not you
I refuse

Wake me up when this is over
I'm tired of living life like it's a dream
Please wake me up when it's all over
I'm tired of living right here in between
Wake me up when this is over
I'm tired of living life like it's a dream
Please wake me up when it's all over
I'm tired of living right here in between

I refuse
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

int n;
long long a[N],b[N];
bool beats[7031][7031];
int outdeg[N];
int cur_size;
int taken[N];
vector<int> leaves;
int in_leaves[N];

void kill(int v){
	cur_size--;
	taken[v]=0;
	for (int i=1;i<=n;i++){
		if (taken[i]==0)
			continue;
		if (beats[i][v]==1)
			outdeg[i]--;
		if (outdeg[i]==cur_size-1&&in_leaves[i]==0){
			in_leaves[i]=1;
			leaves.push_back(i);
		}
	}
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
    	cin>>a[i];
    }
    for (int i=1;i<=n;i++){
    	cin>>b[i];
    }

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++){
    		if ((a[i]&a[j])!=a[i])// j isn't covering all for i
    		{
    			beats[i][j]=1;
    			outdeg[i]++;
    		}
    	}
    }

    cur_size=n;

    for (int i=1;i<=n;i++){
    	taken[i]=1;
    	if (outdeg[i]==n-1){
    		leaves.push_back(i);
    		in_leaves[i]=1;
    	}
    }

    while (leaves.size()){
    	int v=leaves.back();
    	leaves.pop_back();
    	kill(v);
    }

    int ans_cnt=0;
    long long total_b=0;
    for (int i=1;i<=n;i++){
    	if (taken[i]){
    		ans_cnt++;
    		total_b+=b[i];
    	}
    }

    if (ans_cnt==1)
    	total_b=0;

    cout<<total_b<<endl;

//    cin.get(); cin.get();
    return 0;
}