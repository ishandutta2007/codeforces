#include<bits/stdc++.h>
using namespace std;

string cur; int N , B , pos; vector < int > stk , now;
string set1(){string t = cur; for(int i = pos ; i < cur.size() ; ++i){t[i] = '1';} return t;}
bool qry(int p , string q){cout << p << ' ' << q << endl; string s; cin >> s; return s == "yes";}

int main(){
	cin >> N >> B; cur.resize(B , '0'); for(int i = 1 ; i <= N ; ++i) now.push_back(i);
	while(pos < cur.size()){
		for(auto t : now){
			while(stk.size() && qry(t , set1())){stk.pop_back(); if(--pos < cur.size()) cur[pos] = '0';}
			if(pos < cur.size()){++pos; cur[pos - 1] = '0' + qry(t , set1());} else ++pos;
			stk.push_back(t);
		}
		for(int i = stk.size() - 1 ; ~i ; --i)
			if(qry(stk[i] , set1())){while(stk.size() != i + 1){stk.pop_back(); if(--pos < cur.size()) cur[pos] = '0';}}
		now = stk; stk.clear();
	}
	cout << "0 " << cur;
	return 0;
}