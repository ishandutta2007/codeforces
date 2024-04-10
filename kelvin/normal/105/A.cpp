#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const double eps=1e-9;

int n,m;
double k;

typedef pair<string,int> psi;
vector<psi> skill;
set<string> learnt;

int main(void)
{
   int i,val;
   string s;
   cin >> n >> m >> k;
   skill.clear();
   learnt.clear();
   for(i=0;i<n;i++) {
      cin >> s >> val;
      val=int(val*k+eps);
      if(val<100) continue;
      skill.push_back(make_pair(s,val));
      learnt.insert(s);
   }
   for(i=0;i<m;i++) {
      cin >> s;
      if(learnt.find(s)!=learnt.end()) continue;
      skill.push_back(make_pair(s,0));
   }
   sort(skill.begin(),skill.end());
   cout << skill.size() << endl;
   for(i=0;i<skill.size();i++)
      cout << skill[i].first << " " << skill[i].second << endl;
   return 0;
}