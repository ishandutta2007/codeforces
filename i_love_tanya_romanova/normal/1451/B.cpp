/*
I don't need religion
God bless no one
Me and my own opinions
Are written by me
You surrender
Under mass hypnosis
Bound to illusions
Produced by your god

Who is humane
Real alive no god

I see your blindness
Erase your identity
Your mind is hollow
Carved to inability
I know to be
Loyal to myself
My integrity leaves myself
Alone in peace with me

God

There's no god
Life is a trap
Unlock your mind
Trust in yourself

Wake from the grip of the tongue
You've been choked oppressed
God owns god cheats god lies
God hates god kills god slays

The pressure on humanity
Has risen beyond control
We are leading evolution
Into termination
The sense of hate
Inbreeding scars to innocence
Genetic prejudice a
Selfdestructive line in pain

Why this reality
Life poured into inanity
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

int tests,n,q;
string st;
vector<int> v[3];
int interesting_l[N],interesting_r[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>q;
    	cin>>st;
    	for (int i=1;i<=n;i++){
    		interesting_l[i]=interesting_r[i]=0;
    	}
    	v[0].clear();
    	v[1].clear();
    	for (int i=0;i<st.size();i++){
    		v[st[i]-'0'].push_back(i);
    	}
    	if (v[0].size()){
    		interesting_l[v[0][0]+1]=1;
    		interesting_r[v[0].back()+1]=1;
    	}
    	if (v[1].size()){
    		interesting_l[v[1][0]+1]=1;
    		interesting_r[v[1].back()+1]=1;
    	}
    	for (;q;--q){
    		int l,r;
    		cin>>l>>r;
    		if (interesting_l[l]&&interesting_r[r])
    			cout<<"NO"<<endl;
    		else
    			cout<<"YES"<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}