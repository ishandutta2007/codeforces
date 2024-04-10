/*
No time to wait around today
Lets get fucked up its time to rage
A couple of parties up the street
Bare witness to a drunken fleet
I begin to stumble down the hall
I spot a keg and I want it all
I want it all

Let's have a round
Let's drink this keg till it's zero pounds
Does this beer taste kind of strange?
As things begin to quickly fade
I get the feeling something is wrong
Something is wrong

At first it seemed all normal some guys in a fight
But looking closer something is not right
The blood began to splatter the violence quickly spreads
Something fucked up was put in that keg!

Violence
Door to door
Disfigured and we declare war!
Panic
We're maniacs our legions grow with every attack!

Somehow were chemically altered
Some kind of reaction making us stronger
A plague with no mercy we spread
We'll never give up till everyone's slaughtered

Somehow were chemically altered
Some kind of reaction making us stronger
A plague with no mercy we spread
We'll never give up till everyone's slaughtered

Our fight to end humanity is spreading out into the streets
Setting fires, slicing cops
Our lust for blood will never stop
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

const int bs = 998244353;

const int N = 600031;

int C[1000];

void do_gen(){
	int cnt=0;
	while (true){
		if (rand()%2)
			++cnt;
		else
			break;
	}
	C[cnt]++;
}

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x){
	return pw(x,bs-2);
}

int n,m;
vector<int> g[N],gr[N];
int outdeg[N];
int done[N];
int sg[N];

vector<int> values;

vector<int> make_unique(vector<int> v){
	sort(v.begin(),v.end());
	vector<int> ret;
	for (int i=0;i<v.size();i++){
		if (i==0||v[i]!=v[i-1])
			ret.push_back(v[i]);
	}
	return ret;
}

void calculate_sg(int v){
	if (done[v])
		return;
	done[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		calculate_sg(to);
	}
	values.clear();
	values.push_back(-1);
	values.push_back(1e9);

	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		values.push_back(sg[to]);
	}
	values=make_unique(values);
	for (int i=1;i<values.size();i++){
		if (values[i]!=values[i-1]+1)
		{
			sg[v]=values[i-1]+1;
			break;
		}
	}
}

long long dp[1000],new_dp[1000];

long long C1[1000][1000];
long long C2[1000];

void do_cool_gen(){
	int a=0;
	int b=0;
	while (true){
		int here=rand()%3;
		if (here==0)
			a++;
		else if (here==1)
			b++;
		else break;
	}
	C1[a][b]++;
}

double prob[100000];
int cnt_with[N];
long long chance[1000][1000];

const int SZ = 512;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    /*for (int i=1;i<=1000000;i++){
    	do_gen();
    }
    long long S=0;
    for (int i=0;i<=10;i++){
    	cout<<C[i]<<endl;
    	if (i%2==0)
    		S+=C[i];
    	prob[i]=C[i]*1.0/1000000;
    }

    cout<<S<<endl;


    for (int i=0;i<10000000;i++){
    	do_cool_gen();
    }

    for (int i=0;i<10;i++){
    	for (int j=0;j<10;j++){
    		cout<<i<<" "<<j<<" "<<C1[i][j]<<" "<<prob[i]*prob[j]*10000000<<endl;
    		C2[i]+=C1[i][j];
    	}
    	cout<<endl;
    }
    cout<<endl;
    for (int i=0;i<10;i++){
    	cout<<C2[i]<<" ";
    }
    cout<<endl;
*/

    cin>>n>>m;
    for (int i=0;i<m;i++){
    	int a,b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	gr[b].push_back(a);
    	outdeg[a]++;
    }

    for (int i=1;i<=n;i++){
    	calculate_sg(i);
    }

    for (int i=1;i<=n;i++){
    	cnt_with[sg[i]]++;
    }

    long long invN=inv(n+1);

    for (int i=0;i<SZ;i++){
    	for (int j=0;j<SZ;j++){
    		chance[i][i^j]+=cnt_with[j]*invN;
    		chance[i][i^j]%=bs;
    	}
    	if (i!=0)
    		chance[i][SZ]=invN;
    }

    for (int i=0;i<SZ;i++){
    	for (int j=0;j<SZ;j++){
    		if (i==j)
    			chance[i][j]=(1-chance[i][j]+bs)%bs;
    		else
    			chance[i][j]=(bs-chance[i][j])%bs;
    	}
    }

   /* for (int i=0;i<=SZ;i++){
    	for (int j=0;j<=SZ;j++){
    		cout<<chance[i][j]<<" ";
    	}
    	cout<<endl;
    }
*/
    for (int i=0;i<SZ;i++){
    	for (int j=0;j<i;j++){
    		if (chance[i][j]!=0){
    			long long times=chance[i][j];
    			for (int q=0;q<=SZ;q++){
    				chance[i][q]-=chance[j][q]*times;
    				chance[i][q]%=bs;
    				if (chance[i][q]<0)
    					chance[i][q]+=bs;
    			}
    		}
    	}

    	if (chance[i][i]!=1){
    		long long Q=inv(chance[i][i]);
    		for (int j=0;j<=SZ;j++){
    			chance[i][j]*=Q;
    			chance[i][j]%=bs;
    		}
    	}

    }

/*    cout<<endl;
    for (int i=0;i<=SZ;i++){
    	for (int j=0;j<=SZ;j++){
    		cout<<chance[i][j]<<" ";
    	}
    	cout<<endl;
    }
    cout<<endl;
*/
    for (int i=SZ;i>=0;--i){
    	for (int j=i+1;j<SZ;j++){
    		if (chance[i][j]!=0){
    			long long times=chance[i][j];
    			for (int q=0;q<=SZ;q++){
    				chance[i][q]-=chance[j][q]*times;
    				chance[i][q]%=bs;
    				if (chance[i][q]<0)
    					chance[i][q]+=bs;
    			}
    		}
    	}
    }

    cout<<chance[0][SZ]*inv(chance[0][0])%bs<<endl;

    //cin.get(); cin.get();
    return 0;
}