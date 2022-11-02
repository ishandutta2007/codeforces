#include <stdio.h>
#define MAXB 1050

class Coor {
	public:
		int r,c;
		void input() { scanf("%d %d",&r,&c); } 
		const bool operator<(const Coor &b) const {
			return r<b.r||r==b.r&&c<b.c;
		}
		const bool operator==(const Coor &b) const {
			return r==b.r&&c==b.c;
		}
};

const char fr[3][20]={"Carrots","Kiwis","Grapes"};

int rn,cn,bn,qn;
Coor b[MAXB];

int main(void)
{
	int i,c,sol;
	Coor p;
	scanf("%d %d %d %d",&rn,&cn,&bn,&qn);
	for(i=0;i<bn;i++)
		b[i].input();
	while(qn--) {
		p.input();
		c=0;
		for(i=0;i<bn;i++) {
			if(b[i]==p) break;
			if(b[i]<p) c++;
		}
		if(i<bn) {
			puts("Waste");
		} else {
			sol=((p.r-1)*cn+p.c-1-c+30000)%3;
			puts(fr[sol]);
		}
	}
}