/*
Took her to a bar, I though I'd covered all my tracks
Thought I had it made, I felt daggers in my back
You came walkin' through the door sailed into the attack
Don't seem to be my night
You got me bang to rights

I ain't gonna fight it baby, there ain't no excuse
Don't know what to tell ya, but I hope you don't cut loose
It don't matter anyway, my head is in the noose
You got me stitched up tight
You got me bang to rights

I can tell you ain't exactly listening to me
I just wish that I could thing of some place else to be
I'm gonna make it up to you, just you wait and see
My future ain't too bright
You got me bang to rights
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 600031;

int tests,n,m,board[666][666],cnt[655][555],width[666][666];


int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m;
    	for (int i=1;i<=n;i++){
    		string st;
    		cin>>st;
    		for (int j=1;j<=m;j++){
    			if (st[j-1]=='*')
    				board[i][j]=1;
    			else
    				board[i][j]=0;
    		}
    	}

    	for (int i=0;i<=n+1;i++){
    		for (int j=0;j<=m+1;j++){
    			cnt[i][j]=0;
    		}
    	}

    	long long ans=0;

    	for (int i=1;i<=n;i++){
    		for (int j=m;j>=1;--j){
    			cnt[i][j]=0;
    			if (j<m)
    				cnt[i][j]=cnt[i][j+1]+1;
    			else
    				cnt[i][j]=1;
    			if (board[i][j]==0)
    				cnt[i][j]=0;
    			width[i][j]=(cnt[i][j]+1)/2;
    			width[i][j]=min(width[i][j],width[i-1][j+1]+1);
    			ans+=width[i][j];
    		//	cout<<i<<" "<<j<<" "<<width[i][j]<<" "<<cnt[i][j]<<endl;
    		}
    	}
    	cout<<ans<<endl;

    }

    //cin.get(); cin.get();
    return 0;
}