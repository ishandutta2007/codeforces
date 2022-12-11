#include <bits/stdc++.h>
using namespace std;

typedef pair <int,string> pis;

const int MAXM=10005;

vector <pis> a[MAXM];

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string nme;
	for (int no,score;n--;)
	{
		cin >> nme >> no >> score;
		a[no].push_back(make_pair(score,nme));
	}
	for (int i=1;i<=m;i++)
	{
		sort(a[i].begin(),a[i].end(),greater<pis>());
		if (a[i].size()>2&&a[i][2].first==a[i][1].first) cout << '?' << endl;
		else cout << a[i][0].second << ' ' << a[i][1].second << endl;
	}
	return 0;
}