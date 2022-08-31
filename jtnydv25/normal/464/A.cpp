#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int A[N];

int n, p;
set<int> st;
int getNext(int x){
	for(int i = 0; i < p; i++) st.insert(i);
	st.erase(x);
	if(!st.empty()) return *st.begin();
	return -1;
}

int getNext(int x, int y){
	for(int i = 0; i < p; i++) st.insert(i);
	st.erase(x); st.erase(y);
	if(!st.empty()) return *st.begin();
	return -1;
}
int B[N], C[N];
int get(int i){
	if(i == 2) return getNext(B[i - 1]);
	return getNext(B[i - 1], B[i - 2]);
}

int main(){
	cin >> n >> p;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++) A[i] = s[i - 1] - 'a';
	for(int i = n; i >= 1; i--){
		memcpy(B, A, sizeof B);
		int x = A[i];
		x++;
		while(x < p){
			if((i == 1) || (i == 2 && x != A[i - 1]) || (i > 2 && x != A[i - 1] && x != A[i - 2])){
				B[i] = x;
				bool done = 1;
				for(int j = i + 1; j <= n; j++){
					B[j] = get(j);
					if(B[j] == -1){
						done = 0;
						for(int k = j; k >= i; k--)
							B[k] = A[k];
					}
				}
				if(done){
					for(int j = 1; j <= n; j++)
						cout << (char)(B[j] + 'a');
					return 0;
				}
			}
			x++;
		}
	}
	cout << "NO\n";
}