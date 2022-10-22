#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<string> refs;
  while (1) {
    string line;
    getline(cin, line);
    if (line == "\\begin{thebibliography}{99}") break;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '\\') {
	i += 6;
	int j = i;
	while (line[j] != '}') j++;
	refs.push_back(line.substr(i,j-i));
	i = j;
      }
    }
  }
  vector<string> bib_refs;
  map<string, string> bib;
  while (1) {
    string line;
    getline(cin, line);
    if (line == "\\end{thebibliography}") break;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '\\') {
	i += 9;
	int j = i;
	while (line[j] != '}') j++;
	bib_refs.push_back(line.substr(i,j-i));
	bib[line.substr(i,j-i)] = line;
	i = j;
      }
    }
  }
  if (refs == bib_refs) cout << "Correct" << endl;
  else {
    cout << "Incorrect" << endl;
    cout << "\\begin{thebibliography}{99}" << endl;
    for (string s : refs)
      cout << bib[s] << '\n';
    cout << "\\end{thebibliography}" << endl;
  }
}