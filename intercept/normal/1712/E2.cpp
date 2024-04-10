#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int N=2e5;
const int M=2e5+9;
int q;
ll ans[M];
vector<pii>g[M];
int d[M];
vector<int>v[M];
ll bit[M];
void add(int x,ll v){
	for(;x<=N;x+=x&-x)bit[x]+=v;
}
ll ask(int x,ll rex=0){
	for(;x;x-=x&-x)rex+=bit[x];
	return rex;
}
int main(){
	cin>>q;
	for(int i=1;i<=q;++i){
		int l,r;
		cin>>l>>r;
		g[l].eb(r,i);
	}
	for(int i=N;i>=1;--i){
		if(i%2==0){
			for(int k=i/2*3;k<=N;k+=i/2){
				if(k%i){
					for(auto j:v[k]){
						if(i+j>k){
							add(k,1);
						}
					}
					v[k].eb(i);
				}
			}
		}
		for(int k=i+i;k<=N;k+=i){
			add(k,d[k]);
			for(auto j:v[k]){
				if(k%j){
					if(i+j>k){
						add(k,1);
					}
				}
			}
			v[k].eb(i);
			d[k]++;
		}
		for(auto o:g[i]){
			ll t=o.fi-i+1;
			ans[o.se]=t*(t-1)*(t-2)/6-ask(o.fi);
		}
	}
	for(int i=1;i<=q;++i){
		cout<<ans[i]<<"\n";
	}
	return 0;
}