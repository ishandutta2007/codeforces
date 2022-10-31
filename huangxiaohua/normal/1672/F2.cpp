#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[500500],p[500500],it,s[500500],num[500500],b[500500];
vector<int> v[500500],v2[500500];
set<int> v0[500500];
vector<pair<int,int> >v1;

void fuck(){
	it=0;
	map<int,int> mp;
	for(i=1;i<=n;i++){
		s[i]=0;
		num[i]=0;
		v[i].clear();
		v2[i].clear();
	}
	for(i=1;i<=n;i++){
		v2[a[i]].push_back(i);
		num[a[i]]++;
		mp[a[i]]++;
	}
	
	v1.clear();
	for(auto [x,y]:mp){
		v1.push_back({y,x});
	}
	sort(v1.begin(),v1.end());
	reverse(v1.begin(),v1.end());
	
	for(auto [y,x]:v1){
		it=max(it,y);
		for(i=0;i<y;i++){
			v[i+1].push_back(v2[x][i]);
		}
	}

	for(i=1;i<=it;i++){
		int lst=0;
		for(auto j:v[i]){
			if(lst){
				p[lst]=a[j];
			}
			lst=j;
		}
		p[lst]=a[v[i][0]];
	}
	
	//for(i=1;i<=n;i++){cout<<p[i]<<' ';}cout<<'\n';
}

int low[500500], dfn[500500], d[500500], dd[500500], cnt, flag[500500];
queue<int> q;
stack<int> st;
void tarjan(int u) {
    low[u] = dfn[u] = ++cnt;
    st.push(u);
    flag[u] = 1;

    for (auto v:v0[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (flag[v])
            low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            flag[v] = 0;
            dd[v] = u;
            d[u]++;

            if (u == v)
                break;
        }
    }
}

bool chk(int b[]){
	memset(num,0,n*4+50);
	int mx=0,m2=0;
	for(i=1;i<=n;i++){
		num[a[i]]++;
		if(num[a[i]]>mx){
			mx=num[a[i]];m2=a[i];
		}
		v0[i].clear();
	}
	
	memset(num,0,n*4+50);
	for(i=1;i<=n;i++){
		if(a[i]==m2||b[i]==m2)continue;
		if(a[i]==b[i])return 0;
		
		num[a[i]]=num[b[i]]=1;
		v0[a[i]].insert(b[i]);
	}
	cnt=0;
	memset(low,0,n*4+50);
	memset(dfn,0,n*4+50);
	memset(flag,0,n*4+50);
	memset(dd,0,n*4+50);
	memset(d,0,n*4+50);
	for(i=1;i<=n;i++){
		if(!dfn[i])tarjan(i);
	}
	memset(dfn,0,n*4+50);
	for(i=1;i<=n;i++){
		if(!num[i])continue;
		if(dfn[dd[i]])return 0;
		dfn[dd[i]]=1;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++)cin>>b[i];
		fuck();k=chk(p);if(!k)return 1;
		k=chk(b);
		cout<<(k?"AC\n":"WA\n");
	}
}