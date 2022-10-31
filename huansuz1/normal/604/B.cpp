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


int n,k,a[333333];


bool good(int s) {
	int l = 1,r = n,cnt = 0;
	while(l <= r) {
		cnt++;
		int t = s - a[r--];
		if(l > r) break;
		if(t >= a[l]) t -= a[l++];
	}
	if(cnt <= k) return 1;
	else return 0;
}


int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;++i)
		scanf("%d",&a[i]);
	int l = a[n] - 1,r = 2*a[n];
	while(r > l + 1) {
		int m = (r + l)/2;
		if(good(m)) r = m;
		else l = m;	
	}
	cout<<r;
	return 0;
}