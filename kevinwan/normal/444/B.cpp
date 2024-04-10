#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=2e5+10;
ll a[mn],b[mn],n,d,x;
//x is 64-bit variable;
ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
ll c[mn];
struct comp{
    bool operator()(const int &x,const int &y)const{
        return a[x]>a[y];
    }
};
int main(){
    scanf("%lld%lld%lld",&n,&d,&x);
    initAB();
    if(d*d>=n*log2(n)){
        set<int,comp>s;
        for(int i=0;i<n;i++){
            s.insert(i);
            for(int j:s){
                if(b[i-j]){
                    c[i]=a[j];
                    break;
                }
            }
        }
    }
    else{
        vector<int>bb;
        for(int i=0;i<n;i++){
            if(b[i])bb.push_back(i);
            for(int j:bb)c[i]=max(c[i],a[i-j]);
        }
    }
    for(int i=0;i<n;i++)printf("%d\n",c[i]);
}