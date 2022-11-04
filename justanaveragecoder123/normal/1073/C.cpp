#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;

int u[200001];
int d[200001];
int l[200001];
int r[200001];

int main() {
	IO;
	int n;string t;
	cin>>n>>t;
	int aktx=0, akty=0;
	for(int i=0;i<sz(t);++i) {
		if(t[i]=='U') u[i]++, akty++;
		else if(t[i]=='D') d[i]++, akty--;
		else if(t[i]=='L') l[i]++, aktx--;
		else if(t[i]=='R') r[i]++, aktx++;
		else assert(0);
	}
	
	int x,y;
	cin>>x>>y;
	
	if(x==aktx && y==akty) {
		cout<<"0\n";
		return 0;
	}
	
	int sol=1e9;
	
	int l=0, r=-1;
	while(l<sz(t) && r<sz(t)) {
		//cerr<<l<<" "<<r<<"\n";
		while(l<=r) {
			int len=r-l+1;
			int dist=abs(aktx-x)+abs(akty-y);
			if(dist<=len && (len-dist)%2==0) {
				sol=min(sol, len);
				if(t[l]=='U') akty++;
				else if(t[l]=='D') akty--;
				else if(t[l]=='L') aktx--;
				else if(t[l]=='R') aktx++;
				l++;
			}else break;
		}
		
		if(r==sz(t)-1) break ;
		
		r++;
		if(t[r]=='U') akty--;
		else if(t[r]=='D') akty++;
		else if(t[r]=='L') aktx++;
		else if(t[r]=='R') aktx--;
	}
	
	cout<<(sol==(int)1e9?-1:sol)<<"\n";
	return 0;
}