#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define INF 9999999999
#define LINF 9999999999999999
#define SINF "%"
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define xsize(a) sizeof(a)/1024/1024
#define fr(aaaaa,bbbbb) for(aaaaa = 1;aaaaa <= bbbbb;aaaaa++)
#define frr(aaaaa,bbbbb,ccccc) for(aaaaa = ccccc;aaaaa <= bbbbb;aaaaa++)
using namespace std;

string s,t;
int len1,len2;

int l_s[28];
vector<char> need;
int none = 0;

int main(){
	ms(l_s);
	
	cin >> s; cin >> t;
	
	len1 = s.length(); len2 = t.length();
	for(int i = 0;i < len1;i++){
		if(s[i] != '?') l_s[s[i]-'a']++;
		else none++;
	}
	
	while(1){
		for(int i = 0;i < len2;i++){
			if(l_s[t[i]-'a'] > 0){
				l_s[t[i]-'a']--;
			}else if(none > 0){
				none--;
				need.pb(t[i]);
			}else{
				int pos = 0;
				for(int i = 0;i < len1;i++){
					if(s[i] == '?'){
						cout << need[pos];
						pos++;
					}else{
						cout << s[i];
					}
				}
				cout << endl;
				return 0;
			}
		}
	}
	
	return 0;
}