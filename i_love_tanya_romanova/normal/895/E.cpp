/*
Don't you say a word to me
Always barking up my tree
I don't need no more grief, no more third degree
Turn sunshine into rain
Turn pleasure into shame
Turn everything I say, inside out again

It seems, it seems the same
It seems, I ain't to blame
It seems, that you're insane
Don't you take my name in vain

Tell me what a dog I am
Tell me it's 'cause I'm a man
Tell you what, who gives a damn
Just another scam
Ain't me that's wrong this time
Ain't me that's out of line
Ain't me, it ain't my crime
Your rap, 'cause it ain't mine

It seems, it seems the same
It seems, I ain't to blame
It seems, that you're insane
Don't you take my name in vain

Seems like you know the rules
I know you ain't no fool, you think you're somethin' else,
You look pretty cool,
You ought to reconsider, I ain't no Indian giver
I been as fair as I know how so shut your mouth

You know it all seems
It's only in your dreams
I'm getting sick to death of swimming up the stream
I'm gonna ask you nice, and then I'll ask you twice
If that don't work you get your ass back in your jeans

Seems to me, seems the same
Seems to me, I ain't to blame
Seems to me that you're insane
Don't you take my name in vain
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

const int N = 510031;

int n,tests;
long double A[N],B[N];

int ar[N];
int tp;

pair<double,double> make_naive_query(int l,int r){
	pair<double,double> res=make_pair(0,0);
	for (int i=l;i<=r;i++){
		res.first+=A[i];
		res.second+=B[i];
	}
	return res;
}

void make_naive_mult(int l,int r,double p){
	for (int i=l;i<=r;i++)
	{
		B[i]*=p;
		A[i]*=p;
	}
}

void make_naive_add(int l,int r,double val,double chance){
	for (int i=l;i<=r;i++){
		A[i]+=val;
		B[i]+=chance;
	}
}

long double tA[N],tB[N],toaddA[N],toaddB[N],tomultA[N],tomultB[N];

void push(int v,int tl,int tr){
	int tm=tl+tr;
	tm/=2;

	tA[v*2]*=tomultA[v];
	tA[v*2]+=toaddA[v]*(tm-tl+1);

	toaddA[v*2]*=tomultA[v];
	toaddA[v*2]+=toaddA[v];
	tomultA[v*2]*=tomultA[v];

	tA[v*2+1]*=tomultA[v];
	tA[v*2+1]+=toaddA[v]*(tr-tm);

	toaddA[v*2+1]*=tomultA[v];
	toaddA[v*2+1]+=toaddA[v];
	tomultA[v*2+1]*=tomultA[v];

	toaddA[v]=toaddB[v]=0;
	tomultA[v]=tomultB[v]=1;
}

void make_mult(int v,int tl,int tr,int l,int r,long double p){
	if (l>r)
		return;
	if (tl==l&&tr==r){
		tA[v]*=p;
		tB[v]*=p;
		toaddA[v]*=p;
		tomultA[v]*=p;
		return ;
	}
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	make_mult(v*2,tl,tm,l,min(r,tm),p);
	make_mult(v*2+1,tm+1,tr,max(tm+1,l),r,p);
	tA[v]=tA[v*2]+tA[v*2+1];
	tB[v]=tB[v*2]+tB[v*2+1];
}

void make_add(int v,int tl,int tr,int l,int r,long double p1,long double p2){
	if (l>r)
		return;
	//cout<<p1<<"%%"<<p2<<endl;
	if (tl==l&&tr==r){
		tA[v]+=p1*(r-l+1);
		tB[v]+=p2*(r-l+1);
		toaddA[v]+=p1;
		toaddB[v]+=p2;
//		tomultA[v]+=p1;
//		tomultB[v]+=p2;
		return ;
	}
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	make_add(v*2,tl,tm,l,min(r,tm),p1,p2);
	make_add(v*2+1,tm+1,tr,max(tm+1,l),r,p1,p2);
	tA[v]=tA[v*2]+tA[v*2+1];
	tB[v]=tB[v*2]+tB[v*2+1];
}

pair<long double,long double> make_query(int v,int tl,int tr,int l,int r){
	if (l>r)
		return make_pair(0,0);
	if (tl==l&&tr==r)
		return make_pair(tA[v],tB[v]);
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	pair<long double,long double> p1=make_query(v*2,tl,tm,l,min(r,tm));
	pair<long double,long double> p2=make_query(v*2+1,tm+1,tr,max(tm+1,l),r);
	p1.first+=p2.first;
	p1.second+=p2.second;
	return p1;
}

void build(int v,int tl,int tr){

	toaddA[v]=0;
	toaddB[v]=0;
	tomultA[v]=1;
	tomultB[v]=1;

	if (tl==tr){
		tA[v]=ar[tl];
		tB[v]=1.0;
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	tA[v]=tA[v*2]+tA[v*2+1];
	tB[v]=tB[v*2]+tB[v*2+1];
	return ;
}


int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>tests;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}

	for (int i=1;i<=n;i++){
		A[i]=ar[i];
		B[i]=1.0;
	}

	build(1,1,n);

	for (;tests;--tests){
		cin>>tp;
		if (tp==2) // query
		{
			int l,r;
			cin>>l>>r;
//			pair<double,double> P=make_naive_query(l,r);
			pair<long double,long double> P=make_query(1,1,n,l,r);
			cout.precision(7);
//			cout<<P.first<<"@"<<P.second<<endl;
			cout<<fixed<<P.first<<"\n";
		}
		else // update
		{
			int l1,r1,l2,r2;
			cin>>l1>>r1>>l2>>r2;
			//pair<double,double> P1=make_naive_query(l1,r1);
			pair<long double,long double> P1=make_query(1,1,n,l1,r1);

			//pair<double,double> P2=make_naive_query(l2,r2);
			pair<long double,long double> P2=make_query(1,1,n,l2,r2);

			//cout<<P1.first<<" "<<P1.second<<" "<<P2.first<<" "<<P2.second<<endl;

			long double ev1=P1.first/(r1-l1+1);
			long double ev2=P2.first/(r2-l2+1);

/*			cout<<"@@@"<<ev1<<" "<<ev2<<endl;

			for (int j=1;j<=n;j++){
				cout<<A[j]<<"  "<<B[j]<<endl;
			}
*/
//			make_naive_mult(l1,r1,1.0-1.0/(r1-l1+1));
			make_mult(1,1,n,l1,r1,1.0-1.0/(r1-l1+1));
//			make_naive_mult(l2,r2,1.0-1.0/(r2-l2+1));
			make_mult(1,1,n,l2,r2,1.0-1.0/(r2-l2+1));
//			make_naive_add(l1,r1,ev2/(r1-l1+1),1.0/(r1-l1+1));
			make_add(1,1,n,l1,r1,ev2/(r1-l1+1),1.0/(r1-l1+1));
//			make_naive_add(l2,r2,ev1/(r2-l2+1),1.0/(r2-l2+1));
			make_add(1,1,n,l2,r2,ev1/(r2-l2+1),1.0/(r2-l2+1));
		}
	}


//	cin.get(); cin.get();
	return 0;
}