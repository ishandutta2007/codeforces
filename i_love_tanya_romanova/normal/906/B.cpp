/*
As I sit here and slowly close my eyes
I take another deep breath
And feel the wind pass through my body
I'm the one in your soul
Reflecting inner light
Protect the ones who hold you
Cradling your inner child

I need serenity
In a place where I can hide
I need serenity
Nothing changes, days go by

Where do we go when we just don't know
And how do we relight the flame when it's cold
Why do we dream when our thoughts mean nothing
And when will we learn to control

Tragic visions slowly stole my life
Tore away everything
Cheating me out of my time
I'm the one who loves you
No matter wrong or right
And every day I hold you
I hold you with my inner child

I need serenity
In a place where I can hide
I need serenity
Nothing changes, days go by

Where do we go when we just don't know
And how do we relight the flame when it's cold
Why do we dream when our thoughts mean nothing
And when will we learn to control

Where do we go when we just don't know
And how do we relight the flame when it's cold
Why do we dream when our thoughts mean nothing
And when will we learn to control

I need serenity [x2]
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 510031;

int n,m;
vector<pair<int,int> > odd,even;

void show_vec(vector<vector<pair<int,int> > > &v){
	for (int i=0;i<v.size();i++){
		for (int j=0;j<v[i].size();j++){
			if (j)
				printf(" ");
			printf("%d",v[i][j].first*v[0].size()+v[i][j].second+1);
		}
		printf("\n");
	}
}

bool bad(pair<int,int> p1,pair<int,int> p2){
	if (p1.first==p2.first&&abs(p1.second-p2.second)==1)
		return true;
	if (p1.second==p2.second&&abs(p1.first-p2.first)==1)
		return true;
	return false;
}

bool bad_place(vector<vector<pair<int,int>  > > &v,int a,int b){
	for (int dx=-1;dx<=1;dx++){
		for (int dy=-1;dy<=1;dy++){
			if (abs(dx)+abs(dy)!=1)
				continue;
			if (a+dx<0||b+dy<0||a+dx>=v.size()||b+dy>=v[0].size())
				continue;
			if (bad(v[a][b],v[a+dx][b+dy]))
				return true;
		}
	}
	return false;
}

bool valid(vector<vector<pair<int,int> > >& v){
	int n=v.size();
	int m=v[0].size();

	for (int i=0;i+1<n;i++){
		for (int j=0;j<m;j++){
			if (bad(v[i][j],v[i+1][j]))
				return false;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j+1<m;j++){
			if (bad(v[i][j],v[i][j+1]))
				return false;
		}
	}
	return true;
}


vector<vector<pair<int,int> > > solver2(int n,int m,int iters){
	vector<pair<int,int> > t;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			t.push_back(make_pair(i,j));
		}
	}

	vector<vector<pair<int,int> > > ret;

	ret.resize(n);
	for (int i=0;i<n;i++){
		ret[i].resize(m);
	}

	random_shuffle(t.begin(),t.end());
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			ret[i][j]=t[i*m+j];
		}
	}

	for (int iter=1;iter<=iters;iter++){
		if (clock()*1.0/CLOCKS_PER_SEC>1.5)
			break;
		vector<pair<int,int> > v;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (bad_place(ret,i,j))
					v.push_back(make_pair(i,j));
			}
		}
		if (v.size()==0){
	//		cout<<iter<<endl;
		//	while (true);
			return ret;
		}

		int id=rand()%v.size();
		int a=rand()%n;
		int b=rand()%m;
		swap(ret[v[id].first][v[id].second],ret[a][b]);
	}
	ret.clear();
	return ret;
}


vector<vector<pair<int,int> > > solver(int n,int m,int iters){
	vector<pair<int,int> > t;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			t.push_back(make_pair(i,j));
		}
	}

	vector<vector<pair<int,int> > > ret;

	ret.resize(n);
	for (int i=0;i<n;i++){
		ret[i].resize(m);
	}

	for (int iter=1;iter<=iters;iter++){
		random_shuffle(t.begin(),t.end());
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				ret[i][j]=t[i*m+j];
			}
		}
		if (valid(ret)){
		//	cout<<n<<"@"<<m<<" "<<iter<<endl;
			return ret;}
	}
	ret.clear();
	return ret;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	srand(time(NULL));

	/*int n,m;
	while (true){
		cin>>n>>m;
		vector<vector<pair<int,int> > > V=solver(n,m,10000);
		show_vec(V);
	}*/
/*
	for (int n=1;n<=30;n++){
		for (int m=1;m<=30;m++){
			vector<vector<pair<int,int> > > V=solver2(n,m,10000);
			if (V.size()==0){
				//cout<<n<<"@@@"<<m<<endl;
				vector<vector<pair<int,int> > >V2=solver(n,m,100000);
				//cout<<n<<"@"<<m<<endl;
				if (V2.size()!=0){
					cout<<"SHIT "<<n<<" "<<m<<endl;
					show_vec(V2);
					while (true);}
			}
			cout<<"OK"<<endl;
			if (V.size()==0){
				cout<<n<<" "<<m<<" BAD"<<endl;
			}
			else
			{
			//	cout<<n<<"$"<<m<<endl;
			//	show_vec(V);
			}
		}
	}

*/

	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int> > > v=solver2(n,m,1000000);
	if (v.size()==0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		show_vec(v);
	}

	cin.get(); cin.get();
	return 0;
}