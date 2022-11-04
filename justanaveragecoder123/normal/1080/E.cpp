#include<bits/stdc++.h>
using namespace std;

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;	
vector<array<int, 26>> res;
array<int, 26> URES={-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void expand(vector<array<int, 26>>& t) {
	res.resize(t.size()*2+1);
	res[0]=URES;
	int ind=1;
	for(auto i:t) {
		res[ind]=i;
		res[ind+1]=URES;
		ind++;
		ind++;
	
	}
	
}

vector<int> p;
	ll ans=0;

void manacher(vector<array<int, 26>>& t) {
	p.resize(t.size());
	int c=0, r=0;
	
	for(int i=0;i<sz(t);++i) {
		int mirror=c-(i-c);
		if(mirror>=0&&p[mirror]<r-i) {
			p[i]=p[mirror];
		}else {
			p[i]=r-i;
			
			while(i-p[i]>=0 && i+p[i]<sz(t) && t[i-p[i]]==t[i+p[i]]) p[i]++;
			p[i]--;
			
			if(i+p[i]>r) {
				c=i;
				r=i+p[i];
			}
		}
		
		if(t[i][0]>=-1) ans+=(p[i]+1)/2;
	}
}

int szum[252][252][27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i) {
		string x;
		cin>>x;
		for(int j=0;j<sz(x);++j) {
			szum[i][j][x[j]-'a']++;
		}
	}
	
	for(int k=0;k<26;++k) {
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				szum[i][j][k]+=(j>0?szum[i][j-1][k]:0);
			}
		}
	}
	
	vector<array<int, 26>> t(n);
	for(int i=0;i<n;++i) t[i]=array<int, 26>();

	array<int, 26> ind;
		
	for(int col1=0;col1<m;++col1) {
		for(int col2=col1;col2<m;++col2) {
			ind[0]=-2;
			
			for(int i=0;i<n;++i) {
				int ps=0, prt=0;

				for(int k=0;k<26;++k) {
					t[i][k]=szum[i][col2][k]-(col1>0?szum[i][col1-1][k]:0);
					
					if(t[i][k]&1) prt++;
					else ps++;
				}
				
				if(prt>1) {
					t[i]=ind;				
					ind[0]--;
				}	
			}
			
			expand(t);
			manacher(res);
		}
	}
	
	cout<<ans<<"\n";
	
	
	return 0;
}