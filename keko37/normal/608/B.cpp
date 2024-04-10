#include<iostream>

using namespace std;

string a, b;
long long n, m, sol;
int l[200005];

int f (int x, int y) {
    if (x==0) return l[y]; return l[y]-l[x-1];
}

int main () {
    cin >> a >> b;
    n=a.size();
    m=b.size();
    l[0]=a[0]-'0';
    for (int i=1; i<n; i++) l[i]+=a[i]-'0'+l[i-1];
    for (int i=0; i<m; i++) {
        long long left, right;
        if (i<n) left=i; else left=n-1;
        if (m-i-1<n) right=m-i-1; else right=n-1;
        if (b[i]=='0') sol+=f(n-right-1, left); else sol+=left-n+right+2-f(n-right-1, left);
    }
    cout << sol;
    return 0;
}