#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define DEBUG(x) cout << '>' << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

using namespace std;

char in[100049];
char tmp[100049];

int main() {
	gets(in);
	int zs=0,os=0,qs=0;
	int len = strlen(in);
	REP(i,len)switch(in[i]){
		case '0':++zs;break;
		case '1':++os;break;
		case '?':++qs;break;
	}
	bool oc[2][2] = {{0}};
	int mz = zs+qs, mo=os+qs;
	char l = in[len-1];
	if (len%2==0){
		if (mz>os) oc[0][0]=true;
		if (mo>zs) oc[1][1]=true;
		if (mo>=zs&&mz>=os){
			if (l == '0' || (l=='?'&&mo-1>=zs+1)) {
				oc[1][0] = true;
			}
			if (l == '1' || (l=='?'&&mz-1>=os+1)) {
				oc[0][1] = true;
			}
		}
	} else {
		if (mz>os-1) oc[0][0]=true;
		if (mo-1>zs) oc[1][1]=true;
		if (mo-1>=zs&&mz>=os-1){
			if (l == '0' || (l=='?'&&mo-2>=zs+1)) {
				oc[1][0] = true;
			}
			if (l == '1' || (l=='?'&&mz-1>=os)) {
				oc[0][1] = true;
			}
		}
	}
	REP(i,2)REP(j,2)if(oc[i][j])printf("%d%d\n",i,j);
	return 0;
}