/*
Voice is a weapon, bombs are away
Mind's a trigger, fire away
World's in a crossfire, of panic and fear
The war is upon us, I say it starts here

We will take control
Of this abortion called society
I despise the mediocrity
Inject the system with something new
A social terror to lead the few

Why call it the land of the free?
Political banter - If you ask me
Diffusing a problem, the question is how
With imminent conflict, the answer starts now

I can say
We're not the answer to the world's decay
Here to stay
We're just the ones who won't go away

We will take control
Of this disaster called society
I despise the mediocrity
So now I'm going to introduce
A social terror that's on the loose

I am the propaganda war machine
The face of fury and obscenity
So when society has gone astray
I'll be the one to pave the way
They'll never fuck with my reality
'Cause this right here to me is unity
When all is done we'll have always shown
A domination that was never known

We will take control
Of this abortion called society
I despise the mediocrity
We are the torch that lights the fuse
A social terror with nothing to lose
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

#define bs 1000000007

const int N = 200031;

int pr[N],good[N];
vector<int> interesting;
int tests,found;
int n;

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  pr[1]=1;
  for (int i=2;i<N;i++){
	  if (pr[i]==0){
		  for (int j=i*2;j<N;j+=i){
			  pr[j]=1;
		  }
	  }
  }

  for (int i=2;i<=N;i++){
	  for (int j=i+1;1ll*j*j<=2e5;j++){
		  if (pr[i]==0&&pr[j]==0)
			  good[i*j]=1;
	  }
  }

  for (int i=2;i<N;i++){
	  if (good[i])
		  interesting.push_back(i);
  }

  cin>>tests;
  for (;tests;--tests){
	cin>>n;
	found=0;

	for (int i=0;i<10;i++){
		for (int j=i+1;j<10;j++){
			for (int q=j+1;q<10;q++){
				if (found)
					break;
				int rem=n-interesting[i]-interesting[j]-interesting[q];
				if (rem<=0||rem==interesting[i]||rem==interesting[j]||rem==interesting[q])
					continue;
				found=1;
				cout<<"YES"<<endl;
				cout<<interesting[i]<<" "<<interesting[j]<<" "<<interesting[q]<<" "<<rem<<endl;
			}
		}
	}

	if (!found)
		cout<<"NO"<<endl;
  }

  cin.get(); cin.get();
  return 0;
}