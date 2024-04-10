/*
You know everybody's scared, everybody better beware
Scared of spiders, scared of rats, scared of being crossed by cats
Scared of everything that moves and things with cloven hooves

I ain't scared, live my life all right, I ain't scared to stand and fight
I ain't scared 'cause I believe, ain't scared to wear my heart on my sleeve
Ain't scared to show my hands but I'm scared of the boogeyman

You can't boogie with the boogeyman, you can't boogie with the boogeyman
You can't boogie with the boogeyman, you can't boogie with the boogeyman
Hold out any way you can but don't mess with the boogeyman

He's hiding underneath your bed, he's hiding inside your head
He's hiding behind your eye, he'd be there until you die
Ridin' shotgun in your new transam, slide over for the boogeyman

You can't boogie with the boogeyman, you can't boogie with the boogeyman
You can't boogie with the boogeyman, you can't boogie with the boogeyman
Hold out any way you can but don't mess with the boogeyman

You can't boogie with the boogeyman, you can't boogie with the boogeyman
You can't boogie with the boogeyman, you can't boogie with the boogeyman
Hold out any way you can but don't mess with the boogeyman, hey
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 128

const int N = 12500;

using namespace std;

int a,b,c,d,e,f;

int solve()
{
	bool free_lead;
	bool free_sand;
	bool free_gold;
	free_lead=(a==0&&b>0);
	free_gold=(c==0&&d>0);
	free_sand=(e==0&&f>0);
	bool working_gold=(d>0);
	bool working_lead=(b>0);
	bool working_sand=(f>0);
	
	if (free_gold)
		return 1;
	if (!working_gold)
		return 0;
	if (free_lead&&working_gold)
		return 1;
	if (free_sand&&working_lead&&working_gold)
		return 1;
	if (!working_lead)
		return 0;
	if (!working_sand)
		return 0;
	long double have_sand=1;
	long double have_lead=have_sand/a*b;
	long double have_gold=have_lead/c*d;
	long double new_sand=have_gold/e*f;
	if (new_sand>1+1e-15)
		return 1;
	return 0;
}

int main(){
//	freopen("path2.in","r",stdin);
//	freopen("path2.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>a>>b>>c>>d>>e>>f;
	
	if (solve())
		cout<<"Ron"<<endl;
	else
		cout<<"Hermione"<<endl;
	
	return 0;
}