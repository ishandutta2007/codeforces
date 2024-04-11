#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <deque>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>
int n,m;
char w[11111];

inline bool cool(char c) {
	return c =='_' || (c >= '0' && c<='9') || (c >= 'a' && c<='z') || (c >= 'A' && c<='Z');
}

int main(void) {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	scanf("%s",w);
	n = strlen(w);
	bool flag = 1;
	int st = 0,len=0,fl=0;
	
	for (int i=0;i<n;i++)
		if (cool(w[i])) {
			len++;
			fl++;
		} else {
			if (w[i] == '@') {
				if (st == 0) {
						if (len > 0 && len <= 16) {
							st = 1; len = 0; fl=0;
							continue;
						} else {
							flag = 0;
							break;
						}
				} else {
					flag = 0;
					break;
				}
			}
			
			if (w[i] == '.') {
				if (st == 1) {
					fl++;
					if (len > 0 && len <= 16) {
						len = 0; continue;
					} else {
						flag = 0;
						break;
					}
				} else {
					flag = 0;
					break;
				}
			}
			
			if (w[i] == '/') {
				if (st == 1) {
					if (len && len<16 && (fl>0 && fl<=32)) {
						st = 2; len = 0;
						continue;
					} else {
						flag = 0;
						break;
					}
				} else {
					flag = 0;
					break;
				}
			}
			
			flag = 0;
			break;
		}
	
	if (st == 0) flag = 0;
	if ((st == 2) && (len == 0 || len>16)) flag = 0;
	if ((st == 1) && (len == 0 || len>32)) flag = 0;
	
	if (flag) puts("YES");
	else puts("NO");
	
	return 0;
}