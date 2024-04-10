/*
Back again within myself
Asleep but aware i'm lost again
Every time i close my eyes
I enter the dream to which i'm strained
A sudden change into a state
Where life is dust
And everything flow
Circling above swirling seas
Of eyes upraised toward the unknown
 
Vapour masques in the leaden air
Unleashed by death in a grubby dawn
Vacant faces reflecting sorrow
Hidden inside senses disowned
A maze of glass shattered by thoughts
Of a faltered soul freed in bliss
Clouds disperse revealing shades
Tempting my soul i can't resist
 
A vision of morbidity
Of ragged silent shadows
Dressed in black disease
They're closing up on me
Peering lifeless weary eyes
They drag me down into
Another world inside of me
 
Paralyzed by the view
Hypnotized let me wake
 
Mesmerized by the flames as i return
Into myself a slow conversion a silent
Change i wake into the brightened day
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
 
int win[200][200];
 
bool bad(int i,int j,int k,int d){
	i*=k;
	j*=k;
	return (i*i+j*j>d*d);
}
 
int smart(long long d,long long k){
	long long diag_times=sqrt(d*d*0.5+0.4);
	diag_times/=k;
	long long dx=k*diag_times;
	long long dy=k*(diag_times+1);
	//cout<<dx<<" "<<dy<<endl;
	if (1ll*dx*dx+1ll*dy*dy>1ll*d*d)
		return 0;
	return 1;
}
 
long long solver(int n,int k){
	return smart(n,k);
}
 
void do_naive(int d,int k){
	for (int i=0;i<=d/k+1;i++){
		for (int j=0;j<=d/k+1;j++){
			win[i][j]=0;
		}
	}
	for (int i=d/k+1;i>=0;--i){
		for (int j=d/k+1;j>=0;--j){
			//if (i==10&&j==11)
			//	cout<<bad(i,j,k,d)<<"@@@"<<endl;
			if (bad(i,j,k,d)){
				win[i][j]=1;
				continue;
			}
			if (win[i+1][j]==0||win[i][j+1]==0)
				win[i][j]=1;
		}
	}
	for (int i=d/k;i>=0;--i){
		for (int j=0;j<=d/k;j++){
			cout<<win[i][j];
		}
		cout<<endl;
	}
	cout<<smart(d,k)<<endl;//" "<<win[10][10]<<" "<<win[10][11]<<endl;
}
 
int n,k;
 
int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
 
    int tests;
    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
//    	do_naive(n,k);
    	if (solver(n,k))
    		cout<<"Ashish"<<endl;
    	else
    		cout<<"Utkarsh"<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}