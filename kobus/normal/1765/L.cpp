#include "bits/stdc++.h"
#define N 200009
#define INF 1000000007
#define ALL(s) s.begin(),s.end()
#define SZ(x) int((x).size())
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb push_back
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
set<int>bad_day;
vector<int>a[N],b[N];
int p[N],ans[N],active;
string days[]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
set<PII>s[7];
int day_number(string s){
	for(int i=0;i<7;i++)
		if(days[i]==s)
			return i;
	return -1;
}
void add(int id){
	int x=b[id][p[id]];
	for(auto d: a[x])
		s[d].insert(mp(x,id));
}
void rem(int id,int day){
	int x=b[id][p[id]];
	for(auto d: a[x])
		s[d].erase(mp(x,id));
	p[id]++;
	if(p[id]==b[id].size()){
	    ans[id]=day;
		active-=1;
	}
	else
	    add(id);
}
int main(){
	//freopen("file.in","r",stdin);
	int n,m,k;
	string sa;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int r;
		scanf("%d",&r);
		while(r--){
			cin>>sa;
			a[i].pb(day_number(sa));
		}
	}
	while(m--){
		int x;
		scanf("%d",&x);
		bad_day.insert(x);
	}
	active=k;
	for(int i=0;i<k;i++){
		int r;
		scanf("%d",&r);
		while(r--){
			int x;
			scanf("%d",&x);
			b[i].pb(x);
		}
		add(i);
	}
	stack<int>st;
	int day=0;
	while(active){
		if(bad_day.count(day+1)){
		    day++;
			continue;
		}
		auto it = s[day%7].begin();
		while(it != s[day%7].end()){
		    int who=it->first;
		    int id=it->second;
			st.push(id);
			it = s[day%7].upper_bound(mp(who,INF));
		}
		while(!st.empty()){
			rem(st.top(),day+1);
			st.pop();
		}
		day++;
	}
	for(int i=0;i<k;i++)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}