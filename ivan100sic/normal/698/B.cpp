#include "bits/stdc++.h"
using namespace std;

int P[200005], N;
vector<int> E[200005];

int Color[200005];
int BRKA, Root[200005], Size[200005], Sink[200005];

void dfs(int x){
	if (Color[x]) return;
	Color[x] = BRKA;
	Size[BRKA]++;
	for (int y : E[x]) dfs(y);
}

int nadji(int x, int step){
	while (step--){
		x = P[x];
	}
	return x;
}		

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		scanf("%d", P+i);
		E[i].push_back(P[i]);
		E[P[i]].push_back(i);
	}
	for (int i=1; i<=N; i++){
		if (!Color[i]){
			BRKA++;
			Root[BRKA] = i;
			dfs(i);
		}
	}
	for (int i=1; i<=BRKA; i++){
		Sink[i] = nadji(Root[i], Size[i]);
	}
	int ima = -1;
	for (int i=1; i<=BRKA; i++){
		if (Sink[i] == P[Sink[i]]) ima = i;
	}
	if (ima != -1){
		swap(Root[ima], Root[1]);
		swap(Size[ima], Size[1]);
		swap(Sink[ima], Sink[1]);
	}
	int chg = 0;
	for (int i=BRKA; i>1; i--){
		P[Sink[i]] = Root[i-1];
		chg++;
	}
	if (ima == -1){
		P[Sink[1]] = Sink[1];
		chg++;
	}
	printf("%d\n", chg);
	for (int i=1; i<=N; i++) printf("%d%c", P[i], i==N?'\n':' ');
	scanf("%d", &N);
	return 0;	
}