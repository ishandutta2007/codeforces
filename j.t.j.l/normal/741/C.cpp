#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int nico[MAXN], maki[MAXN];
int Pr[MAXN], QvQ[MAXN];

void solve(int casi){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &nico[i], &maki[i]);
		nico[i]--,maki[i]--;
		Pr[nico[i]] = maki[i];
		Pr[maki[i]] = nico[i];
	}
	for(int i = 0; i < 2 * n; i += 2)
		if (QvQ[i] == 0){
			for(int j = i, fg = 0; !fg || j != i; fg++, j = Pr[j ^ 1]){
				QvQ[j] = 1;
				QvQ[j ^ 1] = 2;
			}
		}
	for(int i = 1; i <= n; i++)
		printf("%d %d\n", QvQ[nico[i]], QvQ[maki[i]]);
}

void printans(){

}


int main(){
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}