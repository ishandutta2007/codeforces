#include <bits/stdc++.h>
#define DMAX 500009
#define y1 sadgfsa
#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) //do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok //cerr<<"OK!\n"


using namespace std;

std::vector<pair<int, int> > v[2*DMAX];
std::vector<pair<int, int> > v2[2*DMAX];
std::vector<pair<int, int> > v3[2*DMAX];
std::vector<pair<int, int> > v4[2*DMAX];

std::map<int, int> m;
int n;
int x1[DMAX], x2[DMAX], y2[DMAX], y1[DMAX];
char col[DMAX];

void Add(int k, set<int> *s, int X1)
{
	int l, r;
	pair<int, int > pp ={y1[k], -1};
	l = lower_bound(v[X1].begin(), v[X1].end(), pp) - v[X1].begin();
	pp = {y2[k], -1};
	r = lower_bound(v[X1].begin(), v[X1].end(), pp) - v[X1].begin();

	for(int i=l;i<r;i++)
	{
		s->insert(v[X1][i].second);
		dbg_ok;
	}

	pp = {y1[k], 100000000};
	l = lower_bound(v2[X1].begin(), v2[X1].end(), pp) - v2[X1].begin();
	pp = {y2[k]+1, -1};
	r = lower_bound(v2[X1].begin(), v2[X1].end(), pp) - v2[X1].begin();

	for(int i=l;i<r;i++)
		s->insert(v2[X1][i].second);
}

void Add2(int k, set<int> *s, int X1)
{
	int l, r;
	pair<int, int > pp ={y1[k], -1};
	l = lower_bound(v3[X1].begin(), v3[X1].end(), pp) - v3[X1].begin();
	pp = {y2[k], -1};
	r = lower_bound(v3[X1].begin(), v3[X1].end(), pp) - v3[X1].begin();

	for(int i=l;i<r;i++)
	{
		s->insert(v3[X1][i].second);
		dbg_ok;
	}

	pp = {y1[k], 100000000};
	l = lower_bound(v4[X1].begin(), v4[X1].end(), pp) - v4[X1].begin();
	pp = {y2[k]+1, -1};
	r = lower_bound(v4[X1].begin(), v4[X1].end(), pp) - v4[X1].begin();

	for(int i=l;i<r;i++)
		s->insert(v4[X1][i].second);
}

void res(int k)
{
	set<int> s;
	int us[5];
	memset(us, 0, sizeof(us));
	int l, r;

	int X1 = m[x1[k]];
	int X2 = m[x2[k]];
	int Y1 = m[y1[k]];
	int Y2 = m[y2[k]];
	//x1[k];
	Add(k, &s, X1);

	//x2[k];
	Add(k, &s, X2);

	//part 2
	Add2(k, &s, Y1);

	//x2[k];
	Add2(k, &s, Y2);

	// end of story!!
	//dbg(k);
	for(auto i:s)
		if(i!=k)
			us[col[i]]++;

	for(int i=1;i<=4;i++)
		if(us[i] == 0)
		{
			col[k] = i;
			return;
		}
	cout << "B;eah";
	exit(-1);
}


int main()
{
	cin >> n;

	cout << "YES\n";

	for(int i=1;i<=n;i++)
	{
		col[i] = 1;
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

		cout << (abs(x2[i]%2))*2 + abs(y2[i]%2) +1 << '\n'; 
	}
	return 0;

}