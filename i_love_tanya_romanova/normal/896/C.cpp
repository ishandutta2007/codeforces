/*
There was a time, looking through myself
Wanting to pretend
If I escaped, I could fill myself
I don't think you can
Been far and wide
But that hole inside
Never really leaves
When I went away, what I really left
Left behind was me

It's telling me
To be on my way home
Million miles away
I can't stay

Each passing day, every passing face
Seems like such a blur
I long to be
Home, silently
Lying next to her
Just to get back, by her side is all
All I need to be
Cause I went away
But what I really left
Left behind was me

I need to be
Getting on my way home
A million miles away
Million miles away
I can't take
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

long long seed;

int n,m,vmax;
int ar[N];

int RND(){
	int ret = seed;
    seed = (seed * 7 + 13)%1000000007;
    return ret;
}

int T(){
	int res=0;
	for (int i=1;i<=n;i++)
	{
		if (i==1||ar[i]!=ar[i-1])
			++res;
	}
	return res;
}

vector<pair<long long, int> > order;

vector<pair<pair<int,int>,long long> > S;
//set<pair<pair<int,int>,long long> >::iterator it;

int get_inter(int l1,int r1,int l2,int r2){
	l1=max(l1,l2);
	r1=min(r1,r2);
	if (l1>r1)
		return 0;
	return r1-l1+1;
}

long long pw(long long a,long long b,long long mod){
	a%=mod;
	if (b==0)
		return 1%mod;
	if (b%2)
		return a*pw(a,b-1,mod)%mod;
	return pw(a*a%mod,b/2,mod);
}

vector<pair<pair<int,int>,long long> >V;

void prepare_segments(){
	sort(V.begin(),V.end());
	S.clear();
	int ql=V[0].first.first;
	int qr=V[0].first.second;
	long long qval=V[0].second;
	for (int i=1;i<V.size();i++){
		if (V[i].second!=qval)
		{
			S.push_back(make_pair(make_pair(ql,qr),qval));
			ql=V[i].first.first;
			qval=V[i].second;
		}
		qr=V[i].first.second;
	}
	S.push_back(make_pair(make_pair(ql,qr),qval));

	//debug
	/*for (it=S.begin();it!=S.end();it++){
		pair<pair<int,int>,long long> P=(*it);
		for(int j=P.first.first;j<=P.first.second;j++){
			cout<<P.second<<" ";
		}
	}
	cout<<endl;
*/
}

void run_update(pair<int,int> p,int l,int r,long long old_val, long long new_val){
	//cout<<p.first<<"@"<<p.second<<" "<<l<<" "<<r<<" "<<old_val<<" "<<new_val<<endl;
	if (get_inter(p.first,p.second,l,r)==0){
		V.push_back(make_pair(make_pair(p.first,p.second),old_val));
		return;
	}
	if (p.first<l){ // stays old
		V.push_back(make_pair(make_pair(p.first,l-1),old_val));
	}
	if (p.second>r){ // stays old
		V.push_back(make_pair(make_pair(r+1,p.second),old_val));
	}
	l=max(l,p.first);
	r=min(r,p.second);
	V.push_back(make_pair(make_pair(l,r),new_val));
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m>>seed>>vmax;

	for (int i=1;i<=n;i++){
		ar[i]=RND()%vmax+1;
		//cout<<ar[i]<<"$";
		V.push_back(make_pair(make_pair(i,i),ar[i]));
	}

	prepare_segments();

	for (int i=1;i<=m;i++){
		 int op = (RND()%4) + 1;
		 int l=RND()%n+1;
		 int r=RND()%n+1;
		 int x,y;

		 if (l>r)
			 swap(l,r);
		 if (op==3)
			 x=(RND()%(r-l+1))+1;
		 else
			 x=(RND()%vmax)+1;
		 if (op==4)
			 y=(RND()%vmax)+1;

		// cout<<op<<"%"<<l<<" "<<r<<" "<<x<<" "<<y<<endl;

		 if (op==2)// assign
		 {
			 V.clear();
			 for (int j=0;j<S.size();j++){
				 pair<pair<int,int>,long long> P=S[j];
				 long long new_val=x;
				 run_update(P.first,l,r,P.second,new_val);
			 }
			prepare_segments();
		 }

		 if (op==1){ // add
			 V.clear();
			 for (int j=0;j<S.size();j++){
				 pair<pair<int,int>,long long> P=S[j];
				 long long new_val=x+P.second;
				 run_update(P.first,l,r,P.second,new_val);
			 }
			 prepare_segments();
		 }

		 if (op==3){ // kth stat
			 order.clear();
			 for (int j=0;j<S.size();j++){
				 pair<pair<int,int>,long long> P=S[j];
				 int L=get_inter(P.first.first,P.first.second,l,r);
				 order.push_back(make_pair(P.second,L));
			 }
			 sort(order.begin(),order.end());
			 for (int j=0;j<order.size();j++){
//				 cout<<order[j].first<<"%%%"<<order[j].second<<endl;
				 if (order[j].second>=x){
					 printf("%lld\n",order[j].first);
					 break;
				 }
				 x-=order[j].second;
			 }
		 }
		 if (op==4){ // some random bullshit
			 int res=0;
			 for (int j=0;j<S.size();j++){
//			 for (it=S.begin();it!=S.end();it++){
				 pair<pair<int,int>,long long> P=S[j];
				 int L=get_inter(P.first.first,P.first.second,l,r);
				 if (L==0)
					 continue;
			//	 cout<<P.second<<"%%%"<<L<<" "<<x<<" "<<y<<endl;
				 res+=(pw(P.second,x,y)*L)%y;
				 res%=y;
			 }
			 printf("%d\n",res);
		 }

/*		 if (op==1){
			 for (int j=l;j<=r;j++)
				 ar[j]=x;
		 }
		 if (op==2){
			 for (int j=l;j<=r;j++){
				 ar[j]=ar[j]+x;
			 }
		 }
		 cout<<T()<<endl;*/
	}


//	cin.get(); cin.get();
	return 0;
}