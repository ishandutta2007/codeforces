#include "bits/stdc++.h"

using namespace std;

int p[10];

int main() {
	p[0]=0,p[1]=1,p[2]=5,p[3]=-1,p[4]=-1,p[5]=2,p[6]=-1,p[7]=-1,p[8]=8,p[9]=-1;
	int t;cin >> t;
	while(t--) {
		int h, m;cin >> h >> m;
		string s;cin >> s;
		int sd[4];
		sd[0] = (int) (s[0]-'0');
		sd[1] = (int) (s[1]-'0');
		sd[2] = (int) (s[3]-'0');
		sd[3] = (int) (s[4]-'0');
		
		int i = (sd[0]*10+sd[1])*m + sd[2]*10+sd[3];

		int ans = -1;
		for(;i < h*m;i++) {
			int mm = i%m;
			int hh = (i-mm)/m;
			sd[0] = hh/10;
			sd[1] = hh%10;
			sd[2] = mm/10;
			sd[3] = mm%10;
			
			if(p[sd[0]] < 0) continue;
			if(p[sd[2]] < 0) continue;
			if(p[sd[1]] < 0 || p[sd[1]]*10+p[sd[0]] >= m) continue;
			if(p[sd[3]] < 0 || p[sd[3]]*10+p[sd[2]] >= h) continue;

			ans = i;
			break;
		}
		if(ans >= 0) {
			cout << (ans/m)/10 << (ans/m)%10 << ":" << (ans%m)/10 << (ans%m)%10 << endl;
			continue;
		}
		for(i = 0;i < (sd[0]*10+sd[1])*m + sd[2]*10+sd[3];i++) {
			int mm = i%m;
			int hh = (i-mm)/m;
			sd[0] = hh/10;
			sd[1] = hh%10;
			sd[2] = mm/10;
			sd[3] = mm%10;
			
			if(p[sd[0]] < 0) continue;
			if(p[sd[2]] < 0) continue;
			if(p[sd[1]] < 0 || p[sd[1]]*10+p[sd[0]] >= m) continue;
			if(p[sd[3]] < 0 || p[sd[3]]*10+p[sd[2]] >= h) continue;

			ans = i;
			break;
		}
		if(ans >= 0) {
			cout << (ans/m)/10 << (ans/m)%10 << ":" << (ans%m)/10 << (ans%m)%10 << endl;
			continue;
		}
	}
	return 0;
}