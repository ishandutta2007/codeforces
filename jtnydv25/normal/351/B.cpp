#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 3005;
int p[N];
double E[N * N];
int main(){
	int n;
	cin >> n;
	int invc = 0;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		for(int j = 1; j < i; j++) if(p[j] > p[i]) invc++;
	}	
	E[0] = 0;
	E[1] = 1;
	E[2] = 4;
	for(int i = 3; i <= invc; i++){
		E[i] = E[i - 2] + 4;
	}
	printf("%.10lf\n", E[invc]);
}