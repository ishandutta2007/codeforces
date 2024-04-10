#include <bits/stdc++.h>

using namespace std;

char color[1001][1001];
int num[1001][1001];
int ans[1001][1001][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int anser=0;
	int r, c;
	cin >> r >> c;
	for(int a=0; a<r; a++) {
		string s;
		cin >> s;
		for(int b=0; b<c; b++) {
			color[a][b]=s.at(b);
		}
	}
	for(int b=0; b<c; b++) {
		int last=0;
		char lastone='8';
		for(int a=r-1; a>=0; a--) {
			if(color[a][b]!=lastone) last=0;
			last++;
			num[a][b]=last;
			if(a+2*last<r) {
				if((last==num[a+last][b] && last<=num[a+last+last][b]) && (color[a][b]!=color[a+last][b] && color[a+last][b]!=color[a+last+last][b])) {
					ans[a][b][1]=last;
					if(b==0) {
						ans[a][b][0]=1;
						anser++;
					}
					else {
						if(ans[a][b][1]==ans[a][b-1][1] && color[a][b]==color[a][b-1] && color[a+last][b]==color[a+last][b-1] && color[a+last+last][b]==color[a+last+last][b-1]) ans[a][b][0]=ans[a][b-1][0]+1;
						else ans[a][b][0]=1;
						anser+=(long long int)(ans[a][b][0]);
					}
				}
			}
			lastone=color[a][b];
		}
	}
	cout << anser << '\n';
}