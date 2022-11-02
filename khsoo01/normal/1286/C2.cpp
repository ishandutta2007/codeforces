#include<bits/stdc++.h>
using namespace std;

int n, m, z[105][26];
char tmp[105], ans[105];

multiset<vector<int> > s;

vector<vector<int> > getquery (int X) {
	vector<vector<int> > R;
	while(X--){
		vector<int> C;
		for(int i=0;i<26;i++) {
			C.push_back(0);
		}
		scanf("%s",tmp);
		int L = strlen(tmp);
		for(int i=0;i<L;i++) {
			C[tmp[i]-'a']++;
		}
		R.push_back(C);
	}
	return R;
}

int main()
{
	scanf("%d",&m);
	n = (m+1)/2;
	vector<vector<int> > V1, V2, V3, W;
	if(n == 1) {
		puts("? 1 1");
		fflush(stdout);
		V1 = getquery(1);
	}
	else {
		printf("? 1 %d\n", n);
		fflush(stdout);
		V1 = getquery(n*(n+1)/2);
		printf("? 2 %d\n", n);
		fflush(stdout);
		V2 = getquery(n*(n-1)/2);
	}
	for(auto &T : V1) {
		s.insert(T);
	}
	for(auto &T : V2) {
		s.erase(s.find(T));
	}
	for(auto &T : s) {
		W.push_back(T);
	}
	sort(W.begin(), W.end(), [&] (vector<int> &A, vector<int> &B) {
		int C = 0;
		for(auto &T : A) {
			C += T;
		}
		for(auto &T : B) {
			C -= T;
		}
		return C < 0;
	});
	vector<int> P;
	for(int i=0;i<26;i++) {
		P.push_back(0);
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<26;j++) {
			if(P[j] < W[i][j]) {
				ans[i] = 'a'+j;
				break;
			}
		}
		P = W[i];
	}
	printf("? 1 %d\n", m);
	fflush(stdout);
	V3 = getquery(m*(m+1)/2);
	for(auto &T : V1) {
		int C = 0;
		for(int i=0;i<26;i++) {
			C += T[i];
		}
		for(int i=0;i<26;i++) {
			z[C][i] -= T[i];
		}
	}
	for(auto &T : V3) {
		int C = 0;
		for(int i=0;i<26;i++) {
			C += T[i];
		}
		for(int i=0;i<26;i++) {
			z[C][i] += T[i];
		}
	}
	for(int i=1;m-i>=n;i++) {
		for(int j=1;j<=i;j++) {
			z[i+1][ans[n-j]-'a'] -= i+1-j;
		}
		for(int j=1;j<i;j++) {
			z[i+1][ans[m-j]-'a'] -= j;
		}
		for(int j=0;j<26;j++) {
			if(z[i+1][j] % (i+1) != 0) {
				ans[m-i] = j + 'a';
				break;
			}
		}
	}
	ans[m] = 0;
	printf("! %s\n", ans);
}