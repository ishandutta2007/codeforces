#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXL 100050

using namespace std;
typedef pair<int,int> pii;

#define NUM 0
#define SB -1
#define RB -2
#define NIL -3

class Unit {
   public:
      int ch,cnt,s,e;
      Unit(int _ch,int _cnt,int _s,int _e):ch(_ch),cnt(_cnt),s(_s),e(_e) {}
      const bool operator<(const Unit &b) const { return cnt<b.cnt; }
      const bool operator>(const Unit &b) const { return cnt>b.cnt; }
};

char s[MAXL];
vector<Unit> stk;

void solve() {
   Unit opt(NUM,-1,0,-1);
   for(int i=0;s[i];i++) {
      if(s[i]=='(') {
         stk.push_back(Unit(RB,0,i,i));
      } else if(s[i]==')') {
         int a=0;
         if(stk.size()&&stk.back().ch==NUM) {
            a+=stk.back().cnt;
            stk.pop_back();
         }
         if(stk.size()&&stk.back().ch==RB) {
            Unit u(NUM,a,stk.back().s,i);
            stk.pop_back();
            while(stk.size()&&stk.back().ch==NUM) {
               u.s=stk.back().s;
               u.cnt+=stk.back().cnt;
               stk.pop_back();
            }
            stk.push_back(u);
            opt=max(opt,u);
         } else {
            stk.clear();
         }
      } else if(s[i]=='[') {
         stk.push_back(Unit(SB,0,i,i));
      } else {
         int a=1;
         if(stk.size()&&stk.back().ch==NUM) {
            a+=stk.back().cnt;
            stk.pop_back();
         }
         if(stk.size()&&stk.back().ch==SB) {
            Unit u(NUM,a,stk.back().s,i);
            stk.pop_back();
            while(stk.size()&&stk.back().ch==NUM) {
               u.s=stk.back().s;
               u.cnt+=stk.back().cnt;
               stk.pop_back();
            }
            stk.push_back(u);
            opt=max(opt,u);
         } else {
            stk.clear();
         }

      }
   }
   opt.cnt=max(opt.cnt,0);
   printf("%d\n",opt.cnt);
   for(int i=opt.s;i<=opt.e;i++) {
      printf("%c",s[i]);
   }
   puts("");
}

int main(void)
{
   scanf("%s",s);
   solve();
   return 0;
}