#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int _ = 2003 , __ = 1e5 + 7; int dst[2][_] , N , M , P , Q , V[_]; ll f[_] , mxg[_] , g[_] , nodel[_];
struct Edge{int end , upEd , w;}Ed[__ << 1]; int head[_] , cntEd;
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}

void dijk(int x , int pt){
	static ll dist[_]; static bool vis[_]; memset(vis , 0 , sizeof(vis));
	memset(dist , 0x3f , sizeof(dist)); dist[x] = 0; int id = 0; ll pre = -1;
	for(int i = 1 ; i <= N ; ++i){
		int mn = 0; for(int j = 1 ; j <= N ; ++j) if(!vis[j] && dist[mn] > dist[j]) mn = j;
		vis[mn] = 1; for(int i = head[mn] ; i ; i = Ed[i].upEd) dist[Ed[i].end] = min(dist[Ed[i].end] , dist[mn] + Ed[i].w);
		if(dist[mn] != pre){pre = dist[mn]; ++id;} dst[pt][mn] = id;
	}
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M >> P >> Q; for(int i = 1 ; i <= N ; ++i) cin >> V[i];
	for(int i = 1 ; i <= M ; ++i){int u , v , w; cin >> u >> v >> w; addEd(u , v , w); addEd(v , u , w);}
	dijk(P , 0); dijk(Q , 1); memset(mxg , -0x3f , sizeof(mxg));
	
	for(int i = N - 1 ; ~i ; --i){
		static ll dlt[_]; memset(dlt , 0 , sizeof(dlt)); int mx = -1;
		for(int j = 1 ; j <= N ; ++j) if(dst[0][j] == i + 1 && V[j]){mx = max(mx , dst[1][j] - 1); dlt[dst[1][j] - 1] += V[j];}
		for(int j = N ; ~j ; --j){dlt[j] += dlt[j + 1]; mxg[j] = max(mxg[j] , g[j]); if(j <= mx){f[j] = max(f[j] , mxg[j]) + dlt[j]; mxg[j] = mxg[N + 1];}}
		ll mxf = -mxg[N + 1]; memset(dlt , 0 , sizeof(dlt)); static bool vis[_]; memset(vis , 0 , sizeof(vis));
		for(int j = 1 ; j <= N ; ++j) if(dst[0][j] > i && V[j]){vis[dst[1][j] - 1] = 1; dlt[dst[1][j] - 1] -= V[j];}
		for(int j = N ; ~j ; --j){if(vis[j]){g[j] = min(mxf , g[j + 1]) + dlt[j]; mxf = -mxg[N + 1];}else g[j] = g[j + 1]; mxf = min(mxf , f[j]);}
	}
	cout << (f[0] > 0 ? "Break a heart" : (f[0] ? "Cry" : "Flowers"));
	return 0;
}