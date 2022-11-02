#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#define MAXN 205

using namespace std;

#define FIX 0
#define HBOX 1
#define VBOX 2

inline long long max(long long a,long long b) { return a>b?a:b; }

class Box {
   public:
      string name;
      int type,border,spacing;
      vector<Box*> con;
      bool hcalc,wcalc;
      long long w,h;
      Box() { hcalc=wcalc=0; }
      Box(string ni,int t):name(ni),type(t) { con.clear(); hcalc=wcalc=0; border=spacing=0; }
      Box(string ni,int t,long long wi,long long hi):
         name(ni),type(t),w(wi),h(hi) { con.clear(); hcalc=wcalc=0; border=spacing=0; }
      long long getw() {
         int i;
         if(!wcalc) {
            wcalc=1;
            if(type==FIX) {
            } else if(type==HBOX) {
               if(con.size()==0) w=0;
               else {
                  w=border*2+spacing*(con.size()-1);
                  for(i=0;i<con.size();i++)
                     w+=con[i]->getw();
//                  cout << name << " "<<w << endl;
               }
            } else if(type==VBOX) {
               if(con.size()==0) w=0;
               else {
                  w=0;
                  for(i=0;i<con.size();i++)
                     w=max(w,con[i]->getw());
                  w+=border*2;
               }
            }
         }
         return w;
      }
      long long geth() {
         int i;
         if(!hcalc) {
            hcalc=1;
            if(type==FIX) {
            } else if(type==VBOX) {
               if(con.size()==0) h=0;
               else {
                  h=border*2+spacing*(con.size()-1);
                  for(i=0;i<con.size();i++)
                     h+=con[i]->geth();
               }
            } else if(type==HBOX) {
               if(con.size()==0) h=0;
               else {
                  h=0;
                  for(i=0;i<con.size();i++)
                     h=max(h,con[i]->geth());
                  h+=border*2;
               }
            }
         }
         return h;
      }
      const bool operator<(const Box &b) const {
         return name<b.name;
      }
};

map<string,int> mp;

int bn;
Box box[MAXN];

int main(void)
{
   int qn,qi,i,j,w,h,v,u;
   char cc[200],zz[200];
   string cmd,a,b,c;
   scanf("%d",&qn);
   gets(cc);
   bn=0;
   mp.clear();
   for(qi=0;qi<qn;qi++) {
      gets(cc);
      cmd=cc;
      if(cmd.substr(0,4)=="VBox") {
         a=cmd.substr(5);
         mp[a]=bn;
         box[bn++]=Box(a,VBOX);
      } else if(cmd.substr(0,4)=="HBox") {
         a=cmd.substr(5);
         mp[a]=bn;
         box[bn++]=Box(a,HBOX);
      } else if(cmd.substr(0,6)=="Widget") {
         i=7;
         for(j=i+1;cmd[j]!='(';j++);
         a=cmd.substr(i,j-i);
         mp[a]=bn;
         sscanf(cmd.substr(j).c_str(),"(%d,%d)",&w,&h);
         box[bn++]=Box(a,FIX,w,h);
      } else {
         for(i=0;cmd[i]!='.';i++);
         a=cmd.substr(0,i);
         v=mp[a];
         i++;
         for(j=i;cmd[j]!='(';j++);
         b=cmd.substr(i,j-i);
         j++;
         c=cmd.substr(j,cmd.length()-j-1);
         if(b=="pack") {
//            cout << c;
            u=mp[c];
            box[v].con.push_back(box+u);
         } else if(b=="set_border") {
            sscanf(c.c_str(),"%d",&w);
            box[v].border=w;
         } else if(b=="set_spacing") {
            sscanf(c.c_str(),"%d",&w);
            box[v].spacing=w;
         }
      }
   }
   for(i=0;i<bn;i++) {
      box[i].getw();
      box[i].geth();
   }
   std::sort(box,box+bn);
   for(i=0;i<bn;i++) {
      cout << box[i].name << " " << box[i].getw() << " " << box[i].geth() << endl;
//      cout << box[i].spacing << " " << box[i].border << endl;
   }
   return 0;
}