#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
string a,b;
int n;
int cmp(string &a,string &b) {
    REP(i,n) if (a[i]!=b[i]) {
        //printf("AT %d\n",i);
        //cerr<<a<<endl;
        //cerr<<b<<endl;
        if (n-i<=2) return (a[i]=='1'?1:-1);
        if (a[i]=='1') {
            if (b[i+1]=='0' && b[i+2]=='0') return (1);
            if (b[i+1]=='1' && b[i+2]=='1') {
                b[i+1]=b[i+2]='0';
                continue;
            }
            if (b[i+1]=='1' && b[i+2]=='0') {
                if (a[i+2]=='1') return (1);
                else {
                    a[i+2]='1';
                    b[i+1]='0';
                    continue;
                }
            }
            if (b[i+1]=='0' && b[i+2]=='1') {
                if (a[i+1]=='1') return (1);
                else {
                    a[i+1]='1';
                    b[i+2]='0';
                    continue;
                }
            }
        }
        else {
            if (a[i+1]=='0' && a[i+2]=='0') return (-1);
            if (a[i+1]=='1' && a[i+2]=='1') {
                a[i+1]=a[i+2]='0';
                continue;
            }
            if (a[i+1]=='1' && a[i+2]=='0') {
                if (b[i+2]=='1') return (-1);
                else {
                    b[i+2]='1';
                    a[i+1]='0';
                    continue;
                }
            }
            if (a[i+1]=='0' && a[i+2]=='1') {
                if (b[i+1]=='1') return (-1);
                else {
                    b[i+1]='1';
                    a[i+2]='0';
                    continue;
                }
            }
        }
    }
    return (0);
}
int main(void) {
    string s,t;
    cin>>s>>t;
    n=max(s.size(),t.size());
    REP(zz,n-s.size()) a.push_back('0');
    REP(zz,n-t.size()) b.push_back('0');
    a=a+s;
    b=b+t;
    REP(i,n) if (a[i]==b[i]) a[i]=b[i]='0';
    int x=cmp(a,b);
    if (x<0) printf("<");
    if (x==0) printf("=");
    if (x>0) printf(">");
    return 0;
}