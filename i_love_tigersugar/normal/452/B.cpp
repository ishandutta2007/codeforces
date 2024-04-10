#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
#define SQR(x) ((x)*(x))
using namespace std;
typedef pair<int,int> ii;
inline double dis(const ii &a,const ii &b) {
    return (sqrt(SQR(a.fi-b.fi)+SQR(a.se-b.se)));
}
vector<ii> v;
int main(void) {
    int m,n;
    scanf("%d%d",&m,&n);
    if (m==0) {
        printf("0 %d\n0 %d\n0 %d\n0 %d",1,n,0,n-1);
        return 0;
    }
    if (n==0) {
        printf("%d 0\n%d 0\n%d 0\n%d 0",1,m,0,m-1);
        return 0;
    }
    REP(i,m+1) REP(j,n+1) {
        if (i==0 && j==0) continue;
        if (i==m && j==n) continue;
        if (i==0 || i==m || j==0 || j==n) v.push_back(ii(i,j));
    }
    ii s=ii(0,0);
    ii t=ii(m,n);
    ii a,b,c,d;
    double res=-1.0;
    REP(i,v.size()) REP(j,v.size()) if (i!=j) {
        double tmp=dis(v[i],s)+dis(s,t)+dis(t,v[j]);
        if (res<tmp) {
            res=tmp;
            a=v[i];b=s;c=t;d=v[j];
        }
        tmp=dis(s,v[i])+dis(v[i],t)+dis(t,v[j]);
        if (res<tmp) {
            res=tmp;
            a=s;b=v[i];c=t;d=v[j];
        }
        tmp=dis(s,t)+dis(t,v[i])+dis(v[i],v[j]);
        if (res<tmp) {
            res=tmp;
            a=s;b=t;c=v[i];d=v[j];
        }
    }
    printf("%d %d\n%d %d\n%d %d\n%d %d\n",a.fi,a.se,b.fi,b.se,c.fi,c.se,d.fi,d.se);
    return 0;
}