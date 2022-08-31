/*
Imagine Humanity's decline
Step inside my stain of mind
Infesting superiority
Infectious immorality oh yea
Come worship the place no truths are told
Praise the land where sins are sold
No passion no love your faith evades
Never see yourself again that way
Death becomes your bride
Lifelessness invades your eyes
In fire baptized
All pain sifts through myu soul
You'll never feel greater misery
Master of my enemy
Let the purest stain of mind
Wash the virtue from your eyes
As one the collective unifies
Emanate a faithless shine
Forever creation has conceived
Birth of destruction spreads its wings oh yea
Chaotic rebirth a new domain
Re-live the sight the sound the pain
Erotic the taste of agony
Adorn the scars of inhumanity
This is what you see
Deep inside of me
Agony is life
Lechery is life
Godlessness is life
Purgatory magnified
In fire baptized
All pain sifts through my soul
You'll never feel greater misery
Master of my enemy
Let the purest stain of mind
Wash the virtue from your eyes
Enticing malevolence allures
Bastardize the clean and pure
Salvation forever crucified
I choose the other side oh yea
Entire, complete serenity
Injected intravenously
Transgression euphoric bliss divine
Initiate a timeless stain of mind
Blood will sterilize
In fire I baptized
All pain sifts through my soul
You'll never feel greater misery
Master of my enemy
Let the purest stain of mind
Wash the virtue from your eyes
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
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int a[N],b[N];
int ansa,ansb;

int zero_query(){
	cout<<"? 0 0"<<endl;
	int ret;
	cin>>ret;
	return ret;
}

int query(int ps,int in_a,int in_b){
	int query_a=0;
	int query_b=0;
	for (int i=29;i>=0;--i){
		if (a[i])
			query_a|=(1<<i);
		if (b[i])
			query_b|=(1<<i);
	}
	query_a|=(1<<ps)*in_a;
	query_b|=(1<<ps)*in_b;
	cout<<"? "<<query_a<<" "<<query_b<<endl;
	int val;
	cin>>val;
	return val;
}

int suf_query(int ps){
	int pref_a=0;
	int pref_b=0;
	for (int i=29;i>ps;--i){
		pref_a|=(1<<i)*a[i];
		pref_b|=(1<<i)*b[i];
	}
	cout<<"? "<<pref_a<<" "<<pref_b<<endl;
	int val;
	cin>>val;
	return val;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	int cur_sign=zero_query();

	for (int ps=29;ps>=0;--ps){
		if (cur_sign==0)// suf already equal
		{
			int this_position=query(ps,1,0);
			if (this_position==-1) //  a got smaller
			{
				a[ps]=1;
				b[ps]=1;
			}
			else
			{
				a[ps]=0;
				b[ps]=0;
			}
			continue;
		}

		if (cur_sign==1) // a is larger so far
		{
			int this_position=query(ps,1,1);
			if (this_position==1){ // a is still larger after bit inversion; same bits
				int guess=query(ps,1,0);
				if (guess==-1)
					a[ps]=b[ps]=1;
				else
					a[ps]=b[ps]=0;
			}
			else	 // a got smaller; it means 1 vs 0
			{
				a[ps]=1;
				b[ps]=0;
				cur_sign=suf_query(ps-1);
			}
			continue;
		}

		if (cur_sign==-1){
			int this_position=query(ps,1,1);
			if (this_position==-1) // b is still larger after bit inversion; same bits
			{
				int guess=query(ps,0,1);
				if (guess==-1) // switching keeps it smaller
					a[ps]=b[ps]=0;
				else
					a[ps]=b[ps]=1;
			}
			else
			{
				a[ps]=0;
				b[ps]=1;
				cur_sign=suf_query(ps-1);
			}
		}
	}

	cout<<"!";
	for (int i=0;i<=29;i++)
		ansa+=(1<<i)*a[i],
		ansb+=(1<<i)*b[i];

	cout<<"  "<<ansa<<" "<<ansb<<endl;

//    cin.get(); cin.get();
    return 0;
}