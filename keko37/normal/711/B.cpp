#include<iostream>

using namespace std;

typedef long long llint;

llint n, sum, x, y, sol;
llint l[505] [505];

bool je () {
    for (int i=0; i<n; i++) {
        llint temp=0;
        for (int j=0; j<n; j++) {
            temp+=l[i] [j];
        }
        if (temp!=sum) return 0;
    }
    for (int i=0; i<n; i++) {
        llint temp=0;
        for (int j=0; j<n; j++) {
            temp+=l[j] [i];
        }
        if (temp!=sum) return 0;
    }
    llint d1=0, d2=0;
    for (int i=0; i<n; i++) {
        d1+=l[i] [i];
        d2+=l[i] [n-i-1];
    }
    if (d1!=sum || d2!=sum) return 0;
    return 1;
}

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        bool ima=0;
        for (int j=0; j<n; j++) {
            cin >> l[i] [j];
            if (l[i] [j]==0) {
                ima=1;
                x=i; y=j;
            }
        }
        if (!ima && sum==0) {
            for (int j=0; j<n; j++) {
                sum+=l[i] [j];
            }
        }
    }
    if (n==1) {
        cout << 1;
        return 0;
    }
    llint temp=0;
    for (int i=0; i<n; i++) {
        temp+=l[x] [i];
    }
    if (temp>=sum) {
        cout << -1;
        return 0;
    }
    sol=sum-temp;
    l[x] [y]=sol;
    if (je()) cout << sol; else cout << -1;
    return 0;
}