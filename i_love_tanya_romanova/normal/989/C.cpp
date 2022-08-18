/*
After the war and now that they've sent us homeward
I can't help but feel that I'm on my own
No one can see just what this conflict has done to
The minds of the man who are on their way home

I'm scared for life but it's not my flesh that's wounded
So how can I face the torment alone
The vivid scenes and all the recurring nightmares
I lay there and sweat until it gets light...

People say "Don't worry"
Say that time's a perfect healer
That the nightmares they will come to pass
Can't hear what they're saying
I am living in my own world
And I'm feeling trance like all the time

I hear voices in my head
Could I really be going crazy
In the night the visions seem so real
Do you care if you live or die
When you laugh are you really crying
You're not sure what's real anymore

Fortunes of war
Fortunes of war no pain anymore

Sometimes I wake
I feel that my spirit's broken
I wonder if I've the strenght... to carry on.
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
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

int a,b,c,d;
char ans[200][200];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>a>>b>>c>>d;

	cout<<50<<" "<<50<<endl;

	for (int i=1;i<=25;i++){
		for (int j=1;j<=50;j++){
			ans[i][j]='A';
		}
	}
	--a;
	for (int i=26;i<=50;i++){
		for (int j=1;j<=50;j++){
			ans[i][j]='B';
		}
	}
	--b;

	for (int i=1;i<25;i++){
		for (int j=1;j<=50;j++){
			if (i%2==1&&j%2==1){
				if (b){
					ans[i][j]='B';
					--b;
				}
			}
		}
	}

	for (int i=27;i<=50;i++){
		for (int j=1;j<=50;j++){
			if (i%2==1&&j%2==1){
				if (a){
					ans[i][j]='A';
					--a;
				}
			}
		}
	}

	for (int i=1;i<=50;i++){
		for (int j=1;j<=50;j++){
			if (i%2==1&&j%2==1&&i!=25){
				if (i<25&&ans[i][j]=='B')
					continue;
				if (i>25&&ans[i][j]=='A')
					continue;
				if (c){
					ans[i][j]='C';
					--c;
					continue;
				}
				if (d){
					ans[i][j]='D';
					--d;
					continue;
				}
			}
		}
	}

	for (int i=1;i<=50;i++){
		for (int j=1;j<=50;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}