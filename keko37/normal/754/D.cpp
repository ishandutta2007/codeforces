#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>

using namespace std;

int n, k, a, b, sol, sol2;

vector < pair <pair <int, int>, int> > v;
set < pair <pair <int, int>, int> > s;
set < pair <pair <int, int>, int> > s2;
set < pair <pair <int, int>, int> > :: iterator it;
vector <int> out;

ispis () {
	for (it=s.begin(); it!=s.end(); it++) {
		out.push_back(it->second);
	}
	sort(out.begin(), out.end());
	for (int i=0; i<out.size(); i++) {
		printf("%d ", out[i]+1);
	}
}

int main () {
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; i++) {
		scanf("%d%d", &a, &b);
		v.push_back(make_pair(make_pair(a, b), i));
	}
	sort(v.begin(), v.end());
	for (int i=0; i<n; i++) {
		int ea=v[i].first.first;
		int eb=v[i].first.second;
		int eind=v[i].second;
		s.insert(make_pair(make_pair(eb, ea), eind));
		s2.insert(make_pair(make_pair(-ea, eb), eind));
		if (i>=k) {
			it=s.begin();
			eb=it->first.first;
			ea=it->first.second;
			eind=it->second;
			s.erase(it);
			s2.erase(make_pair(make_pair(-ea, eb), eind));
		}
		if (i>=k-1) {
			int minr=s.begin()->first.first;
			int maxl=-(s2.begin()->first.first);
			sol=max(sol, minr-maxl+1);
		}
	}
	printf("%d\n", sol);
	s.clear();
	s2.clear();
	for (int i=0; i<n; i++) {
		int ea=v[i].first.first;
		int eb=v[i].first.second;
		int eind=v[i].second;
		s.insert(make_pair(make_pair(eb, ea), eind));
		s2.insert(make_pair(make_pair(-ea, eb), eind));
		if (i>=k) {
			it=s.begin();
			eb=it->first.first;
			ea=it->first.second;
			eind=it->second;
			s.erase(it);
			s2.erase(make_pair(make_pair(-ea, eb), eind));
		}
		if (i>=k-1) {
			int minr=s.begin()->first.first;
			int maxl=-(s2.begin()->first.first);
			sol2=max(sol2, minr-maxl+1);
			if (sol2==sol) {
				ispis();
				return 0;
			}
		}
	}
	return 0;
}