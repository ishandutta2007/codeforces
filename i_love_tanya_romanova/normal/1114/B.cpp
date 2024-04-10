/*
The waiting drove me mad
You're finally here and I'm a mess
I take your entrance back
Can't let you roam inside my head

I don't wanna take what you can give
I would rather starve than eat your bread
I would rather run but I can't walk
Guess I'll lie alone just like before

I'll take the vermin's path
Oh, and I must refuse your test
A push me and I will resist
This behavior's not unique

I don't wanna hear from those who know
They can buy, but can't put on my clothes
I don't wanna limp for them to walk
Never would have known of me before

I don't wanna be held in your debt
I'll pay it off in blood, let I be wed
I'm already cut up and half dead
I'll end up alone like I began

Everything has chains
Absolutely nothing's changed
Take my hand, not my picture
Spilled my tincture

I don't wanna take what you can give
I would rather starve than eat your bread
All the things that others want for me
Can't buy what I want because it's free

Can't buy what I want because it's free
Can't be what you want because I'm

Why ain't it supposed to be just fun
Oh, to live and die, let it be done
I figure I'll be damned
All alone like I began

It's your move now

I thought you were a friend, but I guess I, I guess I hate you
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

int n,m,k,ar[N];
vector<pair<int,int> > order;
long long ans;
int take[N];

int C;
vector<int> cuts;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	order.push_back(make_pair(ar[i],i));
    }

    sort(order.begin(),order.end());
    reverse(order.begin(),order.end());
    for (int i=0;i<m*k;i++){
    	int id=order[i].second;
    	int val=order[i].first;
    	ans+=val;
    	take[id]=1;
    }

    cout<<ans<<endl;

    for (int i=1;i<=n;i++){
    	if (take[i])
    		++C;
    	if (C==m){
    		cuts.push_back(i);
    		C=0;
    	}
    }

    for (int i=0;i+1<cuts.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<cuts[i];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}