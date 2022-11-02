#include<bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, a[N], b[N];

vector<int> v1, v2;

bool cmp (int A, int B) {
	return a[A] > a[B];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		if(a[i] == b[i]) continue;
		else if(a[i] > b[i]) {
			swap(a[i], b[i]);
			v1.push_back(i);
		}
		else v2.push_back(i);
	}
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	if(v1.size() > v2.size()) {
		printf("%d\n", v1.size());
		for(int i=v1.size();i--;) {
			printf("%d ", v1[i]);
		}
		puts("");
	}
	else {
		printf("%d\n", v2.size());
		for(int i=0;i<v2.size();i++) {
			printf("%d ", v2[i]);
		}
		puts("");
	}
}