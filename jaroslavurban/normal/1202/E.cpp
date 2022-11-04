#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100; // dict max size
string d[N]; // dictionary
string txt;
int n;

struct vertex{
	unordered_map<int,int>next; // trie + automaton combined
	// cumids contains not only previous ids, but also ids ending here
	int ids=0,cumids=-1; // ids of strings of all suffixes
	int id=0,p=0,pc,l=-1,tl=-1; // id, parent, previous char, link
	vertex(int id=0,int p=0,int pc=0):id(id),p(p),pc(pc){}
};
vector<vertex>t(1); // trie

void add(int id){
	int u=0;
	for(char c:d[id]){
		if(!t[u].next.count(c)){ // no edge
			t[u].next[c]=t.size(); // new node
			t.push_back(vertex(t[u].next[c],t[u].id,c)); // create it
		}
		u=t[u].next[c]; // next node
	}
	++t[u].ids; // string ends here
}

int getnext(int u,int c);

int getlink(int u){ // gets link otherwise gets next of parents link
	if(t[u].l==-1)t[u].l=t[u].p?getnext(getlink(t[u].p),t[u].pc):0; // depth<=1 => link=0
	return t[u].l;
}

int getnext(int u,int c){ // gets next state or next state of parents link
	if(!t[u].next.count(c))t[u].next[c]=u?getnext(getlink(u),c):0; // nothing new for u==0
	return t[u].next[c];
}

// this is kinda a bonus, the link system is the basics that will be needed for problem solving
// but whatever you'll need to implement will be implemented in the same way with this dp system of sorts
// just build the links first (in theory) and then use the same strategy for whatever you need to build next
// good only with small N
int getcum(int u){ // gets the ids of strings that match somewhere in this node
	if(~t[u].cumids||!u)return t[u].cumids;
	return t[u].cumids = t[u].ids + getcum(getlink(u));
}

int cnt[N][2];

// returns set of ids of strings that were found
void traverse(string &txt,int cn){
	int u=0;
	for(int i=0;i<txt.size();++i){
		u=getnext(u,txt[i]);
		cnt[i][cn]+=getcum(u);
	}
}



main(){
	cin.tie(0);cin.sync_with_stdio(0);
	t[0].cumids=0;
	cin>>txt>>n;
	int m=txt.size();
	for(int i=0;i<n;++i)cin>>d[i];
	for(int i=0;i<n;++i)add(i);
	traverse(txt,0);
	for(int i=0;i<n;++i)reverse(d[i].begin(),d[i].end());
	t.clear();t.push_back({});
	t[0].cumids=0;
	for(int i=0;i<n;++i)add(i);
	reverse(txt.begin(),txt.end());
	traverse(txt,1);
	ll res=0;
	for(int i=0;i<m-1;++i)res+=cnt[i][0]*(ll)cnt[m-i-2][1];
	cout<<res<<endl;
}