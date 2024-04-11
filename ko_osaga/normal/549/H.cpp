#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>      // std::setprecision
using namespace std;
typedef long double ld;
typedef pair<ld,ld> pi;

int a,b,c,d;

pi get_range(ld al, ld ah, ld bl, ld bh){
    ld maxv = max(max(al*bl,al*bh),max(ah*bl,ah*bh));
    ld minv = min(min(al*bl,al*bh),min(ah*bl,ah*bh));
    return pi(minv,maxv);
}

bool trial(ld t){
    pi t1 = get_range(a-t,a+t,d-t,d+t);
    pi t2 = get_range(b-t,b+t,c-t,c+t);
    return max(t1.first,t2.first) <= min(t1.second,t2.second);
}

int main(){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    ld s = 0, e = 2e9;
    for (int i=0; i<500; i++) {
        ld m = (s+e)/2;
        if(trial(m)) e = m;
        else s = m;
    }
    
    cout << std::setprecision(11) << s;
}