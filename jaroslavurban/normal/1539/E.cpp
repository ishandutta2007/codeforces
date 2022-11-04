#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXSIZE = 1 << 18 | 1;
char buf[MAXSIZE], *p1, *p2;

inline int Gc() {
	return p1 == p2 &&
		(p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
}
template<typename T> inline void read(T& x) {
	x = 0; int f = 0, ch = Gc();
	while (!isdigit(ch)) f |= ch == '-', ch = Gc();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
	if (f) x = -x;
}

inline void write(register int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10^48);
}


const int N=100100;
int other[N][2]; // index of the other ball

void ProGamerMove(){
	memset(other,-1,sizeof(other));
	int n,m;read(n);read(m);
	set<pair<int,int>>through[2]; // pos, idx
	set<int>tidx[2]; // only balls that can win like this
	for(int j=0;j<2;++j){
		through[j].insert({0,-1});
		tidx[j].insert(-1);
	}
	int last[2]={-1,-1}; // idx of ball that can't be taken to left, right
	auto trim=[&](int l,int r,int i){
		for(auto it=through[i].begin();it!=through[i].end()&&it->first<l;it=through[i].erase(it))tidx[i].erase(it->second);
		for(auto it=through[i].end();it!=through[i].begin()&&prev(it)->first>r;it=through[i].erase(prev(it)))tidx[i].erase(prev(it)->second);
	};
	for(int i=0;i<n;++i){
		int k;read(k);
		int l[2],r[2];read(l[0]);read(r[0]);read(l[1]);read(r[1]);
		int found=0;
		// put it to left
		// remove that can't take right
		for(int j=0;j<2;++j){
			trim(l[!j],r[!j],!j);
			if(l[j]<=k&&k<=r[j]&&tidx[!j].size()&&*tidx[!j].rbegin()>=last[j]){
//				cerr<<i<<" can do "<<j<<endl;
				other[i][j]=*tidx[!j].rbegin()+1;
				found=true;
			}
		}
		if(!found){cout<<"No\n";return;}
		for(int j=0;j<2;++j){
			if(other[i][j]>=0){
				through[j].insert({k,i});
				tidx[j].insert(i);
			}
			if(r[j]<k||k<l[j])last[j]=i;
		}
	}
	vector<int>res;
	pair<int,int>cur;
	if(other[n-1][0]>=0)cur={n,0};
	else if(other[n-1][1]>=0)cur={n,1};
	else assert(0);
	for(;cur.first;){
		auto[idx,p]=cur;--idx;
		int nidx=other[idx][p];
		assert(nidx-1<idx);
		assert(nidx>=0);
		for(int i=nidx;i<=idx;++i)res.push_back(p);
		cur={nidx,p^1};
	}
	assert(res.size()==n);
	reverse(res.begin(),res.end());
	cout<<"Yes\n";
	for(auto r:res){
		write(r);putchar(' ');
	}
	putchar('\n');
}

signed main(){
//	cin.tie(0)->sync_with_stdio(0);
//	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}