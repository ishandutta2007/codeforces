//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int N=250;
const int NN=1e5+5;

int memo[N+5][N+5][N+5];
int najb[NN][32];
int n, q, kt, ak[4];
string ss, s[4];
char cc;

int dp(int a, int b, int c){
	if(memo[a][b][c]!=-1) return memo[a][b][c];
	if(a==0 && b==0 & c==0) return memo[a][b][c]=0;
	memo[a][b][c]=inf;
	int pom;
	if(a!=0){
		pom=dp(a-1, b, c);
		if(pom<SIZE(ss)) memo[a][b][c]=min(memo[a][b][c], najb[pom+1][s[1][a-1]-'a']);
	}
	if(b!=0){
		pom=dp(a, b-1, c);
		if(pom<SIZE(ss)) memo[a][b][c]=min(memo[a][b][c], najb[pom+1][s[2][b-1]-'a']);
	}
	if(c!=0){
		pom=dp(a, b, c-1);
		if(pom<SIZE(ss)) memo[a][b][c]=min(memo[a][b][c], najb[pom+1][s[3][c-1]-'a']);
	}
	return memo[a][b][c];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	FOR(i, 0, N) FOR(j, 0, N) FOR(k, 0, N) memo[i][j][k]=-1;
	cin>>n>>q>>ss;
	ss='#'+ss;
	FOR(j, 0, 'z'-'a'+1) najb[SIZE(ss)][j]=inf;
	FORD(i, SIZE(ss)-1, 1){
		FOR(j, 0, 'z'-'a'+1) najb[i][j]=najb[i+1][j];
		najb[i][ss[i]-'a']=i;
	}
	FOR(te, 1, q){
		cin>>cc>>kt;
		if(cc=='+'){
			cin>>cc;
			s[kt]+=cc;
			ak[kt]++;
		}
		else{
			s[kt].pop_back();
			if(kt==1){
				FOR(i, 0, ak[2]) FOR(j, 0, ak[3]) memo[ak[1]][i][j]=-1;
			}
			else if(kt==2){
				FOR(i, 0, ak[1]) FOR(j, 0, ak[3]) memo[i][ak[2]][j]=-1;
			}
			else{
				FOR(i, 0, ak[1]) FOR(j, 0, ak[2]) memo[i][j][ak[3]]=-1;
			}
			ak[kt]--;
		}
		if(dp(ak[1], ak[2], ak[3])!=inf) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}