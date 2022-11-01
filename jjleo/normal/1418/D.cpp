#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
multiset<int> q;
set<int> st;
int x, y;

void add(int x){
	set<int>::iterator it = st.lower_bound(x);
	if(it != st.end() && it != st.begin()){
		//printf("%d %d--\n", (*it), (*prev(it)));
		q.erase(q.find((*it) - (*prev(it))));
	}
	if(it != st.end()){
		q.insert((*it) - x);
	}
	if(it != st.begin()){
		--it;
		q.insert(x - (*it));
	}
	st.insert(x);
}

void del(int x){
	st.erase(x);
	set<int>::iterator it = st.lower_bound(x);
	if(it != st.end() && it != st.begin()){
		q.insert((*it) - (*prev(it)));
	}
	if(it != st.end()){
		q.erase(q.find((*it) - x));
	}
	if(it != st.begin()){
		--it;
		q.erase(q.find(x - (*it)));
	}
}

int main(){
	scanf("%d%d", &n, &m);
	while(n--){
		scanf("%d", &x);
		add(x);
	}
	if(st.size() <= 2) puts("0");
	else printf("%d\n", (*st.rbegin()) - (*st.begin()) - (*q.rbegin()));
	while(m--){
		//for(multiset<int>::iterator it = q.begin();it != q.end();++it) printf("%d ", *it);puts("--");
		scanf("%d%d", &x, &y);
		x ? add(y) : del(y);
		if(st.size() <= 2) puts("0");
		else printf("%d\n", (*st.rbegin()) - (*st.begin()) - (*q.rbegin()));
	} 
}