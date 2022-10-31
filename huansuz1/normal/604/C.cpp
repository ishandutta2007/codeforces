#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 
#define mp make_pair 
#define ll long long

using namespace std;


int n,d[333333];
char s[333333];


int main(){
	

	scanf("%d\n%s",&n,s + 1);
	int mn = n + 1,mx = 0;
	for(int i = 2;i <= n;++i) {
		if(s[i] == s[i - 1]) {
			if(mx < i) mx = i;
			if(mn > i - 1) mn = i - 1;
		}
	}
	if(mx == 0) {
		cout<<n;
		return 0;
	}


	if(s[mx] == '1') s[mx - 1] = '0';
	else s[mx - 1] = '1';
	for(int i = mx - 2;i > 0;--i) {
		if(s[i] != s[i + 1]) break;
		if(s[i] == '1') s[i] = '0';
		else s[i] = '1';
	}
	/*
	for(int i = 1;i <= 8;++i)
		cout<<s[i];
	cout<<endl;
	*/
	int Max = 1;
	d[1] = 1;
	for(int i = 2;i <= n;++i) {
		if(s[i] == s[i - 1]) d[i] = d[i - 1];
		else d[i] = d[i - 1] + 1;
		if(Max < d[i]) Max = d[i];
	//	cout<<i<<' '<<d[i]<<endl;
	}
	cout<<Max;

	return 0;
}