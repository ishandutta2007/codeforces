#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[304];
int seg[304][3];
vector < int > out;

int main(){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;++i) scanf("%d", arr+i);
    for(int i=1;i<=M;++i) scanf("%d %d", seg[i], seg[i]+1);
    int A, B, ans = -1;
    for(int i=1;i<=N;++i) for(int j=1;j<=N;++j){
        int val = arr[i]-arr[j];
        for(int x=1;x<=M;++x) if(!(seg[x][0]<=i&&i<=seg[x][1])&&(seg[x][0]<=j&&j<=seg[x][1])) ++val;
        if(val>ans){
            ans = val; A = i, B = j;
        }
    }
    printf("%d\n", ans);
    for(int x=1;x<=M;++x) if(!(seg[x][0]<=A&&A<=seg[x][1])&&(seg[x][0]<=B&&B<=seg[x][1])) out.push_back(x);
    printf("%d\n", (int)out.size());
    for(int i=0;i<(int)out.size();++i) printf("%d ", out[i]);
    return 0;
}