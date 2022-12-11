#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int n;
char buf[110];
string a[110], b[110];

int To(int i, int j) {
	string s1 = a[i], s2 = b[j];
	int cnt = 0;
	for(int i=0; i<s1.size(); i++)
		cnt += (s1[i] != s2[i]);
	return cnt;
}

int main() {
	map<string, int> M;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%s", buf);
		a[i] = buf;
	}
	for(int i=1; i<=n; i++) {
		scanf("%s", buf);
		b[i] = buf;
		M[b[i]] ++;
	}
	static bool used[110];
	for(int i=1; i<=n; i++) {
		if(M[a[i]]) {
			M[a[i]] --;
			for(int j=1; j<=n; j++)
				if(!used[j] && b[j] == a[i]) {
					used[j] = true;
					break;
				}
			a[i] = "#";
		}
	}
	int cost = 0;
	for(int i=1; i<=n; i++) {
		if(a[i] == "#") continue;
		int min = -1, minc = 2e9;
		for(int j=1; j<=n; j++) {
			if(!used[j] && a[i].size() == b[j].size()) {
				int nowc = To(i, j);
				if(minc > nowc) {
					minc = nowc;
					min = j;
				}
			}
		}
		cost += minc;
		used[min] = true;
	}
	printf("%d\n", cost);
	return 0;
}