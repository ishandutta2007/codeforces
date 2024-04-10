#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
const int N = 30;
int A[30];
int perm[N], B[N];
bool cmp(int i, int j){
	return A[i] < A[j];
}
map<int, int> ind;
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
		perm[i] = i;
		ind[A[i]] = i;
	}
	sort(A + 1, A + n + 1);
	for(int i = 1; i <= n; i++){
		int j = ind[A[i]];
		if(i == n) B[j] = A[1];
		else B[j] = A[i + 1];
	}
	for(int i = 1; i <= n; i++) cout << B[i] << " ";
}