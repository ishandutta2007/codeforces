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

bool t[60][60];
int n;

bool put(int a, int b){
	if(a>n || b>n || a<1 || b<1) return false;
	if(t[a][b]) return false;
	return t[a][b]=1;
}

bool place(int a, int b){
	return put(a, b) && put(a+1, b) && put(a+2, b) && put(a+1, b-1) && put(a+1, b+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	cin>>n;
	FOR(i, 1, n){
		cin>>s;
		FOR(j, 0, SIZE(s)-1){
			if(s[j]=='#') t[i][j+1]=1;
		}
	}
	FOR(i, 1, n){
		FOR(j, 1, n){
			if(!t[i][j]){
				if(!place(i, j)){
					cout<<"NO\n";
					return 0;
				}
			}
		}
	}
	cout<<"YES\n";
	return 0;
}