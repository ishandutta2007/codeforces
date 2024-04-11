#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;
typedef long long li;
typedef pair<int, int> pi;
#define FILENAME "arrays"

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
void solve();
int main(){


#ifdef room210
	freopen("in.txt","r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
#else
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}

#define int li

struct segment{
	int l, r, id;
	segment(int l, int r, int id):l(l),r(r),id(id){}
};

int n;
int hl, hr;
vector <segment> segs[2];
int score[200];

int W = 100000;
int h = 100;

void solve(){
	cin>>hl>>hr>>n;
	for (int i = 0; i < n; ++i){
		int v;
		cin>>v;
		score[i] = v;
		string s;
		cin>>s;
		int q, w;
		cin>>q>>w;
		if (s[0] == 'F')
			segs[0].push_back(segment(q, w, i));
		else
			segs[1].push_back(segment(q, w, i));
	}
	
	int border = 0;
	int last = hr;

	int ans = 0;

	for (int w = 0; w <= 100; ++w){

		set <int> Ids;

		bool f = true;

		int cnt = 1;

		for (int y = 0; y > -w * h; y -= h){
			cnt ^= 1;
			if (last == hl)
				break;
			int x = (y - last) * 0 + (hl - y) * W;
			//cout<<"0 "<<hl<<' '<<W<<' '<<last<<' '<<x/(last - hl)<<' '<<y<<endl;
			bool who = false;
			for (int i = 0; i < segs[cnt].size(); ++i){
				if ( (hl - last) * segs[cnt][i].l <= x && x <= (hl - last) * segs[cnt][i].r ){
					if (Ids.find(segs[cnt][i].id) != Ids.end()){
						f = false;
						break;
					}
					Ids.insert(segs[cnt][i].id);
					who = true;
				}
			}
			if (!who){
				f = false;
				break;
			}
			if (!f)
				break;
		}

		if (!f){
			last = 2 * border - last;
			border -= h;
			continue;
		}

		int curans = 0;
		for (set<int>::iterator it = Ids.begin(); it != Ids.end(); ++it){
			curans += score[*it];
		}

		ans = max(ans, curans);

		last = 2 * border - last;
		border -= h;
	}

	border = h;
	last = hr;

	for (int w = 0; w <= 100; ++w){

		set <int> Ids;

		bool f = true;

		int cnt = 0;

		for (int y = h; y <= w * h; y += h){
			cnt ^= 1;
			int x = (last - y) * 0 + (y - hl) * W;
			if (last == hl)
				break;
			//cout<<"0 "<<hl<<' '<<W<<' '<<last<<' '<<x/(last - hl)<<' '<<y<<endl;
			bool who = false;
			for (int i = 0; i < segs[cnt].size(); ++i){
				if ( (last - hl) * segs[cnt][i].l <= x && x <= (last - hl) * segs[cnt][i].r ){
					if (Ids.find(segs[cnt][i].id) != Ids.end()){
						f = false;
						break;
					}
					Ids.insert(segs[cnt][i].id);
					who = true;
				}
			}
			if (!who){
				f = false;
				break;
			}
			if (!f)
				break;
		}

		if (!f){
			last = 2 * border - last;
			border += h;
			continue;
		}

		int curans = 0;
		for (set<int>::iterator it = Ids.begin(); it != Ids.end(); ++it){
			curans += score[*it];
		}

		ans = max(ans, curans);

		last = 2 * border - last;
		border += h;

	}

	cout<<ans;

}