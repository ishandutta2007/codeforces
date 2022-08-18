/*
Live by the sword and help to contain
The helpless minds of you all
Die by my hand in pools of blood
Clutch yourself as you fall
Mindless tyranny, forgotten victims
Children slaughtered in vain
Raping the maids, in which they serve
Only the words of the Lord

Die by the sword
Die by the sword

Satan watches all of us
Smiles as some do his bidding
Try to escape the grasp of my hand
And your life will no longer exist
Hear our cry, save us from
The Hell in which we live
We turn our heads toward the sky
And listen for the steel

Die by the sword
Die by the sword

Watch as flowers decay
On (the) cryptic life that died
The wisdom of the wizards
Is only a neurtured lie
Black knights of Hell's domain
Walk upon the dead
Satanas sits upon
The blood on which he feeds

Die by the sword
Die by the sword
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

const int N = 300031;

long long k,n,m;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m>>k;
	if (k<n){
		cout<<k+1<<" "<<1<<endl;
		return 0;
	}
	k-=(n-1);
	--k;
	long long full=k/(m-1);
	long long rem=k%(m-1);

	cout<<n-full<<" ";
	if (full%2==0)
		cout<<2+rem;
	else
		cout<<m-rem;
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}