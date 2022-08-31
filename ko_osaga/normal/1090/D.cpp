#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> G[100100];
int N,M,P[100100],C[100100];

int main()
{
	scanf ("%d %d",&N,&M);

	for (int i=0;i<M;i++){
		int x,y; scanf ("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}

	for (int i=1;i<=N;i++) if (G[i].size() < N-1){
		puts("YES");
		P[i] = 1; C[1] = 1;
		for (int s=3,j=0;j<G[i].size();j++){
			P[G[i][j]] = s;
			C[s] = 1;
			s++;
		}
		for (int s=1,j=1;j<=N;j++){
			while (C[s]) s++;
			if (P[j] == 0){
				P[j] = s;
				C[s] = 1;
				s++;
			}
		}

		for (int j=1;j<=N;j++) printf ("%d ",P[j]); puts("");
		P[i]++;
		for (int j=1;j<=N;j++) printf ("%d ",P[j]); puts("");
		return 0;
	}
	puts("NO");

	return 0;
}