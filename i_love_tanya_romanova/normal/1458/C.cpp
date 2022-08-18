/*
Critical moments pass,
As doctrines of fools will last.
I am just trying to cope,
Into my horrorscope.
Through eyes and ears they bleed,
Reciting their holy creed.
Heeding but one request,
The future is put to rest...

Bless me in darkened days,
Down to my knees I pray.
I am just trying to cope
Within this horrorscope.
In the wake of all frustration,
I begin to lose control.

Watched as the weapons fired,
Bombs bursting in the air...
Burned in the fields of fire!
Standing in the middle of nowhere.
Watched as the weapons fired,
Baptized in fields of fire!

Well,
The change is here,
And the future clear.
I can feel it coming.
So full of hate,
It's getting late!
Yeah, I know it's coming.
When all the choice
Turned to just one voice,
Yeah, the wind is turning.

This is your horrorscope...

Words laced with blasphemy,
Drip with sincerity.
Falling into the plan,
Like sacrificial lambs.
Hearing the words and said,
Rings like nail to the head.
Now I can see the stars,
I know we have gone too far.

Watched as the weapons fired,
Bombs bursting in the air...
Baptized in fields of fire!
Watched as the weapons fired,

Well,
The change is here,
And the future clear.
I can feel it coming.
So full of hate,
It's getting late!
Yeah, I know it's coming.
When all the choice
Turned to just one voice,
Yeah, the wind is turning.

Well,
The change is here,
And the future clear.
I can feel it coming.
So full of hate,
It's getting late!
Yeah, I know it's coming.
When all the choice
Turned to just one voice,
Yeah, the wind is turning.

This is your horrorscope.
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

const long long N = 200031;

int tests;
int n,m;
int ar[1031][1031];
int dir[20][20];
int p[20];
string st;
int ans[1031][1031];

void normalize(){
	for (int i=0;i<3;i++){
		p[i]%=n;
		if (p[i]<0)
			p[i]+=n;
	}
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			dir[i][j]%=n;
			if (dir[i][j]<0)
				dir[i][j]+=n;
		}
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m;
    	for (int i=0;i<n;i++){
    		for (int j=0;j<n;j++){
    			cin>>ar[i][j];
    			--ar[i][j];
    		}
    	}
    	for (int i=0;i<3;i++){
    		for (int j=0;j<3;j++){
    			dir[i][j]=0;
    		}
    	}
    	for (int i=0;i<3;i++){
    		dir[i][i]=1;
    	}
    	p[0]=p[1]=p[2]=0;

    	cin>>st;
    	for (int i=1;i<=m;i++){
    		char T=st[i-1];
    		if (T=='R'){
    			p[1]++;
    		}
    		if (T=='L'){
    			p[1]--;
    		}
    		if (T=='U'){
    			p[0]--;
    		}
    		if (T=='D'){
    			p[0]++;
    		}
    		if (T=='I'){
    			swap(p[1],p[2]);
    			for (int j=0;j<3;j++){
    				swap(dir[j][1],dir[j][2]);
    			}
    		}
    		if (T=='C'){
    			swap(p[0],p[2]);
    			for (int j=0;j<3;j++){
    				swap(dir[j][0],dir[j][2]);
    			}
    		}
    		normalize();
		/*	cout<<"@@"<<st[i-1]<<endl;
			for (int a=0;a<3;a++){
				for (int b=0;b<3;b++){
					cout<<dir[a][b]<<" ";
				}
				cout<<endl;
			}*/
    	}

//    	cout<<p[0]<<"@"<<p[1]<<"@@"<<p[2]<<endl;

 //   	++p[0];++p[1];++p[2];
    	for (int i=0;i<n;i++){
    		for (int j=0;j<n;j++){
    			ans[i][j]=0;
    		}
    	}

    	for (int i=0;i<n;i++){
    		for (int j=0;j<n;j++){
    			int qx=0;
    			int qy=0;
    			int qz=0;
    			qx+=p[0];
    			qy+=p[1];
    			qz+=p[2];
    			qx+=dir[0][0]*i+dir[1][0]*j+dir[2][0]*ar[i][j];
    			qy+=dir[0][1]*i+dir[1][1]*j+dir[2][1]*ar[i][j];
    			qz+=dir[0][2]*i+dir[1][2]*j+dir[2][2]*ar[i][j];
    			qx%=n;
    			qy%=n;
    			qz%=n;
    			if (qx<0)
    				qx+=n;
    			if (qy<0)
    				qy+=n;
    			if (qz<0)
    				qz+=n;
    			ans[qx][qy]=qz;

    			//cout<<qx<<"@@@"<<qy<<" "<<qz<<" "<<i<<" "<<j<<endl;
    		}
    	}

    	for (int i=0;i<n;i++){
    		for (int j=0;j<n;j++){
    			if (j>0)
    				cout<<" ";
    			cout<<ans[i][j]+1;
    		}
    		cout<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}