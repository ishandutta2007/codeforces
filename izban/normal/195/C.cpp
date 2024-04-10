#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100;

int n,cur;
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	while (cin >> s) {
		if (s=="try") 
			cur++;
		else if (s[0]=='c') {
			if (s[s.length()-1]==')') continue;
			while (1) {
				cin >> s;
				if (s[s.length()-1]==')') break;
			}
		} else {
			string err="";
			while (s[s.length()-1]!=')') {
				string s1;
				cin >> s1;
				s+=s1;
			}
			bool f=false;
			for (int i=0; i<s.length(); i++) {
				if (f && s[i]!=' ' && s[i]!=')') err+=s[i];
				if (s[i]=='(') f=true;
			}
			if (cur==0) {
				cout << "Unhandled Exception";
				return 0;
			}
			cur=0;
			while (cin >> s) {
				if (s[0]=='t') cur++;
				else if (s[0]=='c') {
					while (s[s.length()-1]!=')') {
						string s1;
						getline(cin,s1);
						//cin >> s1;
						//s+=s1;
						for (int i=0; i<s1.length(); i++)
							if (s1[i]==')') {s+=s1[i];break;}
							else s+=s1[i];
					}
					if (cur>0) {
						if (cur) cur--;
					}
					else {
						string check="";
						bool f=false;
						for (int i=0; i<s.length(); i++) {
							if (f && s[i]==',') f=false;
							if (f && s[i]!=' ') check+=s[i];
							if (s[i]=='(') f=true;
						}
						if (check==err) {
							f=false;
							check="";
							for (int i=0; i<s.length(); i++) {
								if (f && s[i]=='"') f=false;
								if (f) check+=s[i];
								if (s[i]=='"' && !f && check=="") f=true;
							}
							cout << check;
							return 0;
						} else if (cur)cur--;
					}
					if (cur<0 && 0) {
						cout << "Unhandled Exception";
						return 0;
					}
				}
			}
			if (cur!=1 || 1) {
				cout << "Unhandled Exception";
				return 0;
			}

		}
	}

	return 0;
}