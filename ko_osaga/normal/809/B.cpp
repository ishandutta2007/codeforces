#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int mod = 1e9 + 7;

bool solve(int x, int y){
	printf("1 %d %d\n", x, y);
	fflush(stdout);
	char s[6];
	scanf("%s", s);
	return *s == 'T'; // x   
}

int dnc(int s, int e){
	if(s == e) return s;
	int m = (s+e)/2;
	bool x = solve(m, m+1);
	if(x) return dnc(s, m);
	else return dnc(m+1, e);
}

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	int p1 = dnc(1, n);
	if(p1 > 1){
	    int p2 = dnc(1, p1 - 1);
	    if(solve(p2, p1) == 1){
	        printf("2 %d %d\n", p1, p2);
	        fflush(stdout);
	        return 0;
	    }
	}
	printf("2 %d %d\n", p1, dnc(p1 + 1, n));
	fflush(stdout);
}