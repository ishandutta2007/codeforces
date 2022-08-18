/*
We will not return to the countless mistakes of the past
I will not relive the failures of the man I once was

Only through dedication will I destroy all preconception

No longer will I let myself be truly satisfied with the standard
We will not return to the countless mistakes of the past

Only through dedication will I destroy all preconception

Let this be
Be the day
Day of my
My declaration
Let this be the day of my declaration

Join me,
Walk with me

Shatter the bonds that tie us
To what we strive to never be

Join me,
Walk with me
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 1200031;

int n,a,b,ar[1031][1031];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>a>>b;

	if (a>1&&b>1){
		cout<<"NO"<<endl;
	}
	else if (a>1||b>1)
	{
		cout<<"YES"<<endl;
		int need=max(a,b);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i<=n-need+1&&j<=n-need+1&&i!=j)
					ar[i][j]=1;
				else
					ar[i][j]=0;
			}
		}
		if (a==1){
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					if (i!=j){
						ar[i][j]^=1;
					}
				}
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				cout<<ar[i][j];
			}
			cout<<endl;
		}
	}
	else
	{
		if (n==2||n==3){
			cout<<"NO"<<endl;
		}
		else if (n==4){
			ar[1][3]=ar[1][4]=ar[4][1]=ar[3][1]=1;
			ar[2][4]=1;
			ar[4][2]=1;
			cout<<"YES"<<endl;
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					cout<<ar[i][j];
				}
				cout<<endl;
			}
		}
		else
		{
			cout<<"YES"<<endl;
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					if (abs(i-j)==1){
						cout<<1;
					}
					else
						cout<<0;
				}
				cout<<endl;
			}
		}
	}

//	cin.get(); cin.get();
	return 0;
}