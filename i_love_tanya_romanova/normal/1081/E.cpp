/*
Ooh what a night it was, the night I fell apart
I begged a lover not to go away but she went and broke my heart
I found myself in a Vegas bar with a whole new set of friends
Seen through the bottom of an empty glass
Like looking through a fisheye lens
One night in Vegas

It was a morning of revenge for what I did the night before
Which accompanied me to the following day to even up the score
In a stone cold sober mood next afternoon at ten
I found my tongue back in my mouth
And I told myself not to drink again
One night in Vegas

I was three sheets to the wind
The three shots did me in
Three angels there above me
As I was lying on the floor
I knew I should have run for the hills
But I still wanted more

I don't remember the chapel but I woke up with a wife
I looked at her, she looked at me and now we're hooked for life
How strange the situation, it's now been thirty years
Since I met that girl in Vegas
And would you believe it, she's still here
One night in Vegas
Oh yeah I gotta tell you, one night in Vegas
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

const int N = 200031;

int n,dif[N];
long long ar[N];
vector<int> divs[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    for (int i=1;i<N;i++){
    	for (int j=i;j<N;j+=i)
    		divs[j].push_back(i);
    }

    cin>>n;
    for (int i=2;i<=n;i+=2){
    	cin>>dif[i];
    }

    for (int i=2;i<=n;i+=2){
    	long long cur=dif[i];
    	long long lowest=1e9;
    	long long prv;
    	for (int j=0;j<divs[cur].size();j++){
    		long long V=divs[cur][j];
    		long long U=cur/V;
//    		cout<<V<<"@"<<U<<endl;
    		// (a-b)*(a+b)=a*a-b*b
    		// a-b=V, a+b=U
    		if (V%2!=U%2)
    			continue;
    		if (U<=V)
    			continue;
    		long long b=(U-V)/2;
    		long long a=U-b;
    		if (a<=0||b<=0)
    			continue;
    		//cout<<a<<"@"<<b<<endl;
    		if (1ll*b*b<=ar[i-2])
    			continue;
    		if (a<lowest){
    			lowest=a;
    			prv=b;
    		}
    	}
    	//cout<<lowest<<" "<<prv<<endl;
    	if (lowest>1e8){
    		cout<<"No"<<endl;
    		return 0;
    	}
    	ar[i]=lowest*lowest;
    	ar[i-1]=prv*prv;
    }

    cout<<"Yes"<<endl;

    for (int i=1;i<=n;i++){
    	if (i>1)
    		cout<<" ";
    	cout<<ar[i]-ar[i-1];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}