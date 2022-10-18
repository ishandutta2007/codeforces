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

int t[200010], p[200010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h, ociec=-1, ver=-1, ojc=-1, nr=0, lastek=0;
	cin>>h;
	FOR(i, 0, h){
		cin>>t[i];
	}
	lastek=-1;
	FOR(i, 0, h){
		FOR(j, 1, t[i]){
			if(i-1>lastek && ver==-1){
				lastek=0;
				ojc=-1;
			}
			if(j+1==t[i] && ojc==-1){
				ojc=nr;
				p[nr++]=ociec;
				p[nr++]=ociec;
				lastek=i;
				break;
			}
			else if(j+1==t[i] && ojc>-1 && ver==-1 && i-1==lastek){
				ver=nr;
			}
			p[nr++]=ociec;
		}
		ociec=nr-1;
	}
	if(ver==-1 || ojc==-1){
		cout<<"perfect"<<ent;
		return 0;
	}
	cout<<"ambiguous"<<ent;
	FOR(i, 0, nr-1){
		cout<<p[i]+1<<sp;
		if(i==ver){
			p[i]=ojc;
		}
	}
	cout<<ent;
	FOR(i, 0, nr-1){
		cout<<p[i]+1<<sp;
	}
	cout<<ent;
	return 0;
}