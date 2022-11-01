#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define ll long long
const int _ = 4e5 + 7 , __ = _ * 40 , MOD = 1073741823;
struct VI{
	int sz , arr[3]; VI(){memset(arr , 0 , sizeof(arr)); sz = 0;}
	int& operator [](int x){return arr[x];}
	void push_back(int x){arr[sz++] = x;}
}ch[_];
vector < pair < int , int > > nxt[_]; vector < pair < int , ll > > fa[_];
struct Edge{int end , upEd , w;}Ed[_ << 1]; int N , Q , head[_] , p[_] , cntEd; ll lastans;
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}

void rebuild(int x , int p){
	int pre = x;
	for(auto t : nxt[x])
		if(t.first != p){
			++N; addEd(pre , N , 0); addEd(N , pre , 0);
			pre = N; addEd(t.first , pre , t.second); addEd(pre , t.first , t.second);
			rebuild(t.first , x);
		}
}

int nsz , msz , id; bool vis[_];
void getsz(int x){
	vis[x] = 1; ++nsz;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]) getsz(Ed[i].end);
	vis[x] = 0;
}

int getrt(int x){
	int mx = 0 , sz = 1; vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){int t = getrt(Ed[i].end); mx = max(mx , t); sz += t;}
	mx = max(mx , nsz - sz); if(msz > mx){msz = mx; id = x;}
	vis[x] = 0; return sz;
}

void getfa(int x , ll l , int r){
	vis[x] = 1; fa[x].push_back(make_pair(r , l));
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]) getfa(Ed[i].end , l + Ed[i].w , r);
	vis[x] = 0;
}

int dfz(int x){
	nsz = 0; msz = 1e9; getsz(x); getrt(x); x = id; getfa(x , 0 , x); vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd) if(!vis[Ed[i].end]) ch[x].push_back(dfz(Ed[i].end));
	return x;	
}

int dfn[_] , ind[_] , sz[_] , ts;
void getdfn(int x){sz[x] = 1; ind[dfn[x] = ++ts] = x; for(int i = 0 ; i < ch[x].sz ; ++i){getdfn(ch[x][i]); sz[x] += sz[ch[x][i]];}}

struct data{int rep , sz; VI ch; ll sum; data(){rep = sum = 0;}}now[__]; int rt[_] , cnt;

int mdf(int x , int r , int to , int flg , int pos){
	now[++cnt] = now[x]; now[cnt].rep = r; now[cnt].sz += flg;
	now[cnt].sum += flg * (fa[to][pos].second - (pos ? fa[to][pos - 1].second : 0)); 
	if(r == to) return cnt;
	x = cnt;
	for(int i = 0 ; i < 3 ; ++i)
		if(dfn[ch[r][i]] + sz[ch[r][i]] > dfn[to]){
			now[x].ch[i] = mdf(now[x].ch[i] , ch[r][i] , to , flg , pos + 1); break;
		}
	return x;
}

ll qry(int x , int r , int to , int pos){
	ll sum = now[x].sum + (fa[to][pos].second - (pos ? fa[to][pos - 1].second : 0)) * now[x].sz;
	if(r == to) return sum;
	for(int i = 0 ; i < 3 ; ++i)
		if(dfn[ch[r][i]] + sz[ch[r][i]] > dfn[to]){
			sum += qry(now[x].ch[i] , ch[r][i] , to , pos + 1); break;
		}
	return sum;
}

int main(){
	N = read(); Q = read(); for(int i = 1 ; i <= N ; ++i) p[i] = read();
	for(int i = 1 ; i < N ; ++i){int p = read() , q = read() , w = read(); nxt[p].push_back(make_pair(q , w)); nxt[q].push_back(make_pair(p , w));}
	rebuild(1 , 0); int Rt = dfz(1); getdfn(Rt);
	for(int i = 1 ; p[i] ; ++i) rt[i] = mdf(rt[i - 1] , Rt , p[i] , 1 , 0);
	while(Q--)
		if(read() == 1){
			int l = read() ^ lastans , r = read() ^ lastans , v = read() ^ lastans;
			printf("%lld\n" , lastans = qry(rt[r] , Rt , v , 0) - qry(rt[l - 1] , Rt , v , 0)); lastans &= MOD;
		}else{int x = read() ^ lastans; rt[x] = mdf(mdf(rt[x] , Rt , p[x] , -1 , 0) , Rt , p[x + 1] , 1 , 0); swap(p[x] , p[x + 1]);}
	return 0;
}