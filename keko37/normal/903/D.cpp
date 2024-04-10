#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

typedef long double llint;

const int MAXN = 200005;

llint n, sum, sol;
llint l[MAXN];
map <llint, llint> m;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		scanf("%d", &x);
		l[i]=x;
	}
	for (int i=0; i<n; i++) {
		llint val=sum-m[l[i]-1]*(l[i]-1)-m[l[i]]*l[i]-m[l[i]+1]*(l[i]+1);
		llint br=i-m[l[i]-1]-m[l[i]]-m[l[i]+1];
		sol+=br*l[i]-val;
		m[l[i]]++;
		sum+=l[i];
	}
	if (sol<0) {
		cout << "-";
		sol=-sol;
	}
	if (sol<MAXN) {
		cout << sol;
	} else {
		long long k=sol/1000;
		cout << k;
		printf("%.3d", ((int) (sol-((llint) k)*1000))%1000);
	}
	return 0;
}