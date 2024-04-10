#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
const int N = 2e5 + 10;
vector<int> pos[N];
int A[N], B[N];
vector<int> rempos;
set<int> remnum, remnum2;

int remaining[N];
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(A[i]);
		pos[A[i]].push_back(i);
		B[i] = A[i];
	}
	int q = 0;
	for(int i = 1; i <= n; i++){
		if(pos[i].size() >= 2 || pos[i].empty()){
			for(int j : pos[i]) rempos.push_back(j);
			if(pos[i].empty()){
				q++;
				remnum.insert(i);
			}
			if(pos[i].size() >= 2)
				remnum2.insert(i);
		}
		remaining[i] = pos[i].size();
	}

	sort(rempos.begin(), rempos.end());
	for(int i : rempos){
		int x = A[i];

		if(remaining[x] == 1 && remnum2.count(x)){
			B[i] = x;
			remnum2.erase(x);
		}
		else{
			int y = *remnum.begin();
			if(x < y && remnum2.count(x)){
				B[i] = x;
				remnum2.erase(x);
			}
			else{
				B[i] = y;
				remnum.erase(y);
			}
		}
		remaining[x] --;
	}

	printf("%d\n", q);
	for(int i = 1; i <= n; i++) printf("%d ", B[i]); 
}