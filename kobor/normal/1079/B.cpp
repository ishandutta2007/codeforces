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
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

string sa;

int podzial(int a, int b){
	return a*b-SIZE(sa);
}

void dziel(int a, int b, int ile){
	string s[5];
	int pt=0;
	FOR(i, 0, a-1){
		FOR(j, 1, ile/a){
			s[i]+='*';
		}
	}
	ile=ile-(ile/a*a);
	while(ile){
		s[pt]+='*';
		pt=(pt+1)%a;
		ile--;
	}
	pt=0;
	FOR(i, 0, a-1){
		while(SIZE(s[i])<b){
			s[i]+=sa[pt++];
		}
	}
	FOR(i, 0, a-1){
		cout<<s[i]<<ent;
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>sa;
	FOR(i, 1, 5){
		FOR(j, 1, 20){
			if(podzial(i, j)>=0){
				cout<<i<<sp<<j<<ent;
				dziel(i, j, podzial(i, j));
				cout<<ent;
				return 0;
			}
		}
	}
	return 0;
}