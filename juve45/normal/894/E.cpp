#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 1001000;
vector <long long> g[N], gt[N], c[N];
vector <pair<long long, long long> > v[N];
long long use[N], a, b, n, m, nrc, cc[N], x, gr[N];
long long scad[N], dp[N], sum[N];
stack <long long> s;
vector <pair<pair<long long, long long>, long long>> e;
 
void dfs1(long long k) {
    use[k]=1;
    for(auto i : g[k])
        if(!use[i])
            dfs1(i);
    s.push(k);
}
 
void dfs2(long long k) {
	// dbg(k);
    use[k]=1;
    for(auto i : gt[k]) 
        if(!use[i])
            dfs2(i);
    c[nrc].push_back(k);
    cc[k] = nrc;
}
 
void SCC() {
    for(long long i=1;i<=n;i++)
        if(!use[i])
            dfs1(i);
    memset(use, 0, sizeof use);

    while(!s.empty()) {
        long long a=s.top();
        // dbg(a);
        s.pop();
        if(!use[a])
            nrc++,
            dfs2(a);
    }
}

void dfs3(long long node) {
	use[node] = 1;
	for(auto i : v[node])
		if(!use[i.st])
			dfs3(i.st);
}

long long getv(long long val) {

	long long l = 1, r = 33000;
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		if(mid * (mid - 1) / 2 <= val) l = mid;
		else r = mid - 1;
	}
	long long rest = val - l * (l - 1) / 2;
	// dbg(l, rest);
	return l * val - scad[l];
}

int main() {
	ios_base::sync_with_stdio(false);
	
	for(long long i = 1; i <= 33000; i++)
		scad[i] = scad[i - 1] + i * (i - 1) / 2;

	 cin>>n>>m;
    
    for(long long i=1;i<=m;i++)
    {
    		cin >> a >> b >> x;
        g[a].push_back(b);
        gt[b].push_back(a);
        e.push_back({{a, b}, x});
    }
    long long ss;
    cin >> ss;
    SCC();
    
	// dbg(nrc);

	  for(auto i : e)
    	if(cc[i.st.st] == cc[i.st.nd]) 
    		sum[cc[i.st.st]] += getv(i.nd);
    	else 
    		v[cc[i.st.st]].push_back({cc[i.st.nd], i.nd});

    // dbg(sum[1]);
    // dbg(sum[2]);
    // dbg(sum[3]);
    // dbg(c[2]);
    // dbg(c[3]);

    memset(use, 0, sizeof use);
    dfs3(cc[ss]);
    // dbg_v(use, n + 1);

    for(long long i = 1; i <= nrc; i++) v[i].clear();

    for(auto i : e) {
    	// dbg(i, cc[i.st.st], cc[i.st.nd]);
    	if(cc[i.st.st] != cc[i.st.nd] && use[cc[i.st.st]] && use[cc[i.st.nd]]) 
    		v[cc[i.st.st]].push_back({cc[i.st.nd], i.nd}), gr[cc[i.st.nd]]++;
    }
    // dbg(v[1]);
    queue <long long> q;
    q.push(cc[ss]);
    dp[cc[ss]] = sum[cc[ss]];

    while(!q.empty()) {
    	long long x = q.front(); q.pop();
    	// dbg(x);

    	for(auto i : v[x]) {
    		dp[i.st] = max(dp[x] + i.nd + sum[i.st], dp[i.st]);
    		gr[i.st]--;
    		if(gr[i.st] == 0)
    			q.push(i.st);
    	}
    }
   long long ans = 0;
   for(long long i = 1; i <= nrc; i++)
   	ans = max(ans, dp[i]);
   cout << ans << '\n';
}