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

const int N=3e5+5;
const int M=15e6+5;

int n;
int lp[M+5];
int minn[M], cont[M], sum[M];

void sieve(){
	for(int i=2; i*i<=M; i++){
		if(lp[i]) continue;
		for(int j=i*i; j<=M; j+=i){
			if(!lp[j]) lp[j]=i;
		}
	}
	memset(minn, inf, sizeof(minn));
}

void add(int a){
	int pom, cnt;
	while(a>1){
		pom=lp[a];
		if(!pom) pom=a;
		cnt=0;
		while(a%pom==0){
			a/=pom;
			cnt++;
		}
		if(minn[pom]>cnt){
			minn[pom]=cnt;
			cont[pom]=0;
		}
		if(minn[pom]==cnt) cont[pom]++;
		sum[pom]++;
	}
}

int f(int pr){
	if(sum[pr]<n) return n-sum[pr];
	return cont[pr];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	sieve();
	int a, ans=inf;
	cin>>n;
	FOR(i, 1, n){
		cin>>a;
		add(a);
	}
	FOR(i, 1, M-2) if(sum[i]) ans=min(ans, f(i));
	if(ans>=n) ans=-1;
	cout<<ans<<ent;
	return 0;
}