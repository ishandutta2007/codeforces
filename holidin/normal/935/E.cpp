#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define Size(x) ((int)(x).size())
typedef long long ll;
typedef long double ld;
typedef pair<int , int>pii;
const int INF = 1e9 + 10 , MN = 1e4 + 20 , MK = 105;

int New , mn[MK][MN] , mx[MK][MN] , L[MN] , R[MN];
string s;
bool F;

int sparse(int b,int e){
	int v = New++;
	if(e - b == 1){
		mn[0][v] = mx[0][v] = s[b] - '0';
		return v;
	}
	int cnt = 0;
	for(int i=b;i<e;++i){
		cnt += s[i] == '(';
		cnt -= s[i] == ')';
		if(cnt == 1 && s[i] == '?'){
			L[v] = sparse(b+1 , i);
			R[v] = sparse(i+1 , e-1);
			break;
		}
	}
	return v;
}

void calc(int s){
	if(L[s] == -1) return;
	calc(L[s]) , calc(R[s]);
	if(F){ // ye bo'd ru jamas
		for(int i=0;i<MK;++i) // beynesh '+'
			for(int j=0;j<i;++j){
				mn[i][s] = min(mn[i][s] , mn[j][L[s]] + mn[i-j-1][R[s]]);
				mx[i][s] = max(mx[i][s] , mx[j][L[s]] + mx[i-j-1][R[s]]);
			}
		for(int i=0;i<MK;++i) // beynesh '-'
			for(int j=0;j<=i;++j){
				mn[i][s] = min(mn[i][s] , mn[j][L[s]] - mx[i-j][R[s]]);
				mx[i][s] = max(mx[i][s] , mx[j][L[s]] - mn[i-j][R[s]]);
			}
	}else{
		for(int i=0;i<MK;++i) // beynesh '+'
			for(int j=0;j<=i;++j){
				mn[i][s] = min(mn[i][s] , mn[j][L[s]] + mn[i-j][R[s]]);
				mx[i][s] = max(mx[i][s] , mx[j][L[s]] + mx[i-j][R[s]]);
			}
		for(int i=0;i<MK;++i) // beynesh '-'
			for(int j=0;j<i;++j){
				mn[i][s] = min(mn[i][s] , mn[j][L[s]] - mx[i-j-1][R[s]]);
				mx[i][s] = max(mx[i][s] , mx[j][L[s]] - mn[i-j-1][R[s]]);
			}
	}
}

int main(){
	ios_base :: sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	memset(L , -1 , sizeof L);
	memset(R , -1 , sizeof R);
	for(int i=0;i<MK;++i){
		fill(mn[i] , mn[i] + MN , INF);
		fill(mx[i] , mx[i] + MN , -INF);
	}
	cin>>s;
	int id = sparse(0 , Size(s));
	int x,y;cin>>x>>y;
	if(x < y){
		F = true;
		calc(id);
		cout << mx[x][id] << '\n';
	}else{
		calc(id);
		cout << mx[y][id] << '\n';
	}
	return 0;
}