#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=3010,A=256; // dict max size, alphabet size
int n;
string text;
string d[N]; // dictionary
struct vertex{
	int next[A]; // trie + automaton combined
	vector<int>ids,cumids; // ids of strings of all suffixes
	int id,p,pc,l=-1,cum=0; // id, parent, previous char, link, calculated cumulative endings?
	vertex(int id=0,int p=0,int pc=0):id(id),p(p),pc(pc){
		memset(next,-1,sizeof(next));
	}
};
vector<vertex>t(1); // trie

void add(int id){
	int u=0;
	for(char c:d[id]){
		if(t[u].next[c]==-1){ // no edge
			t[u].next[c]=t.size(); // new node
			t.push_back(vertex(t[u].next[c],t[u].id,c)); // create it
		}
		u=t[u].next[c]; // next node
	}
	t[u].ids.push_back(id); // string ends here
}

int getnext(int u,int c);

int getlink(int u){ // gets link otherwise gets next of parents link
	if(t[u].l==-1)t[u].l=t[u].p?getnext(getlink(t[u].p),t[u].pc):0; // depth<=1 => link=0
	return t[u].l;
}

int getnext(int u,int c){ // gets next state or next state of parents link
	if(t[u].next[c]==-1)t[u].next[c]=u?getnext(getlink(u),c):0; // nothing new for u==0
	return t[u].next[c];
}

// this is kinda a bonus, the link system is the basics that will be needed for problem solving
// but whatever you'll need to implement will be implemented in the same way with this dp system of sorts
// just build the links first (in theory) and then use the same strategy for whatever you need to build next
vector<int>getcum(int u){ // gets the ids of strings that match somewhere in this node
	if(t[u].cum||!u)return t[u].cumids;
	t[u].cum=1;
	auto cum=getcum(getlink(u)); // gets cum of previous suffix
	vector<int>res(t[u].ids.size()+cum.size(),-1);
	set_union(t[u].ids.begin(),t[u].ids.end(),cum.begin(),cum.end(),res.begin()); // union with self
	while(res.size()&&res.back()==-1)res.pop_back();
	return t[u].cumids=res;
}

// returns set of ids of strings that were found
set<int>traverse(string &t){
	int u=0;
	set<int>res; // union of all matches in visited nodes
	for(auto c:t){
		u=getnext(u,c);
		vector<int>cum=getcum(u);
		for(auto idx:cum)res.insert(idx);
	}
	return res;
}
int id;
string s;
int x;

bool isprime(string s){
	int n=s.size();
	bool p=true;
	for(int i=0;i<n;++i){
		int sm=0;
		for(int j=i;j<n-!i;++j){
			sm+=s[j]-'0';
			if(x%sm==0)p=false;
		}
	}
	return p;
}
void getprimes(string cur,int sum){
	if(sum>x)return;
	if(sum==x&&isprime(cur))d[id++]=cur;
	else for(int i=1;i<=9;++i)getprimes(cur+string(1,'0'+i),sum+i);
}

const int inf=1e9;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>s>>x;
	n=s.size();
	getprimes("",0);
	for(int i=0;i<id;++i)add(i);
	vector<int>dp(t.size(),inf);
	dp[0]=0;
	for(int i=0;i<n;++i){
		vector<int>newdp(t.size(),inf);
		for(int j=0;j<t.size();++j)
			if(dp[j]!=inf){
				newdp[j]=min(newdp[j],dp[j]+1);
				if(!getcum(getnext(j,s[i])).size())newdp[getnext(j,s[i])]=min(newdp[getnext(j,s[i])],dp[j]);
			}
		swap(dp,newdp);
	}
	cout<<*min_element(dp.begin(),dp.end())<<endl;
}