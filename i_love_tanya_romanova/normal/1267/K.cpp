/*
And I wrap my arms around me
And think of times gone by
I used to share my fate with you
Wrapped in a robe of fire

Inhale  exhale
All that matters  torn to shatters

Having trusted you before
Made my desolate past live again
My earth-born spirit breathe again

I will search forevermore
Through the wind, the waves, the mist, the rain
Your smile is in my tears again

And I drift through empty days
I feel like a puppet on a string
I hear the songs you used to sing

I count the seconds, time unwinds
Walking in the shadows of my mind
Dissolved in thoughts, I melt into you

But the years and memories wither into a scroll
Unfathomed sorrow resonated within my soul

And from my heart, I'll pour this song,
Of endless struggle, still it made me strong
Because these roars of love
Reach towards the sky

Silently I close the door
Pondering words I somehow cannot say
Shutting the world far away

Set me on fire with your glow,
Feels like nothing i have felt before
Earth's last its balance I can fly
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

const int N = 2100031;

int tests;
long long k;
vector<int> order;
long long C[100][100];
int taken;
int HI;

long long solver(int val,int cnt){
	int valid=0;
	for (int i=2;i<=HI;i++){
		if (i>val)
			++valid;
	}
	valid-=taken;
	//cout<<valid<<"@"<<taken<<" "<<val<<" "<<cnt<<endl;
	return C[valid][cnt];
}


long long crap_solver(int val,int cnt,int used){
	int valid=0;
	for (int i=2;i<HI;i++){
		if (i>val)
			++valid;
	}
	valid-=used;
	return C[valid][cnt];
}

long long tricky(vector<int> order){
	int cnt=0;
	int used=0;
	long long ret=1;
	for (int i=0;i<order.size();i++){
		if (i>0&&order[i]!=order[i-1]){
			ret*=crap_solver(order[i-1],cnt,used);
			used+=cnt;
			cnt=0;
		}
		cnt++;
	}
	if (order.back()!=0){
		ret*=crap_solver(order[order.size()-1],cnt,used);
	}
	return ret;
}
int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    for (int i=0;i<=50;i++){
    	for (int j=0;j<=i;j++){
    		if (j==0||j==i)
    			C[i][j]=1;
    		else
    			C[i][j]=C[i-1][j]+C[i-1][j-1];
    	}
    }

    cin>>tests;
    for (;tests;--tests){
    	cin>>k;
    	HI=0;
    	order.clear();
    	for (int i=2;;i++){
    		if (k==0)
    			break;
    		HI=i;
    		order.push_back(k%i);
    		k/=i;
    	}
    	sort(order.begin(),order.end());
    	reverse(order.begin(),order.end());

/*    	for (int i=0;i<order.size();i++){
    		cout<<order[i]<<" ";
    	}
    	cout<<endl;
*/
    	long long ans=1;

    	taken=0;

    	int cnt=0;

    	for (int i=0;i<order.size();i++){
    		if (i>0&&order[i]!=order[i-1]){
    			ans=ans*solver(order[i-1],cnt);
    			taken+=cnt;
    			cnt=0;
    		}
    		++cnt;
    	}

    	ans=ans*solver(order[order.size()-1],cnt);

    	cout<<ans-1-tricky(order)<<endl;
    }
    //    cin.get(); cin.get();
    return 0;
}