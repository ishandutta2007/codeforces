#include <stdio.h>
#include <string.h>
#define MAXL 250

#define RIGHT 2
#define BOTTOM 4

#define WHITE 0
#define BLACK 15

int put[2][2]={6,12,3,9};
char tile[16][2][3];

int rn,cn;
int bb,ww,bw;

int gr[MAXL][MAXL];
char out[MAXL][MAXL];

inline void init() {
   // ww
   strcpy(tile[0][0],"..");
   strcpy(tile[0][1],"..");
   // bb
   strcpy(tile[15][0],"##");
   strcpy(tile[15][1],"##");
   // wb
   strcpy(tile[3][0],"\\#");
   strcpy(tile[3][1],".\\");
   strcpy(tile[6][0],"./");
   strcpy(tile[6][1],"/#");
   strcpy(tile[12][0],"\\.");
   strcpy(tile[12][1],"#\\");
   strcpy(tile[9][0],"#/");
   strcpy(tile[9][1],"/.");
}

inline void next(int &r,int &c) {
   c++;
   if(c==cn) {
      r++;
      c=0;
   }
}

inline bool get(int r,int c,int side) {
   if(r<0||c<0) return 0;
   else return (gr[r][c]&side)?1:0;
}

inline void output() {
   for(int i=0;i<rn;i++) {
      for(int j=0;j<cn;j++) {
         sprintf(out[i*2]+j*2,"%s",tile[gr[i][j]][0]);
         sprintf(out[i*2+1]+j*2,"%s",tile[gr[i][j]][1]);
      }
      out[i*2][cn*2]=out[i*2+1][cn*2]='\0';
   }
   for(int i=0;i<rn*2;i++)
      puts(out[i]);
}

inline void solve() {
   int r=0,c=0;
   for(int i=0;i<ww;i++) {
      gr[r][c]=WHITE;
      next(r,c);
   }
   for(int i=cn-ww%cn;i>0;i--) {
      gr[r][c]=put[get(r-1,c,BOTTOM)][get(r,c-1,RIGHT)];
      next(r,c);
   }
   if(ww%cn) {
      gr[r][c]=put[0][(ww%cn&1)?0:1];
      next(r,c);
   }
   for(int i=ww%cn;i>1;i--) {
      gr[r][c]=put[get(r-1,c,BOTTOM)][get(r,c-1,RIGHT)];
      next(r,c);
   }
   for(int i=0;i<bb;i++) {
      gr[r][c]=BLACK;
      next(r,c);
   }
   for(int i=0;i<bw-cn;i++) {
      gr[r][c]=put[get(r-1,c,BOTTOM)][get(r,c-1,RIGHT)];
      next(r,c);
   }
   output();
}

int main(void)
{
   init();
   scanf("%d %d",&rn,&cn);
   scanf("%d %d %d",&bb,&ww,&bw);
   solve();
   return 0;
}