/*
Again we stalk the stage
At mach speed we engage
Feeding people's rage
The big cat's left it's cage
Back in the bus again
To catch another plane
The behavior's quite insane
But we do it for the fame, yeah

I lost my mind, I lost all my money
I lost my life to the killing road

The road will never end
It always starts again
Another show's around the bend
Another long lost friend
Faceless as the snow
There's nothing special about the road
It's just another haul
It's just too damn long that's all, yeah
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

const int N = 200031;

int n,m,a[N],b[N];
int w[N];

int get(int x){
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b)
{
	a=get(a);
	b=get(b);
	w[a]=b;
}

long long total_cost;
vector<pair<int,pair<int,int> > > edges;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>m>>n;
    for (int i=1;i<=m;i++){
    	cin>>a[i];
    }
    for (int i=1;i<=n;i++){
    	cin>>b[i];
    }

    for (int i=1;i<=m+n;i++){
    	w[i]=i;
    }

    for (int i=1;i<=m;i++){
    	int sz;
    	cin>>sz;
    	for (int j=1;j<=sz;j++){
    		int id;
    		cin>>id;
    		int cost=b[id]+a[i];
    		total_cost+=cost;
    		edges.push_back(make_pair(cost,make_pair(i,id+m)));
    	}
    }

    sort(edges.begin(),edges.end());
    reverse(edges.begin(),edges.end());

    for (int i=0;i<edges.size();i++){
    	int v1=edges[i].second.first;
    	int v2=edges[i].second.second;
    	if (get(v1)==get(v2))
    		continue;
    	total_cost-=edges[i].first;
    	merge(v1,v2);
    }

    cout<<total_cost<<endl;

    //cin.get(); cin.get();
    return 0;
}