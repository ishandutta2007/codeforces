#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

struct sn {
	int a,b,c;
};

int n,k,p,x;
map<int,int> m;
int a[200000],b[200000];
vector <sn> ans;
multiset <pair<int,int>> s;

int f[5];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n; 
	for (int i=0; i<n; i++) {
		cin >> x;
		m[x]++;
	}
	ans.reserve(n);
	int j=1;
	for (map<int,int>::iterator it=m.begin(); it!=m.end(); it++) {
		s.insert(make_pair((*it).second,(*it).first));
		j++;
	}
	while (s.size()>=3) {
		multiset<pair<int,int>>::iterator it1=s.end(); it1--;
		multiset<pair<int,int>>::iterator it2=s.end(); it2--; it2--;
		multiset<pair<int,int>>::iterator it3=s.end(); it3--; it3--; it3--;
		if (it1->first >0 && it2->first> 0 && it3->first >0) {
			sn o;
			o.a=it1->second;
			o.b=it2->second;
			o.c=it3->second;
			pair <int,int> pp;
			pp=*it1; s.erase(pp); pp.first--; s.insert(pp);
			pp=*it2; s.erase(pp); pp.first--; s.insert(pp);
			pp=*it3; s.erase(pp); pp.first--; s.insert(pp);
			ans.push_back(o);
		} else break;
	}
	/*while (m.size()>=3) {
		map<int,int> :: iterator it1=m.end(); it1--;
		map<int,int> :: iterator it2=m.end(); it2--; it2--;
		map<int,int> :: iterator it3=m.end(); it3--; it3--; it3--;
		if (it1->second>0 && it2->second>0 && it3->second>0) {
			sn o;
			o.a=it1->first;
			o.b=it2->first;
			o.c=it3->first;
			(*it1).second--;
			(*it2).second--;
			(*it3).second--;
			ans.push_back(o);
		} else break;
	}*/
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++) {
		f[0]=ans[i].a; f[1]=ans[i].b; f[2]=ans[i].c;
		sort(f,f+3);
		
		cout << f[2] <<' '<< f[1] << ' ' << f[0] << endl;
	}
	return 0;
}