#include<bits/stdc++.h>
using namespace std;

const int T = 1 << 16 , MOD = 1e9 + 7;
int upd(int x){return x + (x >> 31 & MOD);}
vector < int > operator +(const vector < int > &A , const vector < int > &B){
	vector < int > C; C.resize(T);
	for(int i = 0 ; i < T ; ++i) C[i] = upd(A[i] + B[i] - MOD);
	return C;
}

//op=1:And  op=0:Or
vector < int > Merge(vector < int > A , vector < int > B , int op){
	for(int i = 0 ; i < 16 ; ++i)
		for(int j = 0 ; j < T ; ++j)
			if((j >> i & 1) ^ op){A[j] = upd(A[j] + A[j ^ 1 << i] - MOD); B[j] = upd(B[j] + B[j ^ 1 << i] - MOD);}
	for(int i = 0 ; i < T ; ++i) A[i] = 1ll * A[i] * B[i] % MOD;
	for(int i = 0 ; i < 16 ; ++i)
		for(int j = 0 ; j < T ; ++j) if((j >> i & 1) ^ op) A[j] = upd(A[j] - A[j ^ 1 << i]);
	return A;
}

vector < int > get(char c){
	vector < int > pot; pot.resize(T , 1);
	int id = 3 - (c - (isupper(c) ? 'A' : 'a'));
	for(int i = 0 ; i < T ; ++i)
		for(int j = 0 ; j < 16 ; ++j) pot[i] &= (j >> id & 1) ^ (bool)isupper(c) ^ (i >> j & 1);
	return pot;
}

vector < int > dp(string str){
	vector < int > Ans; Ans.resize(T);
	if(str.size() == 1)
		if(str[0] != '?') Ans = get(str[0]);
		else for(int i = 'A' ; i <= 'D' ; ++i) Ans = Ans + get(i) + get(i - 'A' + 'a');
	else{
		int sum = 1 , i; for(i = 1 ; i < str.size() && sum ; ++i) sum += (str[i] == '(') - (str[i] == ')');
		vector < int > L = dp(string(str.begin() + 1 , str.begin() + i - 1)) ,
			R = dp(string(str.begin() + i + 2 , --str.end()));
		switch(str[i]){
		case '&': Ans = Merge(L , R , 1); break;
		case '|': Ans = Merge(L , R , 0); break;
		case '?': Ans = Merge(L , R , 0) + Merge(L , R , 1); break;
		}
	}
	return Ans;
}

int main(){
	string s; cin >> s; vector < int > ans = dp(s); int P , a , b , c , d , e , need0 = 0 , need1 = 0 , sum = 0;
	for(cin >> P ; P ; --P){cin >> a >> b >> c >> d >> e; (!e ? need0 : need1) |= 1 << (a << 3 | b << 2 | c << 1 | d);}
	for(int i = 0 ; i < T ; ++i) if((~i & need0) == need0 && (i & need1) == need1) sum = upd(sum - MOD + ans[i]);
	cout << sum; return 0;
}