#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
const int N = (1<<12)+20;
vector < vector<int> >  Block[17];
vector < pair<int,int> > operators;
inline int merge(int a,int b){
	if(!a||!b)return a|b;
	operators.push_back(make_pair(a,b));
	return ++cnt;
}
int Limit;
int num;
int bel[N];
int a[N];
inline vector< vector<int> > get_idx(vector<int> idx, int all_rngs){
	int n = idx.size()-1;
	if(all_rngs==Limit){
		++num; for(int i=1;i<=n;i++)bel[idx[i]] = num;
	}
	if(all_rngs<Limit){
		vector<int> b;for(int i=1;i<=n;i++)b.push_back(a[idx[i]]);
		sort(b.begin(),b.end());
		int Split_Number=b[n/2-1];
		vector<int> Lft(1,0), Rgt(1,0);
		for(int i=1;i<=n;i++)
			if(a[idx[i]]<=Split_Number)Lft.push_back(idx[i]);
			else Rgt.push_back(idx[i]);
		vector < vector<int> > L = get_idx(Lft, all_rngs*2);
		vector < vector<int> > R = get_idx(Rgt, all_rngs*2);
		return vector< vector<int> >();
	}
	vector< vector<int> > ret(n+2, vector<int>(n+2));
	if(n==1){ret[1][1]=idx[1];}
	else{
		vector<int> b;for(int i=1;i<=n;i++)b.push_back(a[idx[i]]);
		sort(b.begin(),b.end());
		int Split_Number=b[n/2-1];
		vector<int> Lft(1,0), Rgt(1,0);
		for(int i=1;i<=n;i++)
			if(a[idx[i]]<=Split_Number)Lft.push_back(idx[i]);
			else Rgt.push_back(idx[i]);
		vector < vector<int> > L = get_idx(Lft, all_rngs*2);
		vector < vector<int> > R = get_idx(Rgt, all_rngs*2);
		vector<int> pref[2];pref[0]=pref[1]=vector<int>(n+1,0);
		for(int i=1;i<=n;i++){
			pref[0][i]=pref[0][i-1], pref[1][i]=pref[1][i-1];
			if(a[idx[i]]<=Split_Number)pref[0][i]++;
			else pref[1][i]++;
		}
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
			if(i==j)ret[i][j]=idx[i];
			else{
				ret[i][j]=merge(L[pref[0][i-1]+1][pref[0][j]],R[pref[1][i-1]+1][pref[1][j]]);
			}
		}
	}
	if(all_rngs==Limit){Block[num]=ret;}
//	puts("----");
//	for(int i=1;i<=n;i++){
//		cout << idx[i] << " ";
//	}puts("");
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout << ret[i][j] << (j==n?'\n':' ');
//	puts("----");
	return ret;
}

int pref[17][N];

int main()
{
	cin >> n >> m;cnt=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	Limit=1;while(Limit*2<=n&&Limit<16)Limit<<=1;
	vector<int> q(1,0);
	for(int i=1;i<=n;i++)q.push_back(i);
	get_idx(q,1);
//	cout << "idx_get_finish : " << " make " << num << " Blocks" << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=num;j++)pref[j][i]=pref[j][i-1];
		pref[bel[i]][i]++;
	}
	vector<int> ans;
	while(m--){
		int l,r;scanf("%d%d",&l,&r);
		int cur=0;
		for(int i=1;i<=num;i++){
			int _l=pref[i][l-1]+1, _r=pref[i][r];
			cur=merge(cur,Block[i][_l][_r]);
//			cout << _l << ":" << _r << endl;
		}
		ans.push_back(cur);
	}
	cout << cnt << endl;
	for(size_t i=0;i<operators.size();i++){
		printf("%d %d\n", operators[i].first, operators[i].second);
	}
	for(size_t i=0;i<ans.size();i++)printf("%d ", ans[i]);puts("");
	return 0;
}