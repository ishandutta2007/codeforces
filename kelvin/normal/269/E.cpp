#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 400500

using namespace std;
typedef pair<int,int> pii;

int rn,cn,vn;
int link[MAXN];
//vector<vector<int> > cycs;
vector<vector<int> > eights,others;
bool vis[MAXN];
int diag1[MAXN],diag2[MAXN];

int rans[MAXN],cans[MAXN];
bool used[MAXN];
char tmp[MAXN*2];

inline int vid(char s,int x) {
   int b;
   if(s=='L') b=0;
   else if(s=='T') b=rn;
   else if(s=='R') b=rn+cn;
   else if(s=='B') b=rn+rn+cn;
   return b+x-1;
}
inline char getstr(int v) {
   if(v<rn) return 'L';
   else if(v<rn+cn) return 'T';
   else if(v<rn+rn+cn) return 'R';
   else return 'B';
}
inline int getpos(int v) {
   if(v<rn) return v+1;
   else if(v<rn+cn) return v-rn+1;
   else if(v<rn+rn+cn) return v-rn-cn+1;
   else return v-rn-rn-cn+1;
}
inline int ctp(int v) {
   if(v<rn+cn) return v+rn+cn;
   else return v-rn-cn;
}

void dfs(int v,vector<int> &cyc) {
   vis[v]=1;
   cyc.push_back(v);
   int u=link[v];
   int z=ctp(v);
   if(!vis[u]) dfs(u,cyc);
   if(!vis[z]) dfs(z,cyc);
}

void dump(const vector<int> &cyc,char *str) {
   for(int i=0;i<cyc.size();i++)
      str[i]=getstr(cyc[i]);
   str[cyc.size()]='\0';
}
int is_eight(const vector<int> &cyc) {
   if(cyc.size()!=8) return 0;
   // "LTBLRBTR"
   // "LBTLRTBR"
   char rep[10];
   dump(cyc,rep);
   if(!strcmp(rep,"LTBLRBTR")) return 1;
   if(!strcmp(rep,"LBTLRTBR")) return 2;
   return 0;
}
void gao_eight() {
   for(int e=0;e<eights.size();e++) {
      const vector<int>& cyc=eights[e];
      int type=is_eight(cyc);
      if(type==1) { // "LTBLRBTR"
         rans[e]=getpos(cyc[0]);
         cans[e]=getpos(cyc[1]);
         rans[rn-e-1]=getpos(cyc[3]);
         cans[cn-e-1]=getpos(cyc[5]);
      } else { // "LBTLRTBR"
         rans[rn-e-1]=getpos(cyc[0]);
         cans[e]=getpos(cyc[1]);
         rans[e]=getpos(cyc[3]);
         cans[cn-e-1]=getpos(cyc[5]);
      }
      used[vid('L',e+1)]=1;
      used[vid('L',rn-e)]=1;
      used[vid('R',e+1)]=1;
      used[vid('R',rn-e)]=1;
      used[vid('T',e+1)]=1;
      used[vid('T',cn-e)]=1;
      used[vid('B',e+1)]=1;
      used[vid('B',cn-e)]=1;
   }
}

inline int gcd(int a,int b) {
   while(b) {
      int t=b;
      b=a%b;
      a=t;
   }
   return a;
}
void gen_diag() {
   vector<int> a1,a2;
   for(int i=rn-1;i>=0;i--)
      if(!used[i]) a1.push_back(i);
   for(int i=0;i<cn;i++)
      if(!used[rn+i]) a1.push_back(rn+i);
   for(int i=0;i<rn;i++)
      if(!used[rn+cn+i]) a1.push_back(rn+cn+i);
   for(int i=cn-1;i>=0;i--)
      if(!used[rn+rn+cn+i]) a1.push_back(rn+rn+cn+i);
   for(int i=0;i<rn;i++)
      if(!used[i]) a2.push_back(i);
   for(int i=0;i<cn;i++)
      if(!used[rn+rn+cn+i]) a2.push_back(rn+rn+cn+i);
   for(int i=rn-1;i>=0;i--)
      if(!used[rn+cn+i]) a2.push_back(rn+cn+i);
   for(int i=cn-1;i>=0;i--)
      if(!used[rn+i]) a2.push_back(rn+i);
   for(int i=0;i<a1.size();i++)
      diag1[a1[i]]=a1[a1.size()-i-1];
   for(int i=0;i<a2.size();i++)
      diag2[a2[i]]=a2[a2.size()-i-1];
   //for(int i=0;i<vn;i++)
   //   printf("diag1[%d] = %d\n",i,diag1[i]);
}
void dfs_diag(int v,int *diag,vector<int> &arr) {
   vis[v]=1;
   arr.push_back(v);
   int u=diag[v];
   int z=ctp(v);
   if(!vis[u]) dfs_diag(u,diag,arr);
   if(!vis[z]) dfs_diag(z,diag,arr);
}
int lex_smallest_head(char s[], int n) {
   for(int i=0;i<n;i++)
      s[i+n]=s[i];
   int i=0,j=1,k=0;
   while(j<n&&k<n) {
      if(s[i+k]==s[j+k]) k++;
      else {
         if(s[i+k]<s[j+k]) j+=k+1;
         else i+=k+1;
         k=0;
      }
      if(i==j) j++;
   }
   return i;
}
long long hashval(char *s,int len) {
   const int pr=3333331;
   long long h=0;
   for(int i=0;i<len;i++) {
      int x;
      if(s[i]=='L') x=1;
      else if(s[i]=='T') x=2;
      else if(s[i]=='R') x=3;
      else x=4;
      h=h*pr+x;
   }
   return h;
}
long long hashval(const vector<int>& arr) {
   char s[arr.size()+1];
   dump(arr,s);
   return hashval(s,arr.size());
}
bool try_diag(int *diag) {
   for(int i=0;i<vn;i++)
      vis[i]=0;
   vector<pair<int,vector<int> > > diags;
   for(int i=0;i<vn;i++) {
      vector<int> arr;
      if(vis[i]||used[i]) continue;
      dfs_diag(i,diag,arr);
      int tl=arr.size();
      dump(arr,tmp);
      int si=lex_smallest_head(tmp,tl);
      vector<int> aaa=arr;
      for(int i=0;i<tl;i++)
         arr[i]=aaa[si+i<tl?si+i:si+i-tl];
      diags.push_back(make_pair(hashval(arr),arr));
   }
   vector<pair<int,vector<int> > > origs;
   for(int o=0;o<others.size();o++) {
      vector<int> &arr=others[o];
      int tl=arr.size();
      dump(arr,tmp);
      int si=lex_smallest_head(tmp,tl);
      vector<int> aaa=arr;
      for(int i=0;i<tl;i++)
         arr[i]=aaa[si+i<tl?si+i:si+i-tl];
      origs.push_back(make_pair(hashval(arr),arr));
   }
   sort(diags.begin(),diags.end());
   sort(origs.begin(),origs.end());
   /*printf("diags: \n");
   for(int i=0;i<diags.size();i++) {
      printf("> (%d)",diags[i].first);
      for(int j=0;j<diags[i].second.size();j++)
         printf("%c%d ",getstr(diags[i].second[j]),diags[i].second[j]); puts("");
   }
   printf("origs: \n");
   for(int i=0;i<origs.size();i++) {
      printf("> (%d)",origs[i].first);
      for(int j=0;j<origs[i].second.size();j++)
         printf("%c%d ",getstr(origs[i].second[j]),origs[i].second[j]); puts("");
   }*/
   if(diags.size()!=origs.size()) return 0;
   for(int i=0;i<diags.size();i++) {
      if(diags[i].first!=origs[i].first) return 0;
      if(diags[i].second.size()!=origs[i].second.size()) return 0;
      for(int j=0;j<diags[i].second.size();j++) {
         int v1=origs[i].second[j];
         int v2=diags[i].second[j];
         if(getstr(v1)!=getstr(v2)) return 0;
         char c=getstr(v1);
         if(c=='L'||c=='R') rans[getpos(v2)-1]=getpos(v1);
         else cans[getpos(v2)-1]=getpos(v1);
      }
   }
   return 1;
}
bool gao_other() {
   gen_diag();
   /*int zr=(rn-(int)eights.size()*2);
   int zc=(cn-(int)eights.size()*2);
   int g=gcd(zr,zc);
   int sr=zr/g,sc=zc/g;
   for(int o=0;o<others.size();o++) {
   //printf("<%d> %d %d\n",(int)others[o].size(),zr,zc);
      if(others[o].size()!=2*(sr+sc)) return 0;
   }*/
   if(try_diag(diag1)||try_diag(diag2)) return 1;
   return 0;
}

bool solve() {
   vn=(rn+cn)*2;
   for(int i=0;i<vn;i++) {
      if(vis[i]) continue;
      //cycs.push_back(vector<int>());
      vector<int> cyc;
      dfs(i,cyc);
      //printf("%d\n",(int)cycs.back().size());
      if(is_eight(cyc)) eights.push_back(cyc);
      else others.push_back(cyc);
   }
   // eights
   gao_eight();
   // others
   if(!gao_other()) return 0;
   //
   for(int i=0;i<rn;i++)
      printf("%d ",rans[i]); puts("");
   for(int i=0;i<cn;i++)
      printf("%d ",cans[i]); puts("");
   return 1;
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn+cn;i++) {
      char s1[3],s2[3];
      int x1,x2;
      scanf("%s %s %d %d",s1,s2,&x1,&x2);
      int v1=vid(s1[0],x1);
      int v2=vid(s2[0],x2);
      link[v1]=v2;
      link[v2]=v1;
   }
   if(!solve()) puts("No solution");
   return 0;
}