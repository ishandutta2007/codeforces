#include <bits/stdc++.h>

using namespace std;

const int NS = (int)3e5+4;
int N;
int arr[NS], cnt[15000004];
vector < int > prime;
map < int, int > mp;

int sol(int x, int y){
    return y==0? x:sol(y, x%y);
}

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%d", arr+i);
    int gcd = arr[1];
    for(int i=2;i<=N;++i) gcd = sol(gcd, arr[i]);
    for(int i=2;i<=4000;++i){
        int f = 1;
        for(int j=2;j*j<=i;++j) if(i%j==0){
            f = 0; break;
        }
        if(f) prime.push_back(i);
    }
    for(int i=1;i<=N;++i){
        arr[i]/=gcd;
        for(int j=0;j<(int)prime.size();++j) if(arr[i]%prime[j]==0){
            ++mp[prime[j]];
            while(arr[i]%prime[j]==0) arr[i]/=prime[j];
        }
        ++mp[arr[i]];
    }
    int val = 0;
    for(auto p=mp.begin();p!=mp.end();++p) if(p->first>1) val = max(val, p->second);
    if(val>0) printf("%d", N-val);
    else puts("-1");
    return 0;
}