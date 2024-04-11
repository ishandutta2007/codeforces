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

const int N=1e5;

vector<pair<ii, int> > q;
int t[N+5], licz[N+5], odp[N+5];
int akt, blok;

bool cmp(pair<ii, int> &a, pair<ii, int> &b){
	if(a.st.st/blok == b.st.st/blok){
		return a.st.nd < b.st.nd;
	}
	return a.st.st/blok < b.st.st/blok;
}

void dodaj(int a, int b){
	if(b<a){
		swap(a, b);
	}
	FOR(i, a, b){
		// cout<<"dod: "<<i<<ent;
		licz[t[i]]++;
		if(licz[t[i]]==t[i]){
			akt++;
		}
		if(licz[t[i]]==t[i]+1){
			akt--;
		}
	}
}

void usun(int a, int b){
	if(b<a){
		swap(b, a);
	}
	FOR(i, a, b){
		// cout<<"usu: "<<i<<ent;
		licz[t[i]]--;
		if(licz[t[i]]==t[i]){
			akt++;
		}
		if(licz[t[i]]==t[i]-1){
			akt--;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin>>n>>m;
	blok=sqrt(m);
	FOR(i, 1, n){
		cin>>t[i];
		if(t[i]>n){
			t[i]=N+2;
		}
	}
	t[0]=N+2;
	FOR(i, 1, m){
		cin>>a>>b;
		q.pb({{a, b}, i});
	}
	sort(q.begin(), q.end(), cmp);
	a=0, b=0;
	for(auto x: q){
		if(x.st.st>a){
			usun(a, x.st.st-1);
		}
		else if(x.st.st<a){
			dodaj(a-1, x.st.st);
		}
		if(x.st.nd>b){
			dodaj(b+1, x.st.nd);
		}
		else if(x.st.nd<b){
			usun(b, x.st.nd+1);
		}
		a=x.st.st;
		b=x.st.nd;
		odp[x.nd]=akt;
	}
	FOR(i, 1, m){
		cout<<odp[i]<<ent;
	}
	return 0;
}