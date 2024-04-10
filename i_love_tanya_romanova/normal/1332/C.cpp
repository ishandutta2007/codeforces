/*
Devoid of life
Far from the strengthening force
From which it feeds
The unbroken silence swear allegiance to thee
Behold the answers that darkness sets free

Freedom beyond the enslavement

Never let loose upon the world
Con we forgive the enchanter that
Dance beyond the skyline dark
The stains of fire, the one begotten ancestor
To one of far greater strength
Starvation divine

For he shall stand no taller than the flames
That is his feed
Let us not go gently
Into the endless winternight
We are but strangers
Acting on our fragmentary perception

Perception is the lie of the misled
Things are not what they appear
So swear by your deception

There shan't be fire, nor shall the flame
Quench the desire to reign
With fear of its dawning
Appears now in sight
The one brooding warning
Stand clearer than night

Devoid of life
Far from the strengthening force
From which it feeds
The unbroken silence swear allegiance to thee
Behold the answers that darkness sets free

Freedom beyond the enslavement
Never let loose upon the world
Con we forgive the enchanter that
Dance beyond the skyline dark

There shan't be fire, nor shall the flame
Quench the desire to reign
With fear of its dawning
Appears now in sight
The one brooding warning
Stand clearer than night
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

#define bs 998244353

const int N = 600031;

int tests,n,k;
int w[N];
int cnt[N][27];
string st;

int get(int x){
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b){
	a=get(a);
	b=get(b);
	w[a]=b;
}

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n>>k;
		for (int i=1;i<=n;i++){
			w[i]=i;
		}
		for (int i=1;i<=n;i++){
			merge(i,n-i+1);
		}
		for (int i=1;i+k<=n;i++){
			merge(i,i+k);
		}

		cin>>st;
		for (int i=1;i<=n;i++){
			for (int j=0;j<26;j++){
				cnt[i][j]=0;
			}
		}

		for (int i=1;i<=st.size();i++){
			int id=get(i);
			cnt[id][st[i-1]-'a']++;
		}

		int saved=0;
		for (int i=1;i<=n;i++){
			if (get(i)!=i)
				continue;
			int mx=0;
			for (int j=0;j<26;j++){
				mx=max(mx,cnt[i][j]);
			}
			saved+=mx;
		}

		cout<<n-saved<<endl;
	}

  //    cin.get(); cin.get();
  return 0;
}