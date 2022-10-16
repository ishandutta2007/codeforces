#include<bits/stdc++.h>
#define MAX   500500
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string vowel="AEIOUY";
char a[MAX];
double sumInv[MAX],sum[MAX];
int n;
void process(void) {
    scanf("%s",a+1);
    n=strlen(a+1);
    FOR(i,1,n) sumInv[i]=sumInv[i-1]+1.0/i;
    sum[1]=sumInv[n];
    FOR(i,1,n-1) sum[i+1]=sum[i]+sumInv[n-i]-sumInv[i];
    double res=0.0;
    FOR(i,1,n) REP(j,vowel.size()) if (a[i]==vowel[j]) res+=sum[i];
    printf("%.7lf\n",res);
}
int main(void) {
    process();
    return 0;
}