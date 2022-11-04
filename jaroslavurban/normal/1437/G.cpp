#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// cumids was previously:
//	auto cum=getcum(getlink(u)); // gets cum of previous suffix
//	vector<int>res(t[u].ids.size()+cum.size(),-1);
//	set_union(t[u].ids.begin(),t[u].ids.end(),cum.begin(),cum.end(),res.begin()); // union with self
//	while(res.size()&&res.back()==-1)res.pop_back();
//	return t[u].cumids=res;

// CHANGE NEXT TO MAP if N>100k
const int N=300100,A=256; // dict max size, alphabet size
int sus[N];
string text;
string d[N]; // dictionary
int nidx[N];
struct vertex{
	unordered_map<int,int>next; // trie + automaton combined
	// cumids contains not only previous ids, but also ids ending here
	multiset<int>ids,cumids; // ids of strings of all suffixes
	int id,p,pc,l=-1,tl=-1; // id, parent, previous char, link
	vertex(int id=0,int p=0,int pc=0):id(id),p(p),pc(pc){}
};
vector<vertex>t(1); // trie

void add(int id){
	int u=0;
	for(char c:d[id]){
		if(t[u].next.count(c)==0){ // no edge
			t[u].next[c]=t.size(); // new node
			t.push_back(vertex(t[u].next[c],t[u].id,c)); // create it
		}
		u=t[u].next[c]; // next node
	}
	t[u].ids.insert(0); // string ends here
	nidx[id]=u;
}

int getnext(int u,int c);

int getlink(int u){ // gets link otherwise gets next of parents link
	if(t[u].l==-1)t[u].l=t[u].p?getnext(getlink(t[u].p),t[u].pc):0; // depth<=1 => link=0
	return t[u].l;
}

int getnext(int u,int c){ // gets next state or next state of parents link
	if(t[u].next.count(c)==0)t[u].next[c]=u?getnext(getlink(u),c):0; // nothing new for u==0
	return t[u].next[c];
}

int gettl(int u){
	if(t[u].tl==-1)t[u].tl=u?(t[getlink(u)].ids.size()?getlink(u):gettl(getlink(u))):0;
	return t[u].tl;
}

// this is kinda a bonus, the link system is the basics that will be needed for problem solving
// but whatever you'll need to implement will be implemented in the same way with this dp system of sorts
// just build the links first (in theory) and then use the same strategy for whatever you need to build next
//unordered_set<int>&getcum(int u){ // gets the ids of strings that match somewhere in this node
//	if(t[u].cumids.size()||!u)return t[u].cumids;
//	for(auto id:getcum(getlink(u)))t[u].cumids.insert(id);
//	for(auto id:t[u].ids)t[u].cumids.insert(id);
//	return t[u].cumids;
//}

int getmx(int u){
	if(!u)return -1;
	return max(getmx(gettl(u)),t[u].ids.size()?*t[u].ids.rbegin():-1);
}

// returns set of ids of strings that were found
//unordered_set<int>traverse(string &t){
//	int u=0;
//	unordered_set<int>res; // union of all matches in visited nodes
//	for(auto c:t){
//		u=getnext(u,c);
//		for(auto idx:getcum(u))res.insert(idx);
//	}
//	return res;
//}

// returns set of ids of strings that were found
int traverse2(string &text){
	int u=0;
	int res=-1;
	for(auto c:text){
		u=getnext(u,c);
		res=max(res,getmx(u));
	}
	return res;
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;++i)cin>>d[i];
	for(int i=0;i<n;++i)add(i);
	while(m--){
		int tt;cin>>tt;
		if(tt==1){
			int idx,s;cin>>idx>>s;--idx;
			t[nidx[idx]].ids.erase(t[nidx[idx]].ids.find(sus[idx]));
			t[nidx[idx]].ids.insert(s);
			sus[idx]=s;
			continue;
		}
		cin>>text;
		cout<<traverse2(text)<<endl;
	}
}