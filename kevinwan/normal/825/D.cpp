#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=998244353;
const int mn=1e3+10;
int nt[26],ns[26];
int ad[26];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    string s,t;
    cin>>s>>t;
    int nq=0;
    for(char c:t)nt[c-'a']++;
    for(char c:s){
    	if(c=='?')nq++;
    	else ns[c-'a']++;
    }
    bool gud=1;
    while(gud){
    	for(int i=0;i<26;i++){
    		if(ns[i]<nt[i]){
    			if(nq>=nt[i]-ns[i])nq-=nt[i]-ns[i],ad[i]+=nt[i]-ns[i],ns[i]=nt[i];
    			else {gud=0;break;}
    		}
    	}
    	for(int i=0;i<26;i++)ns[i]-=nt[i];
    }
	ad[0]+=nq;
	int cur=0;
	for(char&c:s){
		if(c=='?'){
			while(cur<26&&!ad[cur])cur++;
			ad[cur]--;
			c=cur+'a';
		}
	}
	printf("%s",s.c_str());
}