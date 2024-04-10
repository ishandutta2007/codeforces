/*
Bring to an end
This avoidance when you close your eyes
What is now
Had a beginning phase that came to pass

Now the eyes of the world are upon you
We all want to know
Now the eyes of the world are upon you
Will we ever see?

I can feel it coming down
As the walls give way and crumble
I can feel it coming down
And I will be watching

You take the bait
It pulls you in and takes you down
And these days
It seems we miss what lies between, the lies between

We can sense the way they'll spin us
They'll spin us round and round till we forget
Till we forget

Lead the fires to the core
To the end now within reach, we must resist
We must resist

Now the eyes of the world are upon you
We all want to know
Now the eyes of the world are upon you
Will we ever see?

I can feel it coming down
As the walls give way and crumble
I can feel it coming down
And I will be watching
Yeah, I will be watching

Now the eyes of the world are upon you
Will we ever see?

I can feel it coming down
As the walls give way and crumble
I can feel it coming down
And I will be watching
Yeah, I will be watching
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

vector<pair<int,int> > moves;

bool used[1031][1031];

int CENTER = 200;
int W = 20;

bool outside(int a,int b){
	return (a<0||a>2*CENTER||b<0||b>2*CENTER);
}

void dfs(int a,int b){
	used[a][b]=1;
	for (int i=0;i<moves.size();i++){
		for (int j=-1;j<=1;j++){
			int na=a+moves[i].first*j;
			int nb=b+moves[i].second*j;
			if (outside(na,nb))
				continue;
			if (used[na][nb])
				continue;
			dfs(na,nb);
		}
	}
}

void trace_it(int x1,int y1,int x2,int y2){
	moves.clear();
	moves.push_back(make_pair(x1,y1));
	moves.push_back(make_pair(x2,y2));
	for (int i=0;i<=CENTER*2;i++){
		for (int j=0;j<=CENTER*2;j++){
			used[i][j]=0;
		}
	}
	dfs(CENTER,CENTER);
}

void show_it(){
	for (int i=CENTER-W;i<=CENTER+W;i++){
		for (int j=CENTER-W;j<=CENTER+W;j++){
			if (i==CENTER&&j==CENTER)
				cout<<"X";
			else
				cout<<used[i][j];
		}
		cout<<endl;
	}
}

long long dx1,dx2,dy1,dy2;

pair<long long, long long> normalize(pair<long long, long long> p){
	if (p.first<0)
		p.first*=-1,
		p.second*=-1;
	if (p.first==0&&p.second<0){
		p.second*=-1;
	}
	return p;
}

void iterate_gcd(pair<long long, long long> &p1,pair<long long, long long> &p2){
	if (p1.first<p2.first)
		swap(p1,p2);
	if (p2.first==0)
		return;
	long long times=p1.first/p2.first;
	p1.first-=p2.first*times;
	p1.second-=p2.second*times;
	p1=normalize(p1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
/*
    for (int dx1=-5;dx1<=5;dx1++){
    	for (int dy1=-5;dy1<=5;dy1++){
    		for (int dx2=-5;dx2<=5;dx2++){
    			for (int dy2=-5;dy2<=5;dy2++){
    				trace_it(dx1,dy1,dx2,dy2);
    				cout<<dx1<<" "<<dy1<<" "<<dx2<<" "<<dy2<<endl;
    				show_it();
    				cin.get();
    			}
    		}
    	}
    }
*/

    long long n;
    cin>>n;
    cin>>dx1>>dy1>>dx2>>dy2;

    if (dx1==0&&dy1==0){
    	cout<<"NO"<<endl;
    	return 0;
    }

    if (dx2==0&&dy2==0){
    	cout<<"NO"<<endl;
    	return 0;
    }
    // now both make some sense

    pair<long long, long long> p1=make_pair(dx1,dy1);
    pair<long long, long long> p2=make_pair(dx2,dy2);

    p1=normalize(p1);
    p2=normalize(p2);

    for (int iter=1;iter<=200;iter++)iterate_gcd(p1,p2);

//    cout<<p1.first<<" "<<p1.second<<endl;
//    cout<<p2.first<<" "<<p2.second<<endl;

    long long need=p2.second*p1.first;
    if (need!=n){
    	cout<<"NO"<<endl;
    	return 0;
    }

    cout<<"YES"<<endl;
    for (int i=0;i<p1.first;i++){
    	for (int j=0;j<p2.second;j++){
    		cout<<i<<" "<<j<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}