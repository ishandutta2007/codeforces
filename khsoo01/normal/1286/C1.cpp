#include<bits/stdc++.h>
using namespace std;

int n;
char tmp[105];

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
	scanf("%d",&n);
	vector<vector<int> > V1, V2, W;
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
	string ans;
	for(int i=0;i<n;i++) {
		for(int j=0;j<26;j++) {
			if(P[j] < W[i][j]) {
				ans.push_back('a'+j);
				break;
			}
		}
		P = W[i];
	}
	cout << "! " << ans << "\n";
}