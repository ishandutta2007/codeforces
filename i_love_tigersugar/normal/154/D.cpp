#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;
const string win="FIRST";
const string draw="DRAW";
const string lose="SECOND";
int a,b,x1,x2;
inline void answer(const string &s,int x=0) {
    cout<<s<<endl;
    if (s==win) cout<<x;
    exit(0);
}
void process(void) {
    int x1,x2,a,b;
    cin>>x1>>x2>>a>>b;
    if (x1+a<=x2 && x2<=x1+b) answer(win,x2);
    if (a==0 || b==0) answer(draw);
    if (a<0 && 0<b) answer(draw);
    if (x1<x2) {
        if (a<0) answer(draw);
        int t=(x2-x1)%(a+b);
        if (t==0) answer(lose);
        else if (a<=t && t<=b) answer(win,x1+t);
        else answer(draw);
    }
    else {
        if (a>0) answer(draw);
        int t=(x1-x2)%(-a-b);
        if (t==0) answer(lose);
        else if (-b<=t && t<=-a) answer(win,x1-t);
        else answer(draw);
    }
}
int main(void) {
    process();
    return 0;
}