/*
Half dead, you trod through life
So dependent, a shell of a man
Pitiful, you let your vices tell your fate
Follower of the blind, you have nothing.
My empathy has turned to rage.
My pity has turned to hatred.
In selfishness you've sunken to the depths.
How much lower can you go?

All virtue decayed, now a memory
So many friendships lost.
Only enemies.
Shame I feel for you, pain I feel for you.
To cleanse yourself you've got to let go.
Are you not alone now?
Are you not what you've become?
I want to give you the strength to overcome.
The strength to reject those who brought you down.
Take a look, take a look at yourself.
What do you see? What have you become?
You've gone below the bottom.
Take a look, take a look at yourself.
What do you see? What have you become?
You've gone below the bottom.

You've taken their lies as your own.
Tried to justify your own hypocrisy.
You bear the mark of consequence.
You've lied to yourself, you've lied to me.
You've betrayed your own soul.
Sacrificed all you were.
In selfishness you've sunken to the depths.
How much lower can you go.

(All virtue decayed...)
I want to give you the strength to overcome.
The strength to reject those who have brought you down.

Take a look, take a look at yourself.
What do you see what have you become?
Take a look, take a look at yourself.
You've gone below the bottom.
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

const int N = 300031;

int n;
int ar[N];
int ans;
vector<int> order;
vector<int> entries;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    ans=1;

    for (int b=30;b>=0;--b){
    	entries.clear();
    	for (int i=1;i<=n;i++){
    		if (ar[i]&(1<<b)){
    			entries.push_back(i);
    		}
    	}
    	if (entries.size()==1){
    		ans=entries[0];
    		break;
    	}
    }

    order.push_back(ans);
    for (int i=1;i<=n;i++){
    	if (i!=ans)
    		order.push_back(i);
    }

    for (int i=0;i<order.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<ar[order[i]];
    }
    cout<<endl;

    //    cin.get(); cin.get();
    return 0;
}