#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t;
string s0="XWhat are you doing at the end of the world? Are you busy? Will you save us?";
string s1="XWhat are you doing while sending \"";
string s2="X\"? Are you busy? Will you send \"";
string s3="X\"?";
ll k,len[100500];

char work(ll x,ll y){
	if(!x)return s0[y];
	if(y<=34){
		return s1[y];
	}
	y-=34;
	if(y<=len[x-1]){
		return work(x-1,y);
	}
	y-=len[x-1];
	if(y<=32){
		return s2[y];
	}
	y-=32;
	if(y<=len[x-1]){
		return work(x-1,y);
	}
	y-=len[x-1];
	return s3[y];
}

int main() {
	len[0]=75;
	for(i=1;i<=100000;i++){
		len[i]=34+len[i-1]+32+len[i-1]+2;
		len[i]=min(len[i],(ll)(1e18+5));
	}
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>j>>k;
		if(k>len[j]){
			cout<<'.';
		}
		else{
			cout<<work(j,k);
		}
	}
}