#include <bits/stdc++.h>

using namespace std;

int N, k;
vector < int > one, zero;
int pos;

int main(){
    scanf("%d %d", &N, &k);
    for(int i=1;i<=N;++i){
        int num; scanf("%d", &num);
        zero.push_back(i);
        if(num) one.push_back(i);
    }
    int ans = 0;
    for(int i=0;i<(int)one.size()&&pos<(int)zero.size();++i){
        int j = i;
        while(j<(int)one.size()&&one[j]-k+1<=zero[pos]) ++j;
        --j;
        ++ans;
        while(pos<(int)zero.size()&&abs(zero[pos]-one[j])<k) ++pos;
        if(j<i){
            puts("-1"); return 0;
        }
        i = j;
    }
    if(pos<(int)zero.size()){
        puts("-1"); return 0;
    }
    printf("%d\n", ans);
    return 0;
}