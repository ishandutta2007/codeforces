/*
The trail of tears began for all the Cherokee
The white men came to trade & borrow but then they would not leave
Some of us were taken by boat, and died at sea
Those of us who lived were sold to slavery

We welcomed them as brothers knowing nothing of their greed
Born hunters not the hunted as the white man hunts for me
We are descendants of the animals we live among the free
Our trail of tears would end one day at Wounded Knee.

Great Spirit, thunder birds fly, we are wild and free
To fight and die by the open sky, Spirit Horse ride for me

When we do the Ghost Dance, the buffalo will return
Paint ourselves for war, now blood and fire burn
Great Spirit makes us strong, take us to the sky
The Cherokee are brave, we are not afraid to die

Great Spirit, thunder birds fly, we are wild and free
To fight and die by the open sky, Spirit Horse ride for me

Red Cloud, Black Hawk, Sitting Bull, Crazy Horse, Geronimo
Strong and brave warriors to the grave

There has been much killing there will be much more
The Medicine Man is dancing he's calling us to war,
Hatchets sing with pride let the white men die

Great Spirit, thunder birds fly, we are wild and free
To fight and die by the open sky, Spirit Horse ride for me
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

int tests;
vector<int> V;
string st;

int A,B;
int shit;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	V.clear();
    	cin>>A>>B;
    	cin>>st;
    	int cnt=0;
    	st+="X";
    	shit=0;
    	for (int i=0;i<st.size();i++)
    	{
    		if (st[i]=='X'){
    			if (cnt>=B)
    				V.push_back(cnt);
    			if (cnt>=B&&cnt<A){
    				shit=1;
    			}
    			cnt=0;
    		}
    		else
    			cnt++;
    	}

    	sort(V.begin(),V.end());

    	if (V.size()==0){
    		cout<<"NO"<<endl;
    		continue;
    	}
    	for (int i=0;i<V.size();i++){
    		if (V[i]>=B&&V[i]<A){
    			shit=1;
    		}
    	}

    	if (shit){
    		cout<<"NO"<<endl;
    		continue;
    	}
    	if (V.size()>1&&V[V.size()-2]>=2*B){
    		cout<<"NO"<<endl;
    		continue;
    	}
    	int cnt_moves=0;
    	for (int i=0;i+1<V.size();i++){
    		if (V[i]>=A){
    			cnt_moves++;
    		}
    	}
    	int can_win=0;
    	int len=V.back();
    	for (int i=0;i+A<=len;i++){
    		if (len-i-A>=B&&len-i-A<A)
    			continue;
    		if (i>=B&&i<A)
    			continue;
    		if (len-i-A>=2*B)
    			continue;
    		if (i>=2*B)
    			continue;
    		int new_cnt=cnt_moves;
    		if (i>=A)
    			new_cnt++;
    		if (len-i-A>=A)
    			new_cnt++;
    		if (new_cnt%2==0)
    			can_win=1;
    	}
    	if (can_win){
    		cout<<"YES"<<endl;
    	}
    	else
    	{
    		cout<<"NO"<<endl;
    	}
    }

//    cin.get(); cin.get();
    return 0;
}