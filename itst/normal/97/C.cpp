#include<bits/stdc++.h>
#define R register
#define MAXN 100010
#define eps 1e-9
using namespace std;

double p[111] , dis[210];
short N , K;
queue < int > q;
struct Edge{
	int end , upEd;
	double w;
}Ed[MAXN];
int head[210] , flo[210] , cntEd;
bool inq[210];

inline void addEd(int a , int b , double c){
	Ed[++cntEd].end = b;
	Ed[cntEd].w = c;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

inline bool check(double mid){
	while(!q.empty())
		q.pop();
	memset(dis , 0xdd , sizeof(dis));
	memset(inq , 0 , sizeof(inq));
	memset(flo , 0 , sizeof(flo));
	dis[flo[1] = 1] = 0;
	q.push(1);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		inq[t] = 0;
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(dis[Ed[i].end] < dis[t] + Ed[i].w - mid){
				dis[Ed[i].end] = dis[t] + Ed[i].w - mid;
				flo[Ed[i].end] = flo[t] + 1;
				if(flo[Ed[i].end] > K)
					return 1;
				if(!inq[Ed[i].end]){
					inq[Ed[i].end] = 1;
					q.push(Ed[i].end);
				}
			}
	}
	return 0;
}

inline void solve(){
	for(int i = 0 ; i <= K ; i++)
		for(int j = 0 ; j <= K ; j++){
			int k = i - j;
				if(k <= N && k >= -N && (k & 1) == (N & 1))
					addEd(i , j , p[N + i - j >> 1]);
		}
	double l = 0 , r = 1;
	while(r - l > eps){
		double mid = (l + r) / 2;
		check(mid) ? l = mid : r = mid;
	}
	printf("%.8lf" , l);
}

int main(){
	scanf("%d" , &N);
	K = N << 1;
	for(R short i = 0 ; i <= N ; ++i)
		scanf("%lf" , &p[i]);
	solve();
	return 0;
}