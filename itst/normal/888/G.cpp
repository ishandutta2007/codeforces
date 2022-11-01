#include<iostream>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<vector>
#include<set>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int MAXN = 2e5 + 3;

struct node{
	node *ch[2];
	node(){ch[0] = ch[1] = NULL;}
};

struct Trie{
	node *rt = new node;
	
	void ins(int x){
		node *cur = rt;
		for(int i = 29 ; i >= 0 ; --i){
			if(cur->ch[(bool)(x & (1 << i))] == NULL)
				cur->ch[(bool)(x & (1 << i))] = new node;
			cur = cur->ch[(bool)(x & (1 << i))];
		}
	}
	
	int query(int x){
		int ans = 0;
		node *cur = rt;
		for(int i = 29 ; i >= 0 ; --i){
			bool f = x & (1 << i);
			if(cur->ch[f] != NULL)
				cur = cur->ch[f];
			else{
				cur = cur->ch[!f];
				ans += 1 << i;
			}
		}
		return ans;
	}
};
int N;
long long sum;
vector < int > val;

node* merge(node *A , node *B){
	if(A == NULL) return B;
	if(B == NULL) return A;
	A->ch[0] = merge(A->ch[0] , B->ch[0]);
	A->ch[1] = merge(A->ch[1] , B->ch[1]);
	return A;
}

Trie merge(Trie A , Trie B){
	A.rt = merge(A.rt , B.rt);
	return A;
}

Trie solve(vector < int > val , int now){
	if(val.empty()) return Trie();
	if(now < 0){
		Trie t;
		t.ins(val[0]);
		return t;
	}
	vector < int > lft , rht;
	for(auto t : val)
		t & (1 << now) ? rht.push_back(t) : lft.push_back(t);
	Trie L = solve(lft , now - 1) , R = solve(rht , now - 1);
	if(lft.size() < rht.size()){
		swap(lft , rht);
		swap(L , R);
	}
	int minN = 2e9;
	for(auto t : rht) minN = min(minN , L.query(t));
	if(!rht.empty()) sum += minN;
	return merge(L , R);
}

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		val.push_back(read());
	sort(val.begin() , val.end());
	solve(val , 29);
	cout << sum;
	return 0;
}