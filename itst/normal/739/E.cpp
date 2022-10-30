#include<bits/stdc++.h>
#define int long long
#define ld long double
#define eps 1e-10
#define MAXN 2010
using namespace std;

struct Edge{
	int end , upEd , flow;
	ld w;
}Ed[MAXN << 3];
int head[MAXN] , pre[MAXN] , N , cntEd = 1;
ld p1[MAXN] , p2[MAXN] , maxDis[MAXN] , ans;
bool inq[MAXN];
queue < int > q;

inline void addEd(int a , int b , int c , ld d){
	Ed[++cntEd].end = b;
	Ed[cntEd].flow = c;
	Ed[cntEd].w = d;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

bool SPFA(){
	fill(maxDis , maxDis + N + 4 , -0x7fffffff);
	while(!q.empty()){
		inq[q.front()] = 0;
		q.pop();
	}
	maxDis[0] = 0;
	q.push(0);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		inq[t] = 0;
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(maxDis[Ed[i].end] + eps < maxDis[t] + Ed[i].w && Ed[i].flow){
				pre[Ed[i].end] = i;
				maxDis[Ed[i].end] = maxDis[t] + Ed[i].w;
				if(!inq[Ed[i].end]){
					inq[Ed[i].end] = 1;
					q.push(Ed[i].end);
				}
			}
	}
	return maxDis[N + 3] - eps > -0x7fffffff;
}

void EKKKK(){
	ans += maxDis[N + 3];
	int t = N + 3;
	while(t){
		Ed[pre[t]].flow--;
		Ed[pre[t] ^ 1].flow++;
		t = Ed[pre[t] ^ 1].end;
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int P , Q;
	cin >> N >> P >> Q;
	addEd(0 , N + 1 , P , 0);
	addEd(N + 1 , 0 , 0 , 0);
	addEd(0 , N + 2 , Q , 0);
	addEd(N + 2 , 0 , 0 , 0);
	for(int i = 1 ; i <= N ; i++){
		cin >> p1[i];
		addEd(N + 1 , i , 1 , p1[i]);
		addEd(i , N + 1 , 0 , -p1[i]);
	}
	for(int i = 1 ; i <= N ; i++){
		cin >> p2[i];
		addEd(N + 2 , i , 1 , p2[i]);
		addEd(i , N + 2 , 0 , -p2[i]);
		addEd(i , N + 3 , 1 , 0);
		addEd(N + 3 , i , 0 , 0);
		addEd(i , N + 3 , 1 , -p1[i] * p2[i]);
		addEd(N + 3 , i , 0 , p1[i] * p2[i]);	
	}
	while(SPFA())
	
	EKKKK();
	cout << fixed << setprecision(5) << ans;
	return 0;
}