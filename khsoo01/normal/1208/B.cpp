#include<bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, a[N], cnt[N], x;

map<int,int> mp;

void upd (int I, int C) {
	if(mp[I] == 1) x--;
	mp[I] += C;
	if(mp[I] == 1) x++;
}

bool can (int I) {
	mp.clear();
	x = 0;
	int L = n - I;
	for(int i=I+1;i<=n;i++) {
		upd(a[i], 1);
	}
	if(x == L) return true;
	for(int i=I+1;i<=n;i++) {
		upd(a[i], -1);
		upd(a[i-I], 1);
		if(x == L) return true;
	}
	return false;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	int S = 0, E = n;
	while(S<E) {
		int M = (S+E)/2;
		can(M) ? E = M : S = M+1;
	}
	printf("%d\n",S);
}