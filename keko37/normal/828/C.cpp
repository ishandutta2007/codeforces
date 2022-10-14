#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

const int MAXN = 100005;
const int LIM = 1000005;

int n, x, d;
string s[MAXN];
char sol[2*LIM+5];
int len[MAXN];
int k[MAXN];
vector <int> v[MAXN];
multiset < pair <int, int> > ms;
multiset < pair <int, int> > :: iterator it;
multiset < pair <int, int> > :: iterator it2;

struct event {
	int pos, tip, ind;
	event () {
	}
	event (int _pos, int _tip, int _ind) {
		pos=_pos, tip=_tip, ind=_ind;
	}
};
vector <event> pop;

bool cmp (event e1, event e2) {
	if (e1.pos==e2.pos) {
		return e1.tip<e2.tip;
	} else {
		return e1.pos<e2.pos;
	}
}

void ispis () {
	for (it2=ms.begin(); it2!=ms.end(); it2++) {
		cout << (it2->first) << " " << (it2->second) << endl;
	}
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		len[i]=s[i].size();
		scanf("%d", &k[i]);
		for (int j=0; j<k[i]; j++) {
			scanf("%d", &x);
			v[i].push_back(x);
			d=max(d, x+len[i]-1);
			pop.push_back(event(x-1, 1, i));
			pop.push_back(event(x+len[i]-1, 0, i));
		}
	}
	sort(pop.begin(), pop.end(), cmp);
	int r=0;
	for (int i=0; i<2*LIM+4; i++) {
		while (r<pop.size() && i>=pop[r].pos) {
			//cout << pop[r].pos << " " << pop[r].tip << " " << pop[r].ind << endl;
			if (pop[r].tip==1) {
				ms.insert(make_pair(pop[r].ind, pop[r].pos));
			} else {
				it=ms.lower_bound(make_pair(pop[r].ind, pop[r].pos-len[pop[r].ind]));
				//cout << "hocu " << pop[r].ind << " " <<  pop[r].pos-len[pop[r].ind] << endl;
				ms.erase(it);
			}
			//ispis();
			r++;
		}
		//cout << i << " " << r << endl;
		if (ms.empty()) {
			sol[i]='a';
			continue;
		}
		it=ms.begin();
		int ind=it->first;
		int pos=it->second;
		sol[i]=s[ind] [i-pos];
	}
	for (int i=0; i<d; i++) {
		cout << sol[i];
	}
	return 0;
}