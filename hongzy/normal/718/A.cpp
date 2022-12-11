#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, t, cnt, d, d2;
char s[200010], s1[200010], s2[200010];

void Print() {
	if(s[0] != '0' && s[0] != '\0') printf("%s\n", s);
	else printf("%s\n", s+1);
	exit(0);
}

int main() {
	scanf("%d%d\n", &n, &t);
	gets(s+1); s[0] = '0';
	for(int i=1; i<=n; i++)
		if(s[i] == '.') {d = i; break;}
	for(int i=d+1; i<=n; i++)
		if(s[i] >= '5') {d2 = i; break;}
	if(d + 1 == d2) { // 
		if(cnt == t) Print();
		s[d-1] ++; cnt ++;
		for(int i=d-1; i>=1; i--) {
			if(s[i] > '9') s[i] = '0', s[i-1] ++;
			else break;
		}
		s[d] = '\0';
	} else {
		if(cnt < t) {
			s[d2-1] ++; cnt ++; s[d2] = '\0';
			for(int i=d2-1; i>d+1; i--) {
				if(s[i] >= '5') {
					if(cnt == t) Print();
					s[i-1] ++; s[i] = '\0'; cnt ++;
				}
			}
			if(s[d+1] >= '5') {
				if(cnt == t) Print();
				s[d-1] ++; cnt ++;
				for(int i=d-1; i>=1; i--) {
					if(s[i] > '9') s[i-1] ++, s[i] = '0';
					else break;
				}
				s[d] = '\0';
			}
		}
	}
	Print();
	return 0;
}