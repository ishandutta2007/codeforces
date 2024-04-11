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

ll t[1010], t2[1010];
vii pr;
ll numb=0;
vi maksy;

bool check(int a, int b){
	ll maksio=-1, cyk=0;
	FOR(i, a, b){
		if(t[i]>maksio){
			maksio=t[i];
			cyk=1;
		}
		else if(t[i]==maksio){
			cyk++;
		}
	}
	if(cyk==b-a+1 && b-a>0){
		return true;
	}
	return false;
}

void maker(int a, int b, int he){
	ll maksio=-1, aya=-1;
	maksy.clear();
	FOR(i, a, b){
		if(t[i]>maksio){
			maksio=t[i];
			maksy.clear();
			maksy.pb(i);
		}
		else if(t[i]==maksio){
			maksy.pb(i);
		}
	}
	for(auto x: maksy){
		if(x>a && t[x]>t[x-1]){
			aya=x;
			numb=he+aya-a;
			FORD(i, aya, a+1){
				cout<<numb<<sp<<"L"<<ent;
				numb--;
			}
			FOR(i, aya, b-1){
				cout<<numb<<sp<<"R"<<ent;
			}
			break;
		}
		else if(x<b && t[x]>t[x+1]){
			aya=x;
			numb=he+aya-a;
			FOR(i, aya, b-1){
				cout<<numb<<sp<<"R"<<ent;
			}
			FORD(i, aya, a+1){
				cout<<numb<<sp<<"L"<<ent;
				numb--;
			}
			break;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, pocz=1, sum=0, j=1;
	cin>>n;
	FOR(i, 1, n){
		cin>>t[i];
	}
	cin>>m;
	FOR(i, 1, m){
		cin>>t2[i];
	}
	FOR(i, 1, n){
		sum+=t[i];
		if(j>m){
			cout<<"NO"<<ent;
			return 0;
		}
		if(sum==t2[j]){
			pr.pb({pocz, i});
			pocz=i+1;
			sum=0;
			j++;
		}
		else if(sum>t2[j]){
			cout<<"NO"<<ent;
			return 0;
		}
	}
	if(j<=m){
		cout<<"NO"<<ent;
		return 0;
	}
	for(auto x: pr){
		if(check(x.st, x.nd)){
			cout<<"NO"<<ent;
			return 0;
		}
	}
	cout<<"YES"<<ent;
	FOR(i, 0, SIZE(pr)-1){
		maker(pr[i].st, pr[i].nd, i+1);
	}
	return 0;
}