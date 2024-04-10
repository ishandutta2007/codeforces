#include<cstdio>
#include<iostream>
#include<string>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
string a;
int n,p;
inline bool canfix(int x,int t) {
    if (x>0 && a[x-1]-'a'==t) return (false);
    if (x>1 && a[x-2]-'a'==t) return (false);
    return (true);
}
inline bool canmove(int x) {
    FOR(i,a[x]-'a'+1,p-1) if (canfix(x,i)) return (true);
    return (false);
}
int main(void) {
    scanf("%d%d",&n,&p);
    cin>>a;
    if (n==1) {
        REP(i,p) if (i+'a'>a[0]) {
            printf("%c",i+'a');
            return 0;
        }
        printf("NO");
        return 0;
    }
    if (n==2) {
        REP(i,p) REP(j,p) if (i!=j) {
            string s;
            s.push_back(i+'a');
            s.push_back(j+'a');
            if (s>a) {
                cout<<s;
                return 0;
            }
        }
        printf("NO");
        return 0;
    }
    FORD(i,n-1,0) if (canmove(i)) {
        REP(k,p) if (k>a[i]-'a' && canfix(i,k)) {
            a[i]=k+'a';
            break;
        }
        FOR(j,i+1,n-1) REP(k,p) if (canfix(j,k)) {
            a[j]=k+'a';
            break;
        }
        cout<<a;
        return 0;
    }
    printf("NO");
    return 0;
}