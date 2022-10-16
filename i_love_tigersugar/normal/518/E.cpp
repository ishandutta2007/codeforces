#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int INF=(int)2e9+7;
const char noAns[]="Incorrect sequence";
int n,m;
int a[MAX];
int readInt(void) {
    char s[22];
    scanf("%s",s);
    if (s[0]=='?') return (INF);
    int val=0;
    if (s[0]=='-') {
        FOR(i,1,strlen(s)-1) val=val*10+s[i]-'0';
        return (-val);
    } else {
        REP(i,strlen(s)) val=val*10+s[i]-'0';
        return (val);
    }
}
void init(void) {
    n=readInt();
    m=readInt();
    REP(i,n) a[i]=readInt();
}
void noAnswer(void) {
    printf("%s\n",noAns);
    exit(0);
}
void fillSeq(vector<int> &v,int l,int r) {
    int minVal=l==0?-INF:v[l-1]+1;
    int maxVal=r==(int)v.size()-1?INF:v[r+1]-1;
    if (r-l+1>1LL+maxVal-minVal) noAnswer();
    if (minVal>=0) {
        FOR(i,l,r) v[i]=minVal++;
    } else if (maxVal<=0) {
        FORD(i,r,l) v[i]=maxVal--;
    } else {
        int pos=0;
        int neg=-1;
        FOR(i,l,r) {
            if (pos>maxVal) v[i]=neg--;
            else if (neg<minVal) v[i]=pos++;
            else if (-neg<pos) v[i]=neg--;
            else v[i]=pos++;
        }
        sort(v.begin()+l,v.begin()+r+1);
    }
}
void process(void) {
    REP(i,m) {
        vector<int> v,fst,lst;
        for (int j=i;j<n;j=j+m) v.push_back(a[j]);
        REP(j,v.size()) if (v[j]>=INF) {
            if (j==0 || v[j-1]<INF) fst.push_back(j);
            if (j==(int)v.size()-1 || v[j+1]<INF) lst.push_back(j);
        }
        REP(j,fst.size()) fillSeq(v,fst[j],lst[j]);
        int id=0;
        for (int j=i;j<n;j=j+m) a[j]=v[id++];
    }
    REP(i,n) if (i+m<n && a[i]>=a[i+m]) noAnswer();
    REP(i,n) printf("%d ",a[i]); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}