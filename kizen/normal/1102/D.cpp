#include <bits/stdc++.h>

using namespace std;

const int NS = (int)3e5+4;
int N;
int arr[NS], cnt[3];
int val[3][3];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i) scanf("%1d", arr+i), ++cnt[arr[i]];
    for(int i=0;i<N&&cnt[2]>N/3;++i) if(arr[i]==2){
        if(cnt[0]<N/3) ++val[2][0], ++cnt[0], --cnt[2];
        else ++val[2][1], ++cnt[1], --cnt[2];
    }
    for(int i=0;i<N&&cnt[1]>N/3;++i) if(arr[i]==1){
        if(cnt[0]<N/3) ++val[1][0], ++cnt[0], --cnt[1];
        else ++val[1][2], ++cnt[2], --cnt[1];
    }
    for(int i=0;i<N&&cnt[0]>N/3;++i) if(arr[i]==0){
        if(cnt[1]<N/3) ++val[0][1], ++cnt[1], --cnt[0];
        else ++val[0][2], ++cnt[2], --cnt[0];
    }
    for(int i=0;i<N;++i) if(arr[i]==2){
        if(val[2][0]) arr[i] = 0, --val[2][0];
        else if(val[2][1]) arr[i] = 1, --val[2][1];
    }
    for(int i=0;i<N;++i) if(arr[i]==1){
        if(val[1][0]) arr[i] = 0, --val[1][0];
    }
    for(int i=N-1;i>=0;--i) if(arr[i]==1){
        if(val[1][2]) arr[i] = 2, --val[1][2];
    }
    for(int i=N-1;i>=0;--i) if(arr[i]==0){
        if(val[0][2]) arr[i] = 2, --val[0][2];
        else if(val[0][1]) arr[i] = 1, --val[0][1];
    }
    for(int i=0;i<N;++i) printf("%d", arr[i]);
    return 0;
}