#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4;
int N, M;
int arr[NS], cnt[NS], val;

int main(){
    scanf("%d %d", &M, &N);
    for(int i=0;i<N;++i) scanf("%d", arr+i);
    for(int i=0;i<N;++i){
        if(!cnt[arr[i]]){
            ++val;
        }
        ++cnt[arr[i]];
        if(val==M){
            printf("1");
            for(int i=1;i<=M;++i){
                --cnt[i];
                if(!cnt[i]) --val;
            }
        }
        else{
            printf("0");
        }
    }
    return 0;
}