#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector < vector < string > > g;
int n, k;
map < string, int > mt;
vector < char > used;

ifstream cin("input.txt");
ofstream cout("output.txt");

void f (int y, string s, int pos, int left, string res)
{
    if (left == 0) {if (mt.count(res) == 0) mt[res] = -1; g[y].push_back(res); return;}
    int i;
    for (i = pos; i + left <= s.size(); i++)
        f(y, s, i+1, left-1, res+s[i]);
}

bool try_kuhn (int v) {
	if (used[v]) return false;
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); i++) {
		string to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main()
{
    cin >> n;
    int i, j;
    g.resize(n);

    for (i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (j = 1; j < 5; j++)
            if (j <= s.size()) f(i, s, 0, j, "");
    }

    /*for (i = 0; i < n; i++)
        for (j = 0; j < g[i].size(); j++)
        cout << g[i][j] << "\n";*/

    k = mt.size();

	for (int v = 0; v < n; v++)
    {
		used.assign (n, false);
		try_kuhn (v);
	}

    int ans = n;
	for (map < string, int >::iterator it = mt.begin(); it != mt.end(); it++)
		if (it -> second != -1)
			ans--;

    if (ans != 0) {cout << "-1"; return 0;}
    string otv[230];

    for (map < string, int >::iterator it = mt.begin(); it != mt.end(); it++)
        if (it -> second != -1) otv[it -> second] = it -> first;

    for (i = 0; i < n; i++)
        cout << otv[i] << "\n";

}