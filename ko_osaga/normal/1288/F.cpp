#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 205;
const int mod = 1e9 + 7;
const llf eps = 1e-8;

vector<llf> simplex(vector<vector<llf> > A, vector<llf> b, vector<llf> c) {
  int n = (int) A.size(), m = (int) A[0].size()+1, r = n, s = m-1;
  vector<vector<llf> > D = vector<vector<llf> > (n+2, vector<llf>(m+1));
  vector<int> ix = vector<int> (n+m);
  for (int i=0; i<n+m; i++) ix[i] = i;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m-1; j++)D[i][j]=-A[i][j];
    D[i][m-1] = 1;
    D[i][m] = b[i];
    if (D[r][m] > D[i][m]) r = i;
  }
  for (int j=0; j<m-1; j++) D[n][j]=c[j];
  D[n+1][m-1] = -1; int z = 0;
  for (llf d;;) {
    if (r < n) {
      swap(ix[s], ix[r+m]);
      D[r][s] = 1.0/D[r][s];
      for (int j=0; j<=m; j++) if (j!=s) D[r][j] *= -D[r][s];
      for(int i=0; i<=n+1; i++)if(i!=r) {
        for (int j=0; j<=m; j++) if(j!=s) D[i][j] += D[r][j] * D[i][s];
        D[i][s] *= D[r][s];
      }
    }
    r = -1; s = -1;
    for (int j=0; j <m; j++) if (s<0 || ix[s]>ix[j]) {
      if (D[n+1][j]>eps || D[n+1][j]>-eps && D[n][j]>eps) s = j;
    }
    if (s < 0) break;
    for (int i=0; i<n; i++) if(D[i][s]<-eps) {
      if (r < 0 || (d = D[r][m]/D[r][s]-D[i][m]/D[i][s]) < -eps
        || d < eps && ix[r+m] > ix[i+m]) r=i;
    }
    if (r < 0) return vector<llf>(); // unbounded
  }
  if (D[n+1][m] < -eps) return vector<llf>(); // infeasible
  vector<llf> x(m-1);
  for (int i = m; i < n+m; i ++) if (ix[i] < m-1) x[ix[i]] = D[i-m][m];
  return x; // ans: D[n][m]
}

vector<int> g1[MAXN], g2[MAXN];
llf a[1005][405], b[1005], c[1005];

int main(){
	int l, r, m, x, y; 
	string s1, s2;
	cin >> l >> r >> m >> x >> y;
	cin >> s1 >> s2;
	vector<pi> A(m);
	int piv = 1;
	for(int i=0; i<m; i++){
		cin >> A[i].first >> A[i].second;
		A[i].first--;
		A[i].second--;
		g1[A[i].first].push_back(i);
		g2[A[i].second].push_back(i);
		c[2*i+1] = -x;
		c[2*i+2] = -y;
		a[piv][2*i+1] = 1;
		a[piv][2*i+2] = 1;
		b[piv] = 1;
		piv++;
	}
	for(int i=0; i<l; i++){
		if(s1[i] == 'R'){
			for(auto &j : g1[i]){
				a[piv][2*j+1] += -1;
				a[piv][2*j+2] += 1;
			}
			b[piv++] += -1;
		}
		if(s1[i] == 'B'){
			for(auto &j : g1[i]){
				a[piv][2*j+1] += 1;
				a[piv][2*j+2] += -1;
			}
			b[piv++] += -1;
		}
	}
	for(int i=0; i<r; i++){
		if(s2[i] == 'R'){
			for(auto &j : g2[i]){
				a[piv][2*j+1] += -1;
				a[piv][2*j+2] += 1;
			}
			b[piv++] += -1;
		}
		if(s2[i] == 'B'){
			for(auto &j : g2[i]){
				a[piv][2*j+1] += 1;
				a[piv][2*j+2] += -1;
			}
			b[piv++] += -1;
		}
	}
	vector<vector<llf>> AA;
	vector<llf> B(b + 1, b + piv);
	vector<llf> C(c + 1, c + 2 * m + 1);
	for(int i=1; i<=piv-1; i++){
		vector<llf> t(a[i] + 1, a[i] + 2 * m + 1);
		AA.push_back(t);
	}
	auto ans = simplex(AA, B, C);
	if(ans.empty()){
		puts("-1");
		return 0;
	}
	string dap;
	dap.resize(m);
	for(int i=0; i<m; i++){
		if(ans[2*i] + ans[2*i+1] > 1 - eps){
			if(ans[2*i] > ans[2*i+1]) dap[i] = 'R';
			else dap[i] = 'B';
		}
		else dap[i] = 'U';
	}
	cout << count(all(dap), 'R') * x + count(all(dap), 'B') * y << endl;
	cout << dap << endl;
}