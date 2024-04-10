#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))

bool is_rotation(vector<int> &a, vector<int> &b, int shift){
	int n = b.size();
	for(int i = 0; i < n; i++) if(a[i] != b[( i + shift) % n]) return 0;
	return 1;	
}
vector<int> a, b;
int main(){
	int n, x;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(x); if(x)a.push_back(x);
	}
	for(int j = 1; j <= n; j++){
		sd(x); if(x) b.push_back(x);
	}
	for(int shift = 0; shift < n; shift ++) if(is_rotation(a, b, shift)){ printf("YES"); return 0;}
	printf("NO");	
}