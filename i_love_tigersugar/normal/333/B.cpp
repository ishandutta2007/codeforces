#include<cstdio>
#include<cstring>
#define MAX   1010
int fr[MAX];
int fc[MAX];
int m,n;
int add[]={2,4,6,7};
struct cell {
    int x,y;
    cell(){}
    cell(const int &_x,const int &_y) {
        x=_x;y=_y;
    }
};
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    int i,x,y;
    memset(fr,true,sizeof fr);
    memset(fc,true,sizeof fc);
    for (i=1;i<=m;i=i+1) {
        scanf("%d",&x);
        scanf("%d",&y);     
        fr[x]=false;
        fc[y]=false;
    }
}
bool freecell(const cell &a) {
    if (a.x==1 || a.x==n) return (fc[a.y]);
    if (a.y==1 || a.y==n) return (fr[a.x]);
    return (false);
}
int count(const int &i) {
    cell can[13];
    int j,k;    
    int t1,t2;
    //printf("Count %d\n",i);
    can[0]=cell(i,1);
    can[1]=cell(1,i);
    can[2]=cell(1,n-i+1);
    can[3]=cell(i,n);
    can[4]=cell(n-i+1,n);
    can[5]=cell(n,n-i+1);
    can[6]=cell(n,i);
    can[7]=cell(n-i+1,1);
    //printf("Free:\n");
    //for (j=0;j<8;j=j+1) printf("Cell %d is %d\n",j,freecell(can[j]));
    t1=freecell(can[0])+freecell(can[2])+freecell(can[4])+freecell(can[6]);
    t2=freecell(can[1])+freecell(can[3])+freecell(can[5])+freecell(can[7]);
    //printf("Result: %d\n",res);
    if (t1>t2) return (t1); else return (t2);
}
void process(void) {
    if (n<3) {
        printf("0");
        return;
    }
    int res=0;
    int i;
    for (i=2;i<=n/2;i=i+1) res+=count(i);
    if (n%2==1)
        if (fr[n/2+1] || fc[n/2+1]) res++;
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}