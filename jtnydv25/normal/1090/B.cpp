#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const string START = "\\begin{thebibliography}{99}";
const string END = "\\end{thebibliography}";

vector<string > order;
map<string, string > M;

int main() {
  string s;
  while(1) {
    getline(cin, s);
    
    if((int)s.length() == 0) continue;

    if(s == START) break;


    for(int i = 0; i < s.length(); i++){
      if(s[i] == 92){
        assert(s.substr(i+1, 5) == "cite{");
        i += 6;
        int j = 0;
        while(s[i + j] != '}') j++;
        order.push_back(s.substr(i,j));
        i += j;
      }
    }
  }

  int idx = -1;
  bool ok = true;
  string cur;  
  while(1) {
    getline(cin, s);

    if((int)s.length() == 0) continue;

    if(s == END) break;

    idx++;
    for(int i = 0; i < s.length(); i++){
      if(s[i] == 92){
        assert(s.substr(i+1, 8) == "bibitem{");
        i += 9;
        int j = 0;
        while(s[i + j] != '}') j++;
        string str = s.substr(i, j);
        if(str != order[idx]) ok = false;
        // order.push_back(s.substr(i,j));
        M[str] = s.substr(i + j + 1, s.length() - i - j - 1);
      }
    }
  }
  if(ok) {
    printf("Correct\n");
    return 0;
  }
  printf("Incorrect\n");
  cout << START << "\n";
  rep(i,0,order.size()) {
    cout << "\\bibitem{" << order[i] << "}" << M[order[i]] << "\n";
  }
  cout << END << "\n";
  return 0;
}