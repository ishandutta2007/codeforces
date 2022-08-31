/*
Kneeling before the carnal demon machine
On hands and knees she shallows divinity
Begging for forgiveness, the blessing of a kiss
The essence of denial, the pleasure of her sin

Father please embrace me
My lusts I lay unto thee
Free me from temptation
May you scourge this skin with the seeds of salvation

She's crying beneath an image
An image of a hundred thorns
Rivers that calm, rivers that lie
Thorns like nails driven into her flesh
Ecstacy nailed to the cross

Holy water pouring on my breasts
On hands and knees I shallow divinity
A picture that calms, a picture that lies
I'm drowning in the face of Jesus Christ
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600000;

int n,tests;

long long tw[N*4];
long long twx[N*4];

long long a[N],w[N];

void build(int v,int tl,int tr){
	if (tl==tr){
		tw[v]=w[tl];
		twx[v]=w[tl]*a[tl]%bs;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	tw[v]=tw[v*2]+tw[v*2+1];
	twx[v]=twx[v*2]+twx[v*2+1];
	twx[v]%=bs;
//	cout<<"@"<<v<<" "<<twx[v]<<endl;
}

void update(int v,int tl,int tr,int ps,int val){
	if (tl==tr){
		tw[v]=val;
		twx[v]=1ll*a[ps]*val%bs;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update(v*2,tl,tm,ps,val);
	else
		update(v*2+1,tm+1,tr,ps,val);
	tw[v]=tw[v*2]+tw[v*2+1];
	twx[v]=twx[v*2]+twx[v*2+1];
	twx[v]%=bs;
}

long long getw(int v,int tl,int tr,int l,int r){
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return tw[v];
	int tm=tl+tr;
	tm/=2;
	long long ret=getw(v*2,tl,tm,l,min(r,tm))+getw(v*2+1,tm+1,tr,max(tm+1,l),r);
	return ret;
}

long long getwx(int v,int tl,int tr,int l,int r){
	//cout<<v<<" "<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<twx[v]<<endl;
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return twx[v];
	int tm=tl+tr;
	tm/=2;
	long long ret=getwx(v*2,tl,tm,l,min(r,tm))+getwx(v*2+1,tm+1,tr,max(tm+1,l),r);
	return ret%bs;
}

int get_ps(int v,int tl,int tr,long long val){
	if (tl==tr)
		return tl;
	int tm=tl+tr;
	tm/=2;
	if (tw[v*2]>=val)
		return get_ps(v*2,tl,tm,val);
	val-=tw[v*2];
	return get_ps(v*2+1,tm+1,tr,val);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>tests;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]-=i;
	}
	for (int i=1;i<=n;i++){
		cin>>w[i];
	}

	build(1,1,n);

	for (;tests;--tests){
		int val1,val2;
		cin>>val1>>val2;
		if (val1<0) // first type
		{
			val1*=-1;
			update(1,1,n,val1,val2);
			w[val1]=val2;
		}
		else // second type
		{
			long long pref=getw(1,1,n,1,val1-1);
			long long seg=getw(1,1,n,val1,val2);
			long long need=pref+(seg+1)/2;
			int ps=get_ps(1,1,n,need);
			//cout<<ps<<endl;
			//cout<<pref<<" "<<seg<<" "<<need<<" "<<ps<<" "<<tw[1]<<" "<<tw[2]<<" "<<tw[3]<<endl;
			long long left_side=getwx(1,1,n,val1,ps);
			long long right_side=getwx(1,1,n,ps+1,val2);
			//cout<<left_side<<" "<<right_side<<"@"<<" "<<val1<<" "<<val2<<endl;
			long long ans=(getw(1,1,n,val1,ps)%bs)*1ll*a[ps]-left_side;
			//cout<<"@"<<ans<<endl;
			ans+=right_side-(getw(1,1,n,ps+1,val2)%bs)*1ll*a[ps];
			ans%=bs;
			if (ans<0)
				ans+=bs;
			cout<<ans<<"\n";
		}
	}

//	cin.get(); cin.get();
	return 0;
}