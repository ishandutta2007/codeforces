#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e6+4;
int N;
vector < int > arr;
int chk[NS];

int main(){
    mt19937 gena(time(NULL));
    scanf("%d", &N);
    uniform_int_distribution <> rng(1, N);
//    for(int i=1;i>0;++i) printf("%lld\n", ((long long)rand()*rand()*rand()*rand()%N+(long long)rand()*rand()*rand()%N+(long long)rand()*rand()%N+(long long)rand()%N)%N);
    int s = 1, e = (int)1e9, mid;
    while(s<e){
        mid = (s+e)/2;
        printf("> %d\n", mid); fflush(stdout);
        int a; scanf("%d", &a);
        if(a) s = mid+1;
        else e = mid;
    }
    for(int i=1;i<=30;++i){
        long long val = rng(gena);
        printf("? %lld\n", val); fflush(stdout);
        int a; scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    function < int(int, int) > gcd = [&](int x, int y){return y==0? x:gcd(y, x%y);};
    int val = -arr[0]+arr[1];
    for(int i=2;i<(int)arr.size();++i) val = gcd(val, arr[i]-arr[i-1]);
    printf("! %d %d\n", s-(N-1)*val, val); fflush(stdout);
    return 0;
}