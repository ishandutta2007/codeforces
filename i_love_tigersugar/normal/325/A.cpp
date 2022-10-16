#include<cstdio>
#include<climits>
int maxx,maxy,minx,miny;
int x1,x2,y1,y2,n;
long long s;
void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
int main(void) {
    scanf("%d",&n);
    int i;
    s=0LL;
    minx=INT_MAX;
    maxx=INT_MIN;
    miny=INT_MAX;
    maxy=INT_MIN;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&x1);
        scanf("%d",&y1);
        scanf("%d",&x2);
        scanf("%d",&y2);
        minimize(minx,x1);
        maximize(maxx,x2);
        minimize(miny,y1);
        maximize(maxy,y2);
        s=s+1LL*(x2-x1)*(y2-y1);
    }
    if (s==1LL*(maxx-minx)*(maxy-miny) && (maxx-minx==maxy-miny)) printf("YES");
    else printf("NO");
    return 0;
}