#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
long long x;
long long minVal[111],maxVal[111];
int main(void) {
    cin>>x;
    minVal[1]=1;
    maxVal[1]=9;
    FOR(i,2,10) {
        minVal[i]=minVal[i-1]*10;
        maxVal[i]=maxVal[i-1]*10+9;
    }
    long long res=0;
    FOR(i,1,10) if (x>=minVal[i]) {
        if (x<maxVal[i]) res+=i*(x-minVal[i]+1);
        else res+=i*(maxVal[i]-minVal[i]+1);
    }
    cout<<res<<endl;
    return 0;
}