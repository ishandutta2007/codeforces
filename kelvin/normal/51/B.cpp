#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXL 10000

using namespace std;

#define TBL 0
#define TBR 1
#define TRL 2
#define TRR 3
#define TDL 4
#define TDR 5

const char tag[][10] = {"<table>", "</table>",
                        "<tr>", "</tr>",
                        "<td>", "</td>"};
const int len[6] = {7,8,4,5,4,5};

int sl;
char s[MAXL];

int rh;
vector<int> st;
vector<int> sol;

int token() {
   for(int i=0;i<6;i++) {
      if(!strncmp(s+rh,tag[i],len[i])) {
         rh+=len[i];
         return i;
      }
   }
   return -1;
}

inline void solve() {
   rh=0;
   while(rh<sl) {
      int tk=token();
      if(tk==TBL) st.push_back(0);
      if(tk==TBR) {
         sol.push_back(st.back());
         st.pop_back();
      }
      if(tk==TDL) st.back()++;
   }
   sort(sol.begin(),sol.end());
   for(int i=0;i<sol.size();i++)
      printf("%d ",sol[i]); puts("");
}

int main(void)
{
   sl=0;
   while(gets(s+sl))
      sl+=strlen(s+sl);
   solve();
   return 0;
}