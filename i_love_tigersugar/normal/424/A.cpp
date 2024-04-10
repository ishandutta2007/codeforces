#include<bits/stdc++.h>
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int main(void) {
    string s;
    cin>>s>>s;
    int res=0;
    FORE(it,s) if (*it=='X') res++; else res--;
    res>>=1;
    printf("%d\n",res<0?-res:res);
    FORE(it,s) {
        if (res<0 && *it=='x') *it='X',res++;
        if (res>0 && *it=='X') *it='x',res--;
    }
    cout<<s;
    return 0;
}