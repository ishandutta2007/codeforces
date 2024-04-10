#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
int a,b,c,w,x;
int cycp,cycs,cyct,prev;
int vst[MAX];
vector<ii> his;
void init(void) {
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&w);
    scanf("%d",&x);
    scanf("%d",&c);
    c-=a;
    if (c<=0) {
        printf("0");
        exit(0);
    }
    memset(vst,-1,sizeof vst);
}
void findcyc(void) {
    int cur=b;
    int pnt=0;
    vst[b]=0;
    his.push_back(ii(b,0));
    while (true) {
        cur-=x;
        if (cur>=0) pnt++;
        if (cur<0) cur+=w; else c--;
        if (c<=0) {
            printf("%d",his.size());
            exit(0);
        }
        his.push_back(ii(cur,pnt));
        if (vst[cur]<0) vst[cur]=his.size()-1;
        else {
            cycp=pnt-his[vst[cur]].se;
            cycs=cur;
            cyct=his.size()-vst[cur]-1;
            prev=his.size()-1;          
            return;
        }
    }
}
void calculate(void) {
    long long ans;
    if (c%cycp!=0) {
        ans=prev+1LL*(c/cycp)*cyct;
        c=c%cycp;
    }
    else {
        ans=prev;
        if (c>cycp) {
            ans+=1LL*(c/cycp-1)*cyct;
            c=cycp;
        }
    }
    int cur=cycs;
    while (c>0) {
        cur-=x;
        if (cur<0) cur+=w; else c--;
        ans++;      
    }
    printf("%I64d",ans);
}
int main(void) {
    init();
    findcyc();
    calculate();
    return 0;
}