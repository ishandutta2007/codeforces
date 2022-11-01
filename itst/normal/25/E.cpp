#include<bits/stdc++.h>
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

string s1 , s2 , s3;
int nxt[200010];

void KMP(string s){
	for(int i = 1 ; i <= s.size() ; ++i){
		int t = nxt[i - 1];
		while(t != -1 && s[t] != s[i - 1])
			t = nxt[t];
		nxt[i] = t + 1;
	}
}

int Bord(string s1 , string s2){
	KMP(s1 + s2);
	int t = nxt[s1.size() + s2.size()];
	while(t > s1.size() || t > s2.size())
		t = nxt[t];
	return t;
}

int calc(string s1 , string s2 , string s3){
	return Bord(s2 , s1) + Bord(s3 , s2);
}

int main(){
	nxt[0] = -1;
	cin >> s1 >> s2 >> s3;
	if(s1.find(s2) != string::npos || s3.find(s2) != string::npos)
		s2 = "";
	if(s1.find(s3) != string::npos || s2.find(s3) != string::npos)
		s3 = "";
	if(s2.find(s1) != string::npos || s3.find(s1) != string::npos)
		s1 = "";
	cout << s1.size() + s2.size() + s3.size() - max(max(max(calc(s1 , s2 , s3) , calc(s1 , s3 , s2)) , max(calc(s2 , s1 , s3) , calc(s2 , s3 , s1))) , max(calc(s3 , s1 , s2) , calc(s3 , s2 , s1)));
	return 0;
}