#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[80],b[80];

template <typename T>
struct hung {  // km
  int n;
  vector<int> matchx;  // 
  vector<int> matchy;  // 
  vector<int> pre;     // 
  vector<bool> visx;   //  
  vector<bool> visy;   //  
  vector<T> lx;
  vector<T> ly;
  vector<vector<T> > g;
  vector<T> slack;
  T inf;
  T res;
  queue<int> q;
  int org_n;
  int org_m;

  hung(int _n, int _m) {
    org_n = _n;
    org_m = _m;
    n = max(_n, _m);
    inf = numeric_limits<T>::max();
    res = 0;
    g = vector<vector<T> >(n, vector<T>(n));
    matchx = vector<int>(n, -1);
    matchy = vector<int>(n, -1);
    pre = vector<int>(n);
    visx = vector<bool>(n);
    visy = vector<bool>(n);
    lx = vector<T>(n, -inf);
    ly = vector<T>(n);
    slack = vector<T>(n);
  }

  void addEdge(int u, int v, int w) {
    g[u][v] = max(w, 0);  //  0
  }

  bool check(int v) {
    visy[v] = true;
    if (matchy[v] != -1) {
      q.push(matchy[v]);
      visx[matchy[v]] = true;  // in S
      return false;
    }
    //   pre ""
    while (v != -1) {
      matchy[v] = pre[v];
      swap(v, matchx[pre[v]]);
    }
    return true;
  }

  void bfs(int i) {
    while (!q.empty()) {
      q.pop();
    }
    q.push(i);
    visx[i] = true;
    while (true) {
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
          if (!visy[v]) {
            T delta = lx[u] + ly[v] - g[u][v];
            if (slack[v] >= delta) {
              pre[v] = u;
              if (delta) {
                slack[v] = delta;
              } else if (check(v)) {  // delta=0  
                                      // return 
                return;
              }
            }
          }
        }
      }
      //  
      T a = inf;
      for (int j = 0; j < n; j++) {
        if (!visy[j]) {
          a = min(a, slack[j]);
        }
      }
      for (int j = 0; j < n; j++) {
        if (visx[j]) {  // S
          lx[j] -= a;
        }
        if (visy[j]) {  // T
          ly[j] += a;
        } else {  // T'
          slack[j] -= a;
        }
      }
      for (int j = 0; j < n; j++) {
        if (!visy[j] && slack[j] == 0 && check(j)) {
          return;
        }
      }
    }
  }

  void solve() {
    // 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        lx[i] = max(lx[i], g[i][j]);
      }
    }

    for (int i = 0; i < n; i++) {
      fill(slack.begin(), slack.end(), inf);
      fill(visx.begin(), visx.end(), false);
      fill(visy.begin(), visy.end(), false);
      bfs(i);
    }

    // custom
    vector<int> op;
    for(int i=0;i<m-1;i++){
    	for(int j=0;j<n;j++){
    		if(matchx[j]==i&&g[j][matchx[j]]>0){
    			op.push_back(j+1);break;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(g[i][matchx[i]]<=0){
			op.push_back(i+1);op.push_back(-i-1);
		}
	}
	for(i=0;i<n;i++){
		if(matchx[i]==m-1&&g[i][matchx[i]]>0){
			op.push_back(i+1);break;
		}
	}
	cout<<op.size()<<endl;
	for(auto i:op)printf("%d ",i);
	puts("");
  }
};

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		hung<int> hu(n,m);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(j>m)hu.addEdge(i-1,j-1,-1);
				else hu.addEdge(i-1,j-1,a[i]-b[i]*(m-j)+10000000);
			}
		}
		hu.solve();
	}
	
}