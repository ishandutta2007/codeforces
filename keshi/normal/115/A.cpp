#include <bits/stdc++.h>
using namespace std;
int n,a,m=0;
vector <int> s[100010];
vector <int> see;
void solve(int v, int d){
	for (int i=0; i<s[v].size(); i++){
		solve(s[v][i],d+1);
	}
	if (s[v].size()==0){
		m=max(m,d);
	}
}
int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a;
		a--;
		if (a!=-2){
			s[a].push_back(i);
		}
		else{
			see.push_back(i);
		}
	}
	for (int i=0; i<see.size(); i++){
		solve(see[i],1);
	}
	cout << m;
	return 0;
}