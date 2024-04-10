#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vi cnt(26+26+10);
	for(auto i:s){
		if(islower(i))cnt[i-'a']++;
		if(isupper(i))cnt[i-'A'+26]++;
		if(isdigit(i))cnt[i-'0'+26+26]++;
	}
	int pairs=0;
	int singles=0;
	for(auto i:cnt){
		if(i%2)singles++;
		pairs+=i/2;
	}
	vi anss;
	for(int i=1;i*i<=n;i++){
		if(n%i)continue;
		{
			int len=i;
			int reqdpairs=(n/len)*(len/2);
			int reqdsingles=n-reqdpairs*2;
			bool good=1;
			if(pairs<reqdpairs){
				good=0;
			}
			if(reqdsingles<(pairs-reqdpairs)*2+singles){
				good=0;
			}
			if(good){
				anss.pb(len);
			}
		}
		{
			int len=n/i;
			int reqdpairs=(n/len)*(len/2);
			int reqdsingles=n-reqdpairs*2;
			bool good=1;
			if(pairs<reqdpairs){
				good=0;
			}
			if(reqdsingles<(pairs-reqdpairs)*2+singles){
				good=0;
			}
			if(good){
				anss.pb(len);
			}
		}
	}
	int length=*max_element(all(anss));
	int cntr=n/length;
	cout<<cntr<<endl;
	vector<string>v(cntr);
	int idx=0;
	rep(i,0,cntr){
		rep(j,0,length/2){
			while(cnt[idx]<=1)idx++;
			if(idx<26)v[i].pb('a'+idx),v[i].pb('a'+idx);
			else if(idx<52)v[i].pb('A'+idx-26),v[i].pb('A'+idx-26);
			else v[i].pb('0'+idx-52),v[i].pb('0'+idx-52);
			cnt[idx]-=2;
		}
	}
	idx=0;
	rep(i,0,cntr){
		rep(j,0,length%2){
			while(cnt[idx]==0)idx++;
			if(idx<26)v[i].pb('a'+idx);
			else if(idx<52)v[i].pb('A'+idx-26);
			else v[i].pb('0'+idx-52);
			cnt[idx]--;
		}
	}
	rep(i,0,cntr){
		for(int j=0;j<length;j+=2)cout<<v[i][j];
		int start=length-1;
		if(start%2==0)start--;
		for(int j=start;j>=0;j-=2)cout<<v[i][j];
		cout<<" ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}