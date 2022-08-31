/*
She's stone cold bush yea
And baby that's alright
She's stone cold bush yea
And that's alright with me
Get up off your knees, come on walk with me
Tell me what you need to get along
A statue come to live
I cut you with my knife
Bleeding to the tune of dolly dagger
She's stone cold bush
Haight street got nothing to show
Except the skirt on your ass
When you're livin' on the streets
You've got to let it roll
Get on with what you've got
Awe everybody knows that it's alright
You've got no secrets to tell
But when you walk that walk and talk that talk
You do it oh so well
She's stone cold bush
She's got marble eyes
Sweet china doll her thighs
And animal in pain she starts to cry
Her pipes are open wide
She blows more than my mind
Echo sounds of soul
Time after time
She's stone cold bush
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

int r,c;
int ans[1031][1031];

int gcd(int a,int b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

int flag=0;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>r>>c;
    if (r==1&&c==1){
    	cout<<0<<endl;
    	return 0;
    }

    if (c==1){
    	flag=1;
    	swap(r,c);
    }

    for (int i=1;i<=r;i++){
    	for (int j=1;j<=c;j++){
    		int from_row=i;
    		int from_col=j+r;
    		ans[i][j]=from_row*from_col;
    	}
    }

    if (flag){
    	swap(r,c);
    	for (int i=1;i<=max(r,c);i++){
    		for (int j=1;j<=max(r,c);j++){
    			if (i>j)
    				swap(ans[i][j],ans[j][i]);
    		}
    	}
    }

    for (int i=1;i<=r;i++){
    	for (int j=1;j<=c;j++){
    		if (j>1)
    			cout<<" ";
    		cout<<ans[i][j];
    	}
    	cout<<endl;
    }

    /*for (int i=1;i<=r;i++){
    	int q=0;
    	for (int j=1;j<=c;j++){
    		q=gcd(q,ans[i][j]);
    	}
    	cout<<q<<endl;
    }
    for (int j=1;j<=c;j++){
    	int q=0;
    	for (int i=1;i<=r;i++){
    		q=gcd(q,ans[i][j]);
    	}
    	cout<<q<<endl;
    }*/

    //    cin.get(); cin.get();
    return 0;
}