#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
bool check(pair <int, char> r, pair<int, char> t){
	if(r.F == t.F && r.S == t.S){
		return 1;
	}
	return 0;
}

int n, k, m, o, p;
vector < pair<pair< int, char >, int > > v;
vector < pair< int, int > > a;
vector < pair< int, int > > b;

string s[100100], r;

char l;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		r = s[i];
		l = 'a';
		k = 0;
		for(int j = 0; j < r.size(); j++){
			if(r[j] == 'a' || r[j] == 'e' || r[j] == 'i' || r[j] == 'o' || r[j] == 'u'){
				k++;
				l = r[j];
			}
		}
		v.push_back({{k, l}, i});
	}
	sort(v.begin(), v.end());
	
	m = -1;
	int i;
	for(i = 0; i < n - 1; i++){
		//cout << v[i].F.F << ' ' << v[i].F.S << "  " << s[v[i].S] << "______";
		if(check(v[i].F, v[i + 1].F)){
			if(v[i].F.F == 0){
				a.push_back({v[i].S, v[i + 1].S});
				//cout << v[i + 1].F.F << ' ' << v[i+ 1].F.S << "  " << s[v[i + 1].S];
				i++;
				//cout << " #1";
			}
			else{
				b.push_back({v[i].S, v[i + 1].S});
				//cout << v[i + 1].F.F << ' ' << v[i+ 1].F.S << "  " << s[v[i + 1].S];
				i++;
				//cout << " #2";
			}
		}
		else{
			if(m != -1){
				if(v[i].F.F == v[m].F.F){
					a.push_back({v[i].S, v[m].S});
					//cout << v[m].F.F << ' ' << v[m].F.S << "  " << s[v[m].S];
					m = -1;
					//cout << " #3";
				}
				else{
					m = i;
				}
			}
			else{
				m = i;
			}
		}
		//cout << endl;
	}
	if(m!= -1 && i == n - 1 && v[i].F.F == v[m].F.F){
		a.push_back({v[i].S, v[m].S});
	}
	while(a.size() < b.size()){
		a.push_back(b.back());
		b.pop_back();
	}
	cout << min(a.size(), b.size()) << endl;
	for(int i = 0; i < min(a.size(), b.size()); i++){
		o = a[i].F;
		p = b[i].F;
		cout << s[o] << ' ' << s[p] << endl;
		o = a[i].S;
		p = b[i].S;
		cout << s[o] << ' ' << s[p] << endl;
	}
	return 0;
}