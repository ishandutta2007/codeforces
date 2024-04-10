#include <bits/stdc++.h>
using namespace std;

vector<char> todo;
int ans;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	string str; cin >> str;
	for (char u: str)
		if (u == '(' || u == '[' || u == '{' || u == '<')
			todo.push_back(u);
		else
		{
			if (!todo.size())
			{
				cout << "Impossible" << endl;
				return 0;
			}
			if (todo.back() == '(' && u != ')') ans++;
			if (todo.back() == '[' && u != ']') ans++;
			if (todo.back() == '{' && u != '}') ans++;
			if (todo.back() == '<' && u != '>') ans++;
			todo.pop_back();
		}
	if (todo.size()) cout << "Impossible" << endl;
	else cout << ans << endl;
	return 0;
}