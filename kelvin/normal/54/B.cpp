#include <stdio.h>
#include <set>
#define MAXL 22
#define MAXN (MAXL*MAXL)

using namespace std;

class Puzzle {
	public:
		int rl,cl;
		char p[MAXL][MAXL];
		Puzzle r90() {
			int i,j;
			Puzzle b;
			b.rl=cl;
			b.cl=rl;
			for(i=0;i<rl;i++)
				for(j=0;j<cl;j++)
					b.p[j][rl-i-1]=p[i][j];
			return b;
		}
		Puzzle getmin() {
			int i;
			Puzzle b,opt;
			b=opt=*this;
			for(i=0;i<3;i++) {
				b=b.r90();
				if(b<opt) opt=b;
			}
			return opt;
		}
		const bool operator<(const Puzzle &b) const {
			int i,j;
			if(rl!=b.rl) return rl<b.rl;
			if(cl!=b.cl) return cl<b.cl;
			for(i=0;i<rl;i++)
				for(j=0;j<cl;j++)
					if(p[i][j]!=b.p[i][j]) return p[i][j]<b.p[i][j];
			return 0;
		}
};

int rn,cn;
char g[MAXL][MAXL];

int zn;
Puzzle pz[MAXN];

inline bool sub(int rl,int cl) {
	int i,j,s,t;
	set<Puzzle> st;
	zn=0;
	for(i=0;i<rn;i+=rl) {
		for(j=0;j<cn;j+=cl) {
			pz[zn].rl=rl;
			pz[zn].cl=cl;
			for(s=0;s<rl;s++)
				for(t=0;t<cl;t++)
					pz[zn].p[s][t]=g[i+s][j+t];
			pz[zn]=pz[zn].getmin();
			zn++;
		}
	}
	for(i=0;i<zn;i++) {
		if(st.find(pz[i])!=st.end()) return 0;
		st.insert(pz[i]);
	}
	return 1;
}

inline void solve() {
	int rl,cl,i,j,cnt=0;
	int opta=rn*cn+1,optr,optc;
	for(rl=1;rl<=rn;rl++) {
		if(rn%rl) continue;
		for(cl=1;cl<=cn;cl++) {
			if(cn%cl) continue;
			if(sub(rl,cl)) {
				cnt++;
				if(rl*cl<opta||rl*cl==opta&&rl<optr) {
					opta=rl*cl;
					optr=rl;
					optc=cl;
				}
			}
		}
	}
	printf("%d\n%d %d\n",cnt,optr,optc);
}

int main(void)
{
	int i;
	while(scanf("%d %d",&rn,&cn)==2) {
		for(i=0;i<rn;i++)
			scanf("%s",g[i]);
		solve();
	}
}