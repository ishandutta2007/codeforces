/*
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

const int N = 200031;

const int BOUND = 200000;

int pr[N];

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x){
	return pw(x,bs-2);
}

long long inv_value[N];
int ar[N];
int n;
int root[N];
vector<pair<int,int> > entries[N];

int get_degree(int val,int p){
	int ret=0;
	while (val%p==0){
		val/=p;
		ret++;
	}
	return ret;
}

vector<int> get_primes(int val){
	vector<int> ret;
	while (val>1){
		int here=pr[val];
		ret.push_back(here);
		while (val%here==0)
			val/=here;
	}
	return ret;
}

int q;

int gcd(int a,int b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

long long lcm(int a,int b){
	return 1ll*a/gcd(a,b)*b;
}

const int CAN_AFFORD=3.995e8/12;

int t[CAN_AFFORD],left_son[CAN_AFFORD],right_son[CAN_AFFORD];

int query(int v,int tl,int tr,int l,int r){
	//cout<<v<<"@"<<t[v]<<" "<<tl<<" "<<tr<<" "<<l<<" "<<r<<endl;
	if (l>r)
		return 1;
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	long long le=query(left_son[v],tl,tm,l,min(r,tm));
	long long ri=query(right_son[v],tm+1,tr,max(tm+1,l),r);
	//cout<<v<<" "<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<le<<" "<<ri<<endl;
	long long here=1ll*le*ri;
	return here%bs;
}

int C;

int mult(int v,int tl,int tr,int ps,int val){
	//cout<<v<<"@"<<tl<<" "<<tr<<" "<<ps<<"@@@"<<val<<" "<<t[v]<<endl;
	int new_left_son;
	int new_right_son;

	if (tl!=tr)
	{
		int tm=tl+tr;
		tm/=2;
		if (ps<=tm){
			new_left_son=mult(left_son[v],tl,tm,ps,val);
			new_right_son=right_son[v];
		}
		else
		{
			new_left_son=left_son[v];
			new_right_son=mult(right_son[v],tm+1,tr,ps,val);
		}
	}
	++C;
	left_son[C]=new_left_son;
	right_son[C]=new_right_son;
	if (tl!=tr){
		t[C]=1ll*t[left_son[C]]*t[right_son[C]]%bs;
	}
	else
	{
		t[C]=1ll*t[v]*val%bs;
	}
	return C;
}

int build(int tl,int tr){
	++C;
	int v=C;
	t[v]=1;
	if (tl==tr)
		return v;
	int tm=tl+tr;
	tm/=2;
	left_son[v]=build(tl,tm);
	right_son[v]=build(tm+1,tr);
	return v;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    pr[1]=1;
    for (int i=2;i<=BOUND;i++){
    	if (pr[i])
    		continue;
    	for (int j=i;j<=BOUND;j+=i){
    		pr[j]=i;
    	}
    }

    for (int i=2;i<=BOUND;i++){
    	if (pr[i]==i)
    		inv_value[i]=inv(i);
    }

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    build(1,n);

    root[n+1]=1;

//    cout<<"@"<<endl;

    for (int i=n;i>=1;--i){
    	root[i]=root[i+1];
    	vector<int> primes=get_primes(ar[i]);
    	for (int j=0;j<primes.size();j++){
    		int this_prime=primes[j];
    		int deg_here=get_degree(ar[i],this_prime);
    		for (int q=(int)entries[this_prime].size()-1;q>=0;--q){
    			int old_value=entries[this_prime][q].second;
    			int ps=entries[this_prime][q].first;
    			if (q+1<entries[this_prime].size())
    				old_value-=entries[this_prime][q+1].second;
    			// divide by old
    			long long here=pw(inv_value[this_prime],old_value);
    			root[i]=mult(root[i],1,n,ps,here);
    			old_value=entries[this_prime][q].second;
    			if (old_value>deg_here){
    				// need to multiply by diff, and break
    				int new_value=old_value-deg_here;
    				new_value=pw(this_prime,new_value);
    				root[i]=mult(root[i],1,n,ps,new_value);
    				break;
    			}
    		}
    		// clean up trash
    		while (entries[this_prime].size()>0&&entries[this_prime].back().second<=deg_here)
    			entries[this_prime].pop_back();
    		// push back our value
    		entries[this_prime].push_back(make_pair(i,deg_here));
    		int new_value=pw(this_prime,deg_here);
    		root[i]=mult(root[i],1,n,i,new_value);
    	/*	for (int j=i;j<=5;j++){
    			cout<<query(root[i],1,n,i,j)<<endl;
    		}
    		cout<<endl;*/
    	}
    	if (C>=CAN_AFFORD-1000)
    		throw 1;
    }

    cin>>q;
    int last=0;
    for (;q;--q){
    	int l,r;
    	cin>>l>>r;
    	l=(l+last)%n+1;
    	r=(r+last)%n+1;
    	if (l>r)
    		swap(l,r);
    	last=query(root[l],1,n,l,r);
    	cout<<last<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}