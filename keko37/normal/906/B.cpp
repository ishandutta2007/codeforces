#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 100005;

int n, m, swp, a, b, naso;
vector <int> v[MAXN], sol[MAXN];
int l[30] [30], p[30] [30], bio[30], sus[30] [30];

int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};

bool ok (int x, int y) {
	return x>=0 && x<a && y>=0 && y<b;
}

pair <int, int> nxt (int x, int y) {
	if (y==b-1) return make_pair(x+1, 0); return make_pair(x, y+1);
}

void brut (int x, int y) {
	if (naso) return;
	if (x==a) {
		naso=1;
		return;
	}
	for (int i=1; i<=a*b; i++) {
		if (bio[i]) continue;
		bool moze=1;
		for (int j=0; j<4; j++) {
			int nx=x+dx[j];
			int ny=y+dy[j];
			if (ok(nx, ny) && sus[i] [p[nx] [ny]]) moze=0;
		}
		if (!moze) continue;
		bio[i]=1; p[x] [y]=i;
		brut(nxt(x, y).first, nxt(x, y).second);
		if (naso) return;
		bio[i]=0; p[x] [y]=0;
	}
}

void gen (int aa, int bb) {
	a=aa; b=bb; naso=0;
	memset(sus, 0, sizeof sus);
	memset(p, 0, sizeof p);
	memset(bio, 0, sizeof bio);
	int cnt=0;
	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			cnt++;
			l[i] [j]=cnt;
		}
	}
	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			for (int k=0; k<4; k++) {
				int nx=i+dx[k];
				int ny=j+dy[k];
				if (!ok(nx, ny)) continue;
				sus[l[i] [j]] [l[nx] [ny]]=1;
			}
		}
	}
	brut(0, 0);
}

void rjesi () {
	gen(2, 4);
	int ofsx=n%2, ofsy=m%4;
	for (int i=0; i+2+ofsx<=n; i+=2) {
		for (int j=0; j+4+ofsy<=m; j+=4) {
			if (ofsx>0 && i+2+ofsx==n || ofsy>0 && j+4+ofsy==m) continue;
			vector <int> t;
			for (int k=0; k<2; k++) {
				for (int h=0; h<4; h++) {
					t.push_back(v[i+k] [j+h]);
				}
			}
			for (int k=0; k<2; k++) {
				for (int h=0; h<4; h++) {
					sol[i+k] [j+h]=t[p[k] [h]-1];
				}
			}
		}
	}
	if (ofsy) {
		gen(2, 4+ofsy);
		for (int i=0; i+2+ofsx<=n; i+=2) {
			if (ofsx>0 && i+2+ofsx==n) continue;
			vector <int> t;
			for (int k=0; k<2; k++) {
				for (int h=0; h<4+ofsy; h++) {
					t.push_back(v[i+k] [m-4-ofsy+h]);
				}
			}
			for (int k=0; k<2; k++) {
				for (int h=0; h<4+ofsy; h++) {
					sol[i+k] [m-4-ofsy+h]=t[p[k] [h]-1];
				}
			}
		}
	}
	if (ofsx) {
		gen(3, 4);
		for (int j=0; j+4+ofsy<=m; j+=4) {
			if (ofsy>0 && j+4+ofsy==m) continue;
			vector <int> t;
			for (int k=0; k<3; k++) {
				for (int h=0; h<4; h++) {
					t.push_back(v[n-3+k] [j+h]);
				}
			}
			for (int k=0; k<3; k++) {
				for (int h=0; h<4; h++) {
					sol[n-3+k] [j+h]=t[p[k] [h]-1];
				}
			}
		}
	}
	if (ofsx && ofsy) {
		gen(3, 4+ofsy);
		vector <int> t;
		for (int k=0; k<3; k++) {
			for (int h=0; h<4+ofsy; h++) {
				t.push_back(v[n-3+k] [m-4-ofsy+h]);
			}
		}
		for (int k=0; k<3; k++) {
			for (int h=0; h<4+ofsy; h++) {
				sol[n-3+k] [m-4-ofsy+h]=t[p[k] [h]-1];
			}
		}
	}
}

void ispis () {
	cout << "YES" << endl;
	if (swp) {
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				printf("%d ", sol[j] [i]);
			}
			printf("\n");
		}
	} else {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				printf("%d ", sol[i] [j]);
			}
			printf("\n");
		}
	}
}

int main () {
	cin >> n >> m;
	if (n>m) {
		swap(n, m);
		swp=1;
	}
	if (n==1 && m==1) {
		cout << "YES" << endl << 1;
		return 0;
	} else if ((n==1 && m<=3) || (n==2 && m<=3)) {
		cout << "NO";
		return 0;
	} else if (n==1) {
		for (int i=1; i<=m; i++) {
			if (i%2==0) sol[0].push_back(i);
		}
		for (int i=1; i<=m; i++) {
			if (i%2==1) sol[0].push_back(i);
		}
		ispis();
		return 0;
	} else if (n==3 && m==3) {
		gen(3, 3);
		cout << "YES" << endl;
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				cout << p[i] [j] << " ";
			}
			cout << endl;
		}
		return 0;
	}
	int br=0;
	if (swp) {
		for (int i=0; i<m; i++) {
			for (int j=n-1; j>=0; j--) {
				br++;
				v[j].push_back(br);
			}
		}
	} else {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				br++;
				v[i].push_back(br);
			}
		}
	}
	for (int i=0; i<n; i++) {
		sol[i]=v[i];
	}
	rjesi();
	ispis();
	return 0;
}