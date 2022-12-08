#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int t[212345];
int v[212345];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int MAXN=212345;
	int n,k,q;
	cin>>n>>k>>q;

	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		t[l]++;
		t[r+1]--;
	}

	v[0]=t[0];
	for(int i=1;i<MAXN;i++){
		v[i]=v[i-1]+t[i];
	}
	for(int i=0;i<MAXN;i++){
		if(v[i]>=k){
			v[i]=1;
		}
		else{
			v[i]=0;
		}
	}
	for(int i=1;i<MAXN;i++){
		v[i]=v[i]+v[i-1];
	}
	for(int i=0;i<7;i++){
		//cout<<v[i]<<" ";
	}
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		if(l==0){
			cout<<v[r]<<"\n";
			continue;
		}
		cout<<(v[r]-v[l-1])<<"\n";
	}
	return 0;
}