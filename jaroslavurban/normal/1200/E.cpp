#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// I want to know where to fall back when I miss
// => for each position, I need to know
//    the longest prefix that is also the suffix 
//    (of the string that ends there)
//    so I can point on the index after that prefix when I fail

// this is called the prefix function
// returns preprocessed vector where
// v[i] = length of the longest prefix that is also a suffix
//        of the string v[0:i] // inclusive
vector<int>pre(string &p){
	int m=p.size();
	vector<int>pr(m);
	int i=0,j=1;
	while(j<m){
		// let's roll
		if(p[i]==p[j]){
			pr[j]=i+1;
			++j;++i;
		// go to the end of prefix of the current prefix
		}else if(i)i=pr[i-1];
		// 0
		else ++j;
	}
	return pr;
}

// index where the pattern starts or -1
int kmp(string &t,string &p,vector<int>&pr){
	int n=t.size(),m=p.size();
	int i=max(0,n-m+1),j=0;
	while(i<n){
		if(t[i]==p[j]){++i;++j;}
		else if(j)j=pr[j-1];
		else ++i;
	}
	return j;
}

const int N=100100;
string p[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>p[i];
	string res=p[0];
	for(int i=1;i<n;++i){
		int m=p[i].size();
		p[i]+="$";auto pr=pre(p[i]);
		int st=kmp(res,p[i],pr);
		res+=p[i].substr(st,m-st);
	}
	cout<<res<<endl;
}