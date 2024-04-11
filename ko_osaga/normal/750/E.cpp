#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int MAXN = 200005;

struct query{
	int s, e, idx;
};

int n, q, ret[MAXN];
char str[MAXN];
int dl[MAXN][6], dr[MAXN][6];

int code(char c){
	if(c == '2') return 0;
	if(c == '0') return 1;
	if(c == '1') return 2;
	if(c == '6') return 3;
	if(c == '7') return 4;
	return -1;
}

void solve(int s, int e, vector<query> v){
	if(s == e){
		return;
	}
	int m = (s+e)/2;
	vector<query> l, r, x;
	for(auto &i : v){
		if(i.e <= m) l.push_back(i);
		else if(i.s > m) r.push_back(i);
		else x.push_back(i);
	}
	solve(s, m, l);
	solve(m+1, e, r);
	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			dl[m+1][j] = dr[m][j] = 1e9;
		}
		dl[m+1][i] = dr[m][i] = 0;
		for(int j=m; j>=s; j--){
			int val = code(str[j]);
			for(int k=0; k<6; k++){
				if(val == -1){
					dl[j][k] = dl[j+1][k];
				}
				else if(val <= 2){
					if(k == val) dl[j][k] = min(dl[j+1][k] + 1, dl[j+1][k+1]);
					else dl[j][k] = dl[j+1][k];
				}
				else if(val == 3){
					if(k == 3 || k == 4) dl[j][k] = min(dl[j+1][k] + 1, dl[j+1][5]);
					else dl[j][k] = dl[j+1][k];
				}
				else{
					if(k == 3) dl[j][k] = min(dl[j+1][k] + 1, dl[j+1][k+1]);
					else dl[j][k] = dl[j+1][k];
				}
			}
		}
		for(int j=m+1; j<=e; j++){
			int val = code(str[j]);
			for(int k=0; k<6; k++){
				if(val == -1){
					dr[j][k] = dr[j-1][k];
				}
				else if(val <= 2){
					if(k == val+1) dr[j][k] = min(dr[j-1][k], dr[j-1][k-1]);
					else dr[j][k] = dr[j-1][k] + (k == val);
				}
				else if(val == 3){
					if(k == 3 || k == 4) dr[j][k] = dr[j-1][k] + 1;
					else if(k == 5) dr[j][k] = min({dr[j-1][3], dr[j-1][4], dr[j-1][5]});
					else dr[j][k] = dr[j-1][k];
				}
				else{
					if(k == 4) dr[j][k] = min(dr[j-1][k], dr[j-1][k-1]);
					else dr[j][k] = dr[j-1][k] + (k == 3);
				}
			}
		}
		for(auto &i : x){
			ret[i.idx] = min(dl[i.s][0] + dr[i.e][4], ret[i.idx]);
		}
	}
}

int main(){
	scanf("%d %d %s",&n,&q,str+1);
	vector<query> v;
	for(int i=0; i<q; i++){
		query qr;
		scanf("%d %d",&qr.s,&qr.e);
		qr.idx = i;
		v.push_back(qr);
	}
	memset(ret, 0x3f, sizeof(ret));
	solve(1, n, v);
	for(int i=0; i<q; i++){
		if(ret[i] > 1e8) ret[i] = -1;
		printf("%d\n", ret[i]);
	}
}